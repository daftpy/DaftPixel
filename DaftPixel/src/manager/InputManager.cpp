#include "manager/InputManager.h"

// Constructor for the InputManager class.
// Takes in a reference to a BindingManager object and initializes the action states.
InputManager::InputManager(BindingManager& bindingManager) : m_bindingManager(bindingManager)
{
    // Initialize action states
    // We start with all actions as inactive (false)
    m_actionStates[Action::IncreaseScaleFactor] = false;
    m_actionStates[Action::DecreaseScaleFactor] = false;
    m_actionStates[Action::None] = false;

    // Initialize last action states
    // We start with all actions as inactive (false)
    m_lastActionStates[Action::IncreaseScaleFactor] = false;
    m_lastActionStates[Action::DecreaseScaleFactor] = false;
    m_lastActionStates[Action::None] = false;
}

// Method that handles an SDL_Event.
// Updates the action states based on the event.
void InputManager::handleEvent(const SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYUP:
    {
        Action action;
        // Get the action corresponding to the key event.
        // If there is a valid action, update the action states.
        if (m_bindingManager.getAction(event.key.keysym, action)) {
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = false; // The key was released, so the action is not currently active
        }
        break;
    }
    case SDL_KEYDOWN:
    {
        Action action;
        // Get the action corresponding to the key event.
        // If there is a valid action, update the action states.
        if (m_bindingManager.getAction(event.key.keysym, action)) {
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = true; // The key was pressed, so the action is currently active
        }
        break;
    }
    }
}

// Method to check if an action was triggered.
// Returns true if the action is currently active and was not active in the last frame.
bool InputManager::isActionTriggered(Action action) const {
    return m_actionStates.at(action) && !m_lastActionStates.at(action);
}

// Method to check if an action is currently being pressed.
// Returns true if the action is currently active.
bool InputManager::isActionPressed(Action action) const {
    return m_actionStates.at(action);
}

// Method to check if an action was released.
// Returns true if the action is currently not active but was active in the last frame.
bool InputManager::isActionReleased(Action action) const {
    return !m_actionStates.at(action) && m_lastActionStates.at(action);
}

// Method to mark an action as handled.
// Resets the current and last state of the action.
void InputManager::markActionAsHandled(Action action) {
    m_lastActionStates.at(action) = false;
    m_actionStates.at(action) = false;
}
