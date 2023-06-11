#pragma once
#include <iostream>
#include <unordered_map>
#include <SDL.h>
#include "manager/InputManager.h"
#include "manager/BindingManager.h"
#include "model/Action.h"
#include "model/Pixel.h"
#include <optional>

/**
 * @class InputManager
 * @brief The InputManager class handles key events and manages the state of actions.
 */
class InputManager {
public:
    /**
     * @brief Constructs an InputManager object.
     * @param bindingManager A reference to a BindingManager object.
     */
    InputManager(BindingManager& bindingManager);

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

    /**
     * @brief Get the current Pixel object that the user is hovering over.
     * @return The current Pixel object.
     */
    std::optional<Pixel> getCurrentPixel() const;

    /**
     * @brief Set the current Pixel object that the user is hovering over.
     * @param pixel The new current Pixel object.
     */
    void setCurrentPixel(Pixel pixel);

private:
    /**
     * @brief A reference to a BindingManager object.
     */
    BindingManager& m_bindingManager;

    /**
     * @brief A map from actions to their current states.
     */
    std::unordered_map<Action, bool> m_actionStates;

    /**
     * @brief A map from actions to their states in the last frame.
     */
    std::unordered_map<Action, bool> m_lastActionStates;

    /**
     * @brief An optional Pixel object representing the current Pixel that the user is hovering over. It can be empty if no Pixel is currently being hovered over.
     */
    std::optional<Pixel> currentPixel;
};
