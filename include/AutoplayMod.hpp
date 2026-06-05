#pragma once

#include "modloader/shared/modloader.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/ScoreController.hpp"
#include "GlobalNamespace/ComboController.hpp"

class AutoplayMod {
public:
    static void Init();
    static void Enable();
    static void Disable();
    static bool IsEnabled();

private:
    static bool enabled;
    static void OnNoteControllerCut(GlobalNamespace::NoteController* noteController, const ByRef<GlobalNamespace::NoteCutInfo> noteCutInfo);
    static void OnScoreControllerUpdate(GlobalNamespace::ScoreController* scoreController);
    static void OnComboControllerUpdate(GlobalNamespace::ComboController* comboController);
};
