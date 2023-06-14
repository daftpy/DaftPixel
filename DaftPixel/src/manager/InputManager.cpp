#include "manager/InputManager.h"
#include <string>

// InputManager constructor
// Initializes all possible actions to inactive (false) state
InputManager::InputManager(BindingManager& bindingManager) : m_bindingManager(bindingManager)
{
    // Initialize all action states to false
    m_actionStates[Action::IncreaseScaleFactor] = false;
    m_actionStates[Action::DecreaseScaleFactor] = false;
    m_actionStates[Action::PaintPixel] = false;
    m_actionStates[Action::SelectPixel] = false;
    m_actionStates[Action::None] = false;

    // Initialize all last action states also to false
    m_lastActionStates[Action::IncreaseScaleFactor] = false;
    m_lastActionStates[Action::DecreaseScaleFactor] = false;
    m_lastActionStates[Action::PaintPixel] = false;
    m_lastActionStates[Action::SelectPixel] = false;
    m_lastActionStates[Action::None] = false;
}

// handleEvent method that handles SDL_Events
void InputManager::handleEvent(const SDL_Event& event) {
    Action action;
    int x, y;
    Uint32 mouseState;

    switch (event.type) {
        // If key release event
    case SDL_KEYUP:
        if (m_bindingManager.getAction(event.key.keysym, action)) {
            // Set last state to current state and current state to false
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = false;
        }
        break;
        // If key press event
    case SDL_KEYDOWN:
        if (m_bindingManager.getAction(event.key.keysym, action)) {
            // Set last state to current state and current state to true
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = true;
        }
        break;
        // If mouse movement event
    case SDL_MOUSEMOTION:
        mouseState = SDL_GetMouseState(&x, &y);
        // If left mouse button is pressed
        if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            SDL_MouseButtonEvent mouseButtonEvent;
            mouseButtonEvent.button = SDL_BUTTON_LEFT;
            mouseButtonEvent.state = SDL_PRESSED;
            // If action is associated with the mouse event, set last state to current state and current state to true
            if (m_bindingManager.getMouseAction(mouseButtonEvent, action)) {
                m_lastActionStates[action] = m_actionStates[action];
                m_actionStates[action] = true;
            }
        }
        // If right mouse button is pressed
        else if (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
            SDL_MouseButtonEvent mouseButtonEvent;
            mouseButtonEvent.button = SDL_BUTTON_RIGHT;
            mouseButtonEvent.state = SDL_PRESSED;
            // If action is associated with the mouse event, set last state to current state and current state to true
            if (m_bindingManager.getMouseAction(mouseButtonEvent, action)) {
                m_lastActionStates[action] = m_actionStates[action];
                m_actionStates[action] = true;
            }
        }
        // If mouse button is not pressed, stop the paint action
        else {
            if (m_actionStates[Action::PaintPixel]) {
                std::cout << "Paint handled!!!!" << std::endl;
                markActionAsHandled(Action::PaintPixel);
            }
        }
        break;
        // If mouse button down or up event
    case SDL_MOUSEBUTTONDOWN:
        if (m_bindingManager.getMouseAction(event.button, action)) {
            // Update the action state
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = true;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        std::cout << "Mouse button up: " << std::to_string(event.button.button) << std::endl;

        if (m_bindingManager.getMouseAction(event.button, action)) {
            // Update the action state
            m_lastActionStates[action] = m_actionStates[action];
            m_actionStates[action] = false;

            // Debug: print the action considered
            std::cout << "Mouse button up: action = " << static_cast<int>(action) << std::endl;

            // Check if left button is released and action is PaintPixel
            if (event.button.button == SDL_BUTTON_LEFT && action == Action::PaintPixel) {
                markActionAsHandled(Action::PaintPixel);  // <-- Mark the PaintPixel action as handled
                std::cout << "Paint action handled." << std::endl;
            }
        }
        break;
    }
}

// Checks if an action was just triggered in this frame
bool InputManager::isActionTriggered(Action action) const {
    // Return true if the action is currently active and was not active in the last frame
    return m_actionStates.at(action) && !m_lastActionStates.at(action);
}

// Checks if an action is currently being pressed
bool InputManager::isActionPressed(Action action) const {
    // Return true if the action is currently active
    return m_actionStates.at(action);
}

// Checks if an action was just released in this frame
bool InputManager::isActionReleased(Action action) const {
    // Return true if the action is currently not active but was active in the last frame
    return !m_actionStates.at(action) && m_lastActionStates.at(action);
}

// Marks an action as handled by resetting its state
void InputManager::markActionAsHandled(Action action) {
    // Resets the current and last state of the action
    m_lastActionStates.at(action) = false;
    m_actionStates.at(action) = false;
}
