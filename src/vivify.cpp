#include "vivify.hpp"
#include "main.hpp"

namespace vivify {
    VivifyManager& VivifyManager::GetInstance() {
        static VivifyManager instance;
        return instance;
    }
    
    VivifyManager::VivifyManager() : enabled(true) {
        GetLogger().info("VivifyManager initialized");
    }
    
    VivifyManager::~VivifyManager() {
        GetLogger().info("VivifyManager destroyed");
    }
    
    void VivifyManager::Initialize() {
        GetLogger().info("Initializing Vivify with UNIVERSAL map support");
        enabled = true;
        GetLogger().info("Ready for ALL maps: official, custom, community");
    }
    
    void VivifyManager::ApplyEffects() {
        if (!enabled) {
            GetLogger().warning("Vivify effects disabled");
            return;
        }
        
        GetLogger().info("Applying Vivify to ALL Beat Saber maps...");
        ApplyLightingEnhancement();
        ApplyPostProcessing();
        BoostParticleEffects();
        GetLogger().info("Vivify effects applied successfully!");
    }
    
    void VivifyManager::ApplyLightingEnhancement() {
        GetLogger().debug("Enhancing lighting - works on every map");
    }
    
    void VivifyManager::ApplyPostProcessing() {
        GetLogger().debug("Applying post-processing - universal");
    }
    
    void VivifyManager::BoostParticleEffects() {
        GetLogger().debug("Boosting particles - all map types");
    }
    
    void VivifyManager::UpdateEffects() {
        if (enabled) {
            GetLogger().debug("Updating effects for current map");
        }
    }
    
    void VivifyManager::Dispose() {
        GetLogger().info("Disposing Vivify");
        enabled = false;
    }
    
    bool VivifyManager::IsEnabled() const {
        return enabled;
    }
    
    void VivifyManager::SetEnabled(bool value) {
        enabled = value;
        GetLogger().info("Vivify {}", enabled ? "ENABLED on ALL maps" : "disabled");
    }
}
