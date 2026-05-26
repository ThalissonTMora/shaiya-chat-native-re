// Export decompiled C from manifest: category<TAB>symbol<TAB>0xVA
// Manifest line 1: # binary=ps_game.exe md5=... imagebase=0x00400000
// Usage: ExportDecompileByAddress.java <outputRoot> <manifestPath>
// @category Shaiya

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class ExportDecompileByAddress extends GhidraScript {

    private static class Entry {
        final String category;
        final String symbol;
        final String addrRaw;

        Entry(String category, String symbol, String addrRaw) {
            this.category = category;
            this.symbol = symbol;
            this.addrRaw = addrRaw;
        }
    }

    private static class Meta {
        String binary = "unknown.exe";
        String md5 = "unknown";
        String imageBase = "0x00400000";
        String regenScript = "tools/ghidra/decompile.sh";
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            printerr("Usage: ExportDecompileByAddress.java <outputRoot> <manifestPath>");
            return;
        }

        File outRoot = new File(args[0]);
        File manifestFile = new File(args[1]);
        Meta meta = new Meta();
        List<Entry> entries = loadManifest(manifestFile, meta);
        if (entries.isEmpty()) {
            printerr("Manifest empty: " + manifestFile.getAbsolutePath());
            return;
        }

        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        int ok = 0;
        int fail = 0;

        for (Entry e : entries) {
            String raw = e.addrRaw.trim();
            if (raw.startsWith("0x") || raw.startsWith("0X")) {
                raw = raw.substring(2);
            }
            Address addr = toAddr(raw);
            Function func = getFunctionAt(addr);
            boolean midFunction = false;
            if (func == null) {
                func = getFunctionContaining(addr);
                midFunction = func != null;
            }
            if (func == null) {
                createFunction(addr, null);
                func = getFunctionAt(addr);
            }
            if (func == null) {
                printerr("No function at " + e.addrRaw + " (" + e.symbol + ")");
                fail++;
                continue;
            }

            File catDir = new File(outRoot, e.category);
            if (!catDir.exists() && !catDir.mkdirs()) {
                printerr("Cannot create " + catDir.getAbsolutePath());
                fail++;
                continue;
            }

            String vaTag = addr.toString().replace(":", "").toLowerCase();
            File outFile = new File(catDir, e.symbol + "_" + vaTag + ".c");

            DecompileResults results = decomp.decompileFunction(func, 180, monitor);
            try (PrintWriter pw = new PrintWriter(new FileWriter(outFile))) {
                pw.println("/*");
                pw.println(" * " + meta.binary + " — " + e.symbol);
                pw.println(" * VA solicitado: " + e.addrRaw);
                pw.println(" * Entry Ghidra:  " + func.getEntryPoint());
                pw.println(" * Ghidra name:   " + func.getName());
                if (midFunction) {
                    pw.println(" * NOTA: VA dentro da função (landmark/hook), não é entry point.");
                }
                pw.println(" * MD5: " + meta.md5);
                pw.println(" * ImageBase: " + meta.imageBase);
                pw.println(" * Categoria: " + e.category);
                pw.println(" * Regenerar: " + meta.regenScript);
                pw.println(" */");
                pw.println();
                if (results.decompileCompleted()) {
                    pw.print(results.getDecompiledFunction().getC());
                    ok++;
                } else {
                    pw.println("/* DECOMPILE FAILED: " + results.getErrorMessage() + " */");
                    fail++;
                }
            }
            println("Wrote " + outFile.getAbsolutePath());
        }

        decomp.dispose();
        println("Export: " + ok + " ok, " + fail + " fail, " + entries.size() + " total");
    }

    private static List<Entry> loadManifest(File manifest, Meta meta) throws Exception {
        List<Entry> list = new ArrayList<>();
        Pattern pBin = Pattern.compile("binary=([^\\s]+)", Pattern.CASE_INSENSITIVE);
        Pattern pMd5 = Pattern.compile("md5=([a-fA-F0-9]+)", Pattern.CASE_INSENSITIVE);
        Pattern pIb = Pattern.compile("imagebase=(0x[0-9a-fA-F]+)", Pattern.CASE_INSENSITIVE);
        Pattern pRegen = Pattern.compile("regen=([^\\s]+)", Pattern.CASE_INSENSITIVE);

        try (BufferedReader br = new BufferedReader(new FileReader(manifest))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    continue;
                }
                if (line.startsWith("#")) {
                    Matcher m;
                    m = pBin.matcher(line);
                    if (m.find()) meta.binary = m.group(1);
                    m = pMd5.matcher(line);
                    if (m.find()) meta.md5 = m.group(1).toLowerCase();
                    m = pIb.matcher(line);
                    if (m.find()) meta.imageBase = m.group(1);
                    m = pRegen.matcher(line);
                    if (m.find()) meta.regenScript = m.group(1);
                    continue;
                }
                String[] parts = line.split("\t");
                if (parts.length < 3) {
                    continue;
                }
                list.add(new Entry(parts[0].trim(), parts[1].trim(), parts[2].trim()));
            }
        }
        return list;
    }
}
