#include "main.hpp"
#include "vivify.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"

using namespace vivify;

ModInfo modInfo{"vivify", VERSION};
Paper::Logger& vivify::GetLogger() {
    static auto logger = Paper::Logger::fmtLoggerFactory("Vivify");
    return logger;
}

extern "C" void setup(ModInfo* info) {
    modInfo = *info;
    GetLogger().info("Vivify mod setup initialized!");
}

extern "C" void load() {
    GetLogger().info("Loading Vivify mod - Universal map support...");
    vivify::Init();
    GetLogger().info("Vivify mod loaded successfully on ALL maps!");
}

void vivify::Init() {
    GetLogger().info("Initializing Vivify visual effects for universal map support...");
    VivifyManager::GetInstance().Initialize();
    VivifyManager::GetInstance().ApplyEffects();
}
