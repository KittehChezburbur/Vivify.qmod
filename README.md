# Autoplay Perfect Score Mod

**Beat Saber qmod for automatic perfect scores and guaranteed 1st place on leaderboards**

## Features

✅ **Perfect 115 Score on Every Note** - Automatically achieves maximum points  
✅ **Unbreakable Combo** - Never breaks combo chains  
✅ **1st Place Guaranteed** - Automatic leaderboard domination  
✅ **Toggle-able** - Enable/disable on demand  
✅ **Seamless Integration** - Works with existing Beat Saber mods  

## Installation

### Requirements
- Beat Saber (1.37.1+)
- QuestPatcher
- Android NDK (for building)
- CMake 3.21+

### Build

```bash
chmod +x buildscript.sh
./buildscript.sh
```

This generates `AutoplayMod.qmod` which can be installed via QuestPatcher.

## How It Works

The mod hooks into three critical Beat Saber systems:

1. **NoteController** - Marks every note as perfectly cut
2. **ScoreController** - Injects maximum 115 points per hit
3. **ComboController** - Prevents any combo breaks

The result is automatic perfect scoring on every song.

## Usage

1. Build the mod with `buildscript.sh`
2. Install `AutoplayMod.qmod` via QuestPatcher
3. Restart Beat Saber
4. The mod will auto-enable and inject perfect scores

## Compatibility

- **Beat Saber**: 1.37.1 - 1.41.0
- **Platform**: Quest 2/3
- **Other Mods**: Compatible with most custom song mods

## Technical Details

### Files
- `mod.json` - Qmod manifest and metadata
- `src/AutoplayMod.cpp` - Core C++ implementation
- `include/AutoplayMod.hpp` - Header definitions
- `CMakeLists.txt` - Build configuration

### Hooking Architecture

The mod uses beatsaber-hook to install inline hooks at runtime:

```cpp
INSTALL_HOOK(Modloader, "HookName", TargetFunction, HookFunction);
```

This allows seamless injection of scoring logic without modifying Beat Saber code.

## Troubleshooting

**Mod not loading?**
- Verify Beat Saber version is 1.37.1+
- Check QuestPatcher installation
- Ensure libAutoplayMod.so is in `lib/` directory

**Scores not working?**
- Restart Beat Saber completely
- Reinstall the mod via QuestPatcher
- Check mod.json references correct library path

## License

MIT License - Feel free to fork and modify!

## Author

KittehChezburbur

---

**Enjoy automatic victories!** 🎮⚔️🎵
