#pragma once
#include <iostream>
#include <unordered_map>
#include <SDL.h>
#include "manager/InputManager.h"
#include "manager/KeyBindingManager.h"
#include "model/Action.h"

/**
 * @class InputManager
 * @brief The InputManager class handles key events and manages the state of actions.
 */
class InputManager {
public:
	/**
	 * @brief Constructs an InputManager object.
	 * @param keyBindingManager A reference to a KeyBindingManager object.
	 */
	InputManager(KeyBindingManager& keyBindingManager);

	/**
	 * @brief Handles an SDL_Event and updates the action states.
	 * @param event An SDL_Event object.
	 */
	void handleEvent(const SDL_Event& event);

	/**
	 * @brief Checks if an action was triggered in the current frame.
	 * @param action The action to check.
	 * @return True if the action was triggered in the current frame, false otherwise.
	 */
	bool isActionTriggered(Action action) const;

	/**
	 * @brief Checks if an action is currently being pressed.
	 * @param action The action to check.
	 * @return True if the action is currently being pressed, false otherwise.
	 */
	bool isActionPressed(Action action) const;

	/**
	 * @brief Checks if an action was released in the current frame.
	 * @param action The action to check.
	 * @return True if the action was released in the current frame, false otherwise.
	 */
	bool isActionReleased(Action action) const;

	/**
	 * @brief Marks an action as handled, resetting its current and last state.
	 * @param action The action to mark as handled.
	 */
	void markActionAsHandled(Action action);

private:
	/**
	 * @brief A reference to a KeyBindingManager object.
	 */
	KeyBindingManager& m_keyBindingManager;

	/**
	 * @brief A map from actions to their current states.
	 */
	std::unordered_map<Action, bool> m_actionStates;

	/**
	 * @brief A map from actions to their states in the last frame.
	 */
	std::unordered_map<Action, bool> m_lastActionStates;
};
