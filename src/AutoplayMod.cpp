#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

// Logger
static auto logger = new Logger(ModInfo{"AutoplayMod", "1.0.0"});

bool autoplayEnabled = true;

// Hook for perfect note cutting
MAKE_HOOK_MATCH(NoteCutInfo_ctor, &GlobalNamespace::NoteCutInfo::NoteCutInfo, void,
    GlobalNamespace::NoteCutInfo* self, 
    GlobalNamespace::NoteData* noteData,
    int cutDirection,
    UnityEngine::Vector3 cutPoint,
    UnityEngine::Quaternion cutAngle,
    float cutSpeed) {
    
    if (autoplayEnabled && noteData) {
        cutDirection = noteData->cutDirection;
        cutPoint = UnityEngine::Vector3::zero;
        cutAngle = UnityEngine::Quaternion::identity;
        cutSpeed = 20.0f;
    }
    
    NoteCutInfo_ctor(self, noteData, cutDirection, cutPoint, cutAngle, cutSpeed);
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
        moveEndPos.z = -100.0f;
        moveStartPos.z = -100.0f;
    }
    
    ObstacleController_Init(self, obstacleData, worldRotation, moveStartPos, moveEndPos, duration);
}

extern "C" void setup(ModInfo& info) {
    info = ModInfo{"AutoplayMod", "1.0.0"};
}

extern "C" void load() {
    logger->info("Loading Autoplay Mod...");
    
    INSTALL_HOOK(*logger, NoteCutInfo_ctor);
    INSTALL_HOOK(*logger, BombNoteController_Init);
    INSTALL_HOOK(*logger, ObstacleController_Init);
    
    logger->info("Autoplay Mod loaded!");
}
