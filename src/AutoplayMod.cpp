// Autoplay Mod - Beat Saber Perfect Score Mod
// Minimal implementation without external dependencies

extern "C" {
    // ModInfo structure
    struct ModInfo {
        const char* id;
        const char* version;
    };
    
    // Setup function - called when mod is loaded
    void setup(ModInfo& info) {
        info.id = "AutoplayMod";
        info.version = "1.0.0";
    }
    
    // Load function - main entry point
    void load() {
        // Autoplay mod loaded successfully
        // Note: Full hooking would require beatsaber-hook headers
        // For now, this is a placeholder that will compile
    }
}
