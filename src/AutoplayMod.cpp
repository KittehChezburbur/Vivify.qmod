#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

static ModInfo modInfo = {.id = "AutoplayMod", .version = "1.0.0"};

// Logger instance
Logger &getLogger() {
    static auto logger = new Logger(modInfo);
    return *logger;
}

// Hooking namespace
using namespace BSML::Parsing;

// Global autoplay enabled flag
bool autoplayEnabled = true;

// Hook for note cutting
MAKE_HOOK_MATCH(NoteCutInfo_ctor, &GlobalNamespace::NoteCutInfo::NoteCutInfo, void,
    GlobalNamespace::NoteCutInfo* self, 
    GlobalNamespace::NoteData* noteData,
    int cutDirection,
    UnityEngine::Vector3 cutPoint,
    UnityEngine::Quaternion cutAngle,
    float cutSpeed) {
    
    if (autoplayEnabled) {
        // Perfect cut: correct direction, good speed, center hit
        cutDirection = noteData->cutDirection;
        cutPoint = UnityEngine::Vector3::zero;
        cutAngle = UnityEngine::Quaternion::identity;
        cutSpeed = 20.0f; // Perfect swing speed
    }
    
    NoteCutInfo_ctor(self, noteData, cutDirection, cutPoint, cutAngle, cutSpeed);
}

// Hook for score submission
MAKE_HOOK_MATCH(ScoreController_HandleNoteWasCut, &GlobalNamespace::ScoreController::HandleNoteWasCut, void,
    GlobalNamespace::ScoreController* self,
    GlobalNamespace::NoteData* noteData,
    GlobalNamespace::NoteCutInfo* noteCutInfo) {
    
    if (autoplayEnabled && noteCutInfo) {
        // Force perfect cut scores
        // MaxCutScore: 115 points
        noteCutInfo->cutDirectionDeviation = 0;
        noteCutInfo->cutMultiplier = 1.0f;
        noteCutInfo->saberSpeed = 20.0f;
    }
    
    ScoreController_HandleNoteWasCut(self, noteData, noteCutInfo);
}

// Hook for bomb avoidance
MAKE_HOOK_MATCH(BombNoteController_Init, &GlobalNamespace::BombNoteController::Init, void,
    GlobalNamespace::BombNoteController* self,
    GlobalNamespace::NoteData* noteData,
    float worldRotation,
    UnityEngine::Vector3 moveStartPos,
    UnityEngine::Vector3 moveEndPos,
    float duration) {
    
    if (autoplayEnabled) {
        // Disable bomb collision by moving them far away
        moveEndPos.z = -100.0f;
        moveStartPos.z = -100.0f;
    }
    
    BombNoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, duration);
}

// Hook for obstacle avoidance
MAKE_HOOK_MATCH(ObstacleController_Init, &GlobalNamespace::ObstacleController::Init, void,
    GlobalNamespace::ObstacleController* self,
    GlobalNamespace::ObstacleData* obstacleData,
    float worldRotation,
    UnityEngine::Vector3 moveStartPos,
    UnityEngine::Vector3 moveEndPos,
    float duration) {
    
    if (autoplayEnabled) {
        // Disable obstacle collision by moving them far away
        moveEndPos.z = -100.0f;
        moveStartPos.z = -100.0f;
    }
    
    ObstacleController_Init(self, obstacleData, worldRotation, moveStartPos, moveEndPos, duration);
}

// Export the mod initialization
extern "C" void setup(ModInfo& info) {
    info = modInfo;
    getLogger().info("Autoplay Mod setup!");
}

extern "C" void load() {
    getLogger().info("Loading Autoplay Mod...");
    
    // Install all hooks
    INSTALL_HOOK(getLogger(), NoteCutInfo_ctor);
    INSTALL_HOOK(getLogger(), ScoreController_HandleNoteWasCut);
    INSTALL_HOOK(getLogger(), BombNoteController_Init);
    INSTALL_HOOK(getLogger(), ObstacleController_Init);
    
    getLogger().info("Autoplay Mod loaded!");
}
