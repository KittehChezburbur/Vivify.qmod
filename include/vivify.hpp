#pragma once

namespace vivify {
    class VivifyManager {
    public:
        static VivifyManager& GetInstance();
        
        void Initialize();
        void ApplyEffects();
        void UpdateEffects();
        void Dispose();
        
        bool IsEnabled() const;
        void SetEnabled(bool enabled);
        
    private:
        VivifyManager();
        ~VivifyManager();
        
        void ApplyLightingEnhancement();
        void ApplyPostProcessing();
        void BoostParticleEffects();
        
        bool enabled = true;
    };
}
