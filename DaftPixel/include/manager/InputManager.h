#pragma once
#include <iostream>
#include <unordered_map>
#include <SDL.h>
#include "manager/InputManager.h"
#include "manager/KeyBindingManager.h"
#include "model/Action.h"

class InputManager {
public:
	InputManager(KeyBindingManager& keyBindingManager);

	void handleEvent(const SDL_Event& event);

	bool isActionTriggered(Action action) const;
	bool isActionPressed(Action action) const;
	bool isActionReleased(Action action) const;

	void markActionAsHandled(Action action);

private:
	KeyBindingManager& m_keyBindingManager;

	std::unordered_map<Action, bool> m_actionStates;
	std::unordered_map<Action, bool> m_lastActionStates;
};