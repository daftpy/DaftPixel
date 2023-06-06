#include "manager/InputManager.h"

InputManager::InputManager(KeyBindingManager& keyBindingManager) : m_keyBindingManager(keyBindingManager)
{
	// Initialize action states
	m_actionStates[Action::IncreaseScaleFactor] = false;
	m_actionStates[Action::DecreaseScaleFactor] = false;
    m_actionStates[Action::None] = false;

	// Initialize last action states
	m_lastActionStates[Action::IncreaseScaleFactor] = false;
	m_lastActionStates[Action::DecreaseScaleFactor] = false;
    m_lastActionStates[Action::None] = false;
}

void InputManager::handleEvent(const SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYUP:
    {
        std::cout << "Key up: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
        Action action;
        if (m_keyBindingManager.getAction(event.key.keysym, action)) {
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = false; // The key was released, so the action is not currently active
        }
        break;
    }
    case SDL_KEYDOWN:
    {
        // Ignore repeated KEYDOWN events
        if (event.key.repeat != 0)
            break;

        std::cout << "Key down: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
        Action action;
        if (m_keyBindingManager.getAction(event.key.keysym, action)) {
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = true; // The key was pressed, so the action is currently active
        }
        break;
    }
    }
}


bool InputManager::isActionTriggered(Action action) const {
	return m_actionStates.at(action) && !m_lastActionStates.at(action);
}

bool InputManager::isActionPressed(Action action) const {
	// Returns true if the action is currently active (i.e., the key is currently pressed)
	return m_actionStates.at(action);
}

bool InputManager::isActionReleased(Action action) const {
	// Returns true if the action is currently not active (i.e., the key is not currently pressed), 
	// but was active in the last frame (i.e., the key was just released)
	return !m_actionStates.at(action) && m_lastActionStates.at(action);
}

void InputManager::markActionAsHandled(Action action) {
    m_lastActionStates.at(action) = false;
    m_actionStates.at(action) = false;
}
