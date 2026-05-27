#include "../include/AutoplayMod.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/ScoreController.hpp"
#include "GlobalNamespace/ComboController.hpp"
#include "GlobalNamespace/NoteCutInfo.hpp"

bool AutoplayMod::enabled = true;

void AutoplayMod::Init() {
    // Hook into NoteController to auto-cut notes
    INSTALL_HOOK(
        Modloader, "NoteController_CutNote",
        GlobalNamespace::NoteController::Cut,
        &AutoplayMod::OnNoteControllerCut
    );
    
    // Hook into ScoreController to inject perfect scores
    INSTALL_HOOK(
        Modloader, "ScoreController_Update",
        GlobalNamespace::ScoreController::Update,
        &AutoplayMod::OnScoreControllerUpdate
    );
    
    // Hook into ComboController to prevent breaks
    INSTALL_HOOK(
        Modloader, "ComboController_Update",
        GlobalNamespace::ComboController::Update,
        &AutoplayMod::OnComboControllerUpdate
    );
    
    getLogger().info("Autoplay Perfect Score mod initialized!");
}

void AutoplayMod::Enable() {
    enabled = true;
    getLogger().info("Autoplay enabled - Perfect scores incoming!");
}

void AutoplayMod::Disable() {
    enabled = false;
    getLogger().info("Autoplay disabled");
}

bool AutoplayMod::IsEnabled() {
    return enabled;
}

void AutoplayMod::OnNoteControllerCut(GlobalNamespace::NoteController* noteController, const ByRef<GlobalNamespace::NoteCutInfo> noteCutInfo) {
    if (!enabled) return;
    
    // Auto-perfect cut all notes
    auto& cutInfo = const_cast<GlobalNamespace::NoteCutInfo&>(noteCutInfo.get());
    cutInfo.saberTypeOk = true;
    cutInfo.speedOK = true;
    cutInfo.directionOK = true;
    cutInfo.saberTypeOk = true;
    cutInfo.wasCutTooSoon = false;
    cutInfo.distanceToCutLine = 0.0f;
}

void AutoplayMod::OnScoreControllerUpdate(GlobalNamespace::ScoreController* scoreController) {
    if (!enabled || !scoreController) return;
    
    // Inject maximum score (115 per perfect note)
    scoreController->maxCombo = INT32_MAX;
}

void AutoplayMod::OnComboControllerUpdate(GlobalNamespace::ComboController* comboController) {
    if (!enabled || !comboController) return;
    
    // Prevent any combo breaks
    comboController->combo = INT32_MAX;
}
