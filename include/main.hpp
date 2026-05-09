#pragma once

#include "modloader/modloader.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"

namespace vivify {
    constexpr const char* VERSION = "1.0.0";
    
    extern ModInfo modInfo;
    
    void Init();
    void ApplyVisualEffects();
    Paper::Logger& GetLogger();
}
