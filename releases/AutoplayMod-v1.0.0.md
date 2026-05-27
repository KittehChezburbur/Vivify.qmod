# Autoplay Perfect Score v1.0.0

**Beat Saber qmod for automatic perfect scores and guaranteed 1st place on leaderboards**

## Release Information

- **Version:** 1.0.0
- **Beat Saber Compatibility:** 1.40.8 (latest moddable)
- **Platform:** Meta Quest 2/3/Pro
- **Release Date:** May 27, 2026
- **Commit:** [b59873ae](https://github.com/KittehChezburbur/Vivify.qmod/commit/b59873ae41499b6c918b27886b7098d608173a26)

## Features

✅ **Perfect 115 Score on Every Note** - Automatically achieves maximum points  
✅ **Unbreakable Combo** - Never breaks combo chains  
✅ **1st Place Guaranteed** - Automatic leaderboard domination  
✅ **Toggle-able** - Enable/disable on demand  
✅ **Seamless Integration** - Works with existing Beat Saber mods  

## Installation

1. Download `AutoplayMod.qmod` from this release
2. Open QuestPatcher on your PC
3. Plug in your Meta Quest device
4. Install the mod via QuestPatcher
5. Restart Beat Saber

## How It Works

The mod hooks into three critical Beat Saber systems:

1. **NoteController** - Marks every note as perfectly cut
2. **ScoreController** - Injects maximum 115 points per hit
3. **ComboController** - Prevents any combo breaks

Result: Automatic perfect scoring on every song!

## Build Instructions

```bash
git clone https://github.com/KittehChezburbur/Vivify.qmod.git
cd Vivify.qmod
git checkout autoplay-feature
chmod +x buildscript.sh
./buildscript.sh
```

This generates `AutoplayMod.qmod` ready for installation.

## Files Included

- `mod.json` - Qmod manifest
- `lib/libAutoplayMod.so` - Compiled C++ library
- `src/AutoplayMod.cpp` - Source implementation
- `include/AutoplayMod.hpp` - Header definitions

## Known Issues

None at this time. Report issues on the repository.

## License

MIT License - Feel free to fork and modify!

## Author

KittehChezburbur

---

**Enjoy automatic victories!** 🎮⚔️🎵
