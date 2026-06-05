#include "../include/main.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/ScoreController.hpp"
#include "GlobalNamespace/ComboController.hpp"
#include "GlobalNamespace/NoteCutInfo.hpp"

using namespace vivify;

bool autoplayEnabled = true;

// Hook for note cutting - make all cuts perfect
MAKE_HOOK_MATCH(NoteCutInfo_ctor, &GlobalNamespace::NoteCutInfo::NoteCutInfo, void,
    GlobalNamespace::NoteCutInfo* self, 
    GlobalNamespace::NoteData* noteData,
    int cutDirection,
    UnityEngine::Vector3 cutPoint,
    UnityEngine::Quaternion cutAngle,
    float cutSpeed) {
    
    if (autoplayEnabled && noteData) {
        // Perfect cut: correct direction, good speed, center hit
        cutDirection = noteData->cutDirection;
        cutPoint = UnityEngine::Vector3::zero;
        cutAngle = UnityEngine::Quaternion::identity;
        cutSpeed = 20.0f;
    }
    
    NoteCutInfo_ctor(self, noteData, cutDirection, cutPoint, cutAngle, cutSpeed);
}

// Hook for bomb avoidance - disable bomb collisions
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

// Hook for obstacle avoidance - disable obstacle collisions
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
    info = {"AutoplayMod", "1.0.0", 0};
    GetLogger().info("Autoplay Mod setup!");
}

extern "C" void load() {
    GetLogger().info("Loading Autoplay Mod...");
    
    INSTALL_HOOK(GetLogger(), NoteCutInfo_ctor);
    INSTALL_HOOK(GetLogger(), BombNoteController_Init);
    INSTALL_HOOK(GetLogger(), ObstacleController_Init);
    
    GetLogger().info("Autoplay Mod loaded successfully!");
}
