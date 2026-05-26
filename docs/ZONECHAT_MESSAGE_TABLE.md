# Zone chat message table — `ps_game.exe` / `Game.exe`

Maps **script / wire `message_id`** → **NUL-terminated display text** for Pattern **D** (`0x1109`) and Pattern **E** (`0x110A`).

| Binary | MD5 | ImageBase |
|--------|-----|-----------|
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` | `0x00400000` |
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` | `0x00400000` |

**Do not invent strings** — text lives in runtime data loaded from `data/cn_string.DB` (not embedded in the PE).

---

## 1. Summary

| Item | Value | Tag |
|------|-------|-----|
| Container | MSVC `std::map<u32, std::string>` (RB-tree) | **CONFIRMED** |
| Server map header | `DAT_00587c5c` (BSS) | **CONFIRMED** |
| Server element count | `DAT_00587c60` | **CONFIRMED** |
| Server allocator stub | `DAT_00587c44` | **CONFIRMED** |
| Lookup (server) | `ZoneChat_MessageResolver` @ `0x004C6970` | **CONFIRMED** |
| BST lower_bound (server) | `ZoneChat_MessageLookup` / inner @ `0x004C7250` | **CONFIRMED** |
| Load source file | `data/cn_string.DB` | **CONFIRMED** |
| Loader | `FUN_00408C70` | **CONFIRMED** |
| Client lookup | `GetMsg` → `FUN_004163C0` @ `0x004163C0` | **CONFIRMED** |
| Script index bias | `message_id \| 0xC00` before `0x110A` send | **CONFIRMED** |

---

## 2. RB-tree node layout (map entry)

Evidence: BST walk @ `0x004C7250`, insert @ `0x0040DE10` / node alloc @ `0x0040E1C0`, resolver @ `0x004C69C4`.

```c
// CONFIRMED — ps_game.exe @ 0x004C7250 / 0x0040E1C0 (MSVC std::_Tree node)
struct ZoneChat_MapNode {
    ZoneChat_MapNode* _Left;    // +0x00
    ZoneChat_MapNode* _Parent;  // +0x04
    ZoneChat_MapNode* _Right;   // +0x08
    u32               message_id; // +0x0C  (key; BST compare @ 0x004C7266)
    std::string       text;     // +0x10  (MSVC basic_string object)
    u8                _Color;   // +0x14  (RB red/black)
    u8                _Isnil;   // +0x15  (1 = sentinel)
    // node heap size: 24 bytes when allocated via FUN_004088B0 (ecx=1 → 24*ecx)
};
```

| Field | Offset | Size | Notes |
|-------|--------|------|-------|
| `_Left` | `0x00` | 4 | |
| `_Parent` | `0x04` | 4 | |
| `_Right` | `0x08` | 4 | |
| `message_id` | `0x0C` | 4 | `u32le`; script `0xC00` bias stored **after** OR in wrapper |
| `text` | `0x10` | var | MSVC `std::string`; **NUL-terminated payload** read at `string+0x04` in 1109 builder |
| `_Color` | `0x14` | 1 | RB-tree |
| `_Isnil` | `0x15` | 1 | `0` = data node; sentinel @ map header has `_Isnil=1` |

**Logical entry size (emulator):** not a fixed array — use `map<u32,string>`. Load buffer uses **`0x84`** bytes per parsed record (`u32 id` + `char text[0x80]`) @ `0x00408D1B`.

---

## 3. Runtime globals (server)

| Symbol | VA | Section | Role |
|--------|-----|---------|------|
| `DAT_00587c44` | `0x00587c44` | BSS (uninitialized) | Map allocator / `_Getal` stub |
| `DAT_00587c5c` | `0x00587c5c` | BSS | Map object → pointer to **sentinel node** |
| `DAT_00587c60` | `0x00587c60` | BSS | `map.size()` mirror; inc @ `0x0040DE9E`, dec @ `0x004085A6` |

**Init (CONFIRMED)** @ `0x00407E40`:

1. Alloc stub → `DAT_00587c44`
2. Alloc sentinel node (`FUN_004085E0`, 24 B) → `DAT_00587c5c`
3. Sentinel self-links @ `+0x00/+0x04/+0x08`; `_Isnil=1` @ `+0x15`
4. `DAT_00587c60 = 0`

**Not a static `.rdata` table** — the PE has empty BSS at these VAs; entries appear only after `FUN_00408C70` runs.

---

## 4. Resolver call path

### 4.1 `ZoneChat_MessageResolver` @ `0x004C6970`

**Calling convention (CONFIRMED):** `__stdcall`, 1× `u32` arg, `ret 4`.

```
push message_id          // e.g. Chat_PacketBuilder_1109 @ 0x004C6AA0
call 0x004C6970
// eax = pointer to std::string object (node+0x10), or 0 if not found
```

**Algorithm (CONFIRMED asm):**

1. `ZoneChat_MessageLookup` @ `0x004C71D0` → BST `lower_bound(message_id)` via `0x004C7250`
2. If iterator == sentinel (`node == DAT_00587c5c`) → return `0`
3. Walk `_Parent` until `_Parent == map.end()` equivalent (`cmp ebx, [esi+0x18]` — parent sentinel marker)
4. Return `[node+0x10]` (`std::string` object)

**1109 text extraction (CONFIRMED)** @ `Chat_PacketBuilder_1109_A` `0x004C6AA8`:

```c
void* str_obj = ZoneChat_MessageResolver(message_id);
if (!str_obj) return;
char* text = (char*)str_obj + 4;   // NUL-terminated; len 1..0x7F enforced
```

### 4.2 BST walk @ `0x004C7250`

```
root = [DAT_00587c5c + 4]           // _Parent of header
while (!node->_Isnil):
    if node->message_id >= key: best = node; node = node->_Left
    else:                         node = node->_Right
return {header, best}
```

Same pattern on client @ `Game.exe` `0x004163C0` (map root `DAT_007c3b4c`).

---

## 5. Data source — `data/cn_string.DB`

**Loader:** `FUN_00408C70` @ `0x00408C70`

| Step | API / detail | VA |
|------|----------------|-----|
| Open | `fopen("data/cn_string.DB", "rt")` | strings @ `0x0056F410`, `0x0056F40C` |
| Read id | `fscanf(fp, "%d\n", &message_id)` | format @ `0x0056F424` |
| Read text | `fgets(buf, 0x400, fp)` | skip empty lines |
| Temp pair | `malloc(0x84)` → `[+0]=id`, `[+4..]=text` (max 0x80, zero-filled) | `0x00408D1B` |
| Insert | `FUN_0040DCE0` → `std::map` emplace | `0x00408D74` |

**File format (CONFIRMED from loader loop):**

```text
<message_id_decimal>
<text line, single fgets row, may contain GetMsg tags like <p>...</>
<message_id_decimal>
<text line>
...
```

**Callers (CONFIRMED xrefs to `0x00408C00` / `0x00408C70`):** `0x00409EE0`, `0x0040D45E`, `0x00474590`, `0x004818DC`, `0x00481977`, `0x00481A64`, `0x00553780` (server init chain).

---

## 6. Script / wire ID encoding

| Path | ID on wire / in map | Evidence |
|------|---------------------|----------|
| `0x1109` builders | Script operand **as-is** (no `0xC00` OR in builder) | `Chat_PacketBuilder_1109_*` calls resolver with raw script arg @ `0x004C6AA0` |
| `0x110A` builder | **`u16le`** on wire; wrapper **`or eax, 0xC00`** @ `0x004CB402` before builder | **CONFIRMED** |
| Client `0x110A` recv | `GetMsg(u16 message_id)` @ `0x00420DB0` | same map on client |

**INFERRED:** Script table indices are **small integers** (e.g. `1`, `2`, …); wire/client IDs add **`0xC00` (3072)** for union/zone script messages. Map keys in `cn_string.DB` likely use the **full** id (post-bias values) — **validate** against a real `cn_string.DB` dump.

---

## 7. Sample entries

**No sample rows extracted from this repo** — `data/cn_string.DB` is not vendored and the map BSS is empty in the static PE.

| Claim | Tag |
|-------|-----|
| First 20 `(message_id → text)` pairs | **BLOCKED** — needs runtime file or live server `data/` tree |
| Example id `3072` (`0xC00`) exists | **HYPOTHESIS** — bias constant only; no string without DB |

**Reproduction (when `cn_string.DB` is available):**

```bash
# Path relative to ps_game working directory (CONFIRMED string @ 0x0056F410)
head -n 40 /path/to/server/data/cn_string.DB

# Optional: breakpoint after insert
# ps_game.exe: bp 0x00408D74, log [edi], [edi+4]  (id + text ptr)
```

---

## 8. Emulator guidance

1. **Load** `data/cn_string.DB` at startup (same format as §5).
2. **Expose** `resolve(message_id) -> Option<&str>` backed by `HashMap<u32, String>` or `BTreeMap`.
3. **Pattern D (`0x1109`):** resolve script id → UTF-8/legacy bytes → enforce **`1 ≤ len ≤ 0x7F`** (builder @ `0x004C6ACE`).
4. **Pattern E (`0x110A`):** accept **`u16 message_id` on wire**; client calls `GetMsg(id)` — server script path ORs **`0xC00`** before send; ensure map keys align with client expectations.
5. **GetMsg tags:** client expands `<p>`, `<t>`, `<s>`, etc. (@ `Game.exe` `0x00420DB0`) — server stores **raw** strings from DB; tag expansion is **client-side only**.

---

## 9. Artifacts

| Path | Contents |
|------|----------|
| `psgame-chat-native/lookup/ZoneChat_MessageResolver_004c6970.c` | Ghidra export |
| `psgame-chat-native/lookup/ZoneChat_MessageLookup_004c71d0.c` | Ghidra export |
| `game-chat-native/util/GetMsg_00420db0.c` | Client resolution + tag expansion |
| `psgame-chat-native/send/Chat_PacketBuilder_1109_A_004c6a80.c` | Resolver consumer (text path) |

**Reproduce disassembly:**

```bash
objdump -d -M intel --start-address=0x4c6970 --stop-address=0x4c7290 bin/ps_game.exe
objdump -d -M intel --start-address=0x408c70 --stop-address=0x408da0 bin/ps_game.exe
strings -a bin/ps_game.exe | grep cn_string
```

---

## 10. Assumptions & limitations

- Map implementation matches **MSVC 7.1 / 2003-era** `std::map` (RB-tree, node layout above).
- **`cn_string.DB` encoding** (UTF-8 vs codepage) not verified — treat as **8-bit extended ASCII** until captured.
- Long strings may heap-allocate inside `std::string`; loader caps read buffer at **0x80** bytes per line.
- Version drift: paths/VAs tied to MD5 `91b212af…`; re-base after binary swap.

---

## 11. Next validation steps

1. Obtain `data/cn_string.DB` from a stock server tree → dump first 20 id/text pairs into this doc.
2. Break @ `0x004C6970` on live NPC script chat → log `message_id` + resolved C string.
3. Correlate script operand `N` with DB id `N` vs `N+0xC00` for one known NPC line.
4. Capture S→C `0x110A` frame + client `GetMsg` output to confirm id ↔ text end-to-end.
