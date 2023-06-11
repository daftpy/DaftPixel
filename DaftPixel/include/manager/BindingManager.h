#pragma once
#include <SDL.h>
#include <vector>
#include "model/Action.h"

/**
 * @struct KeyBinding
 * @brief Structure representing a key binding.
 *
 * This struct holds a key binding, consisting of a key code,
 * a key modifier and an associated action.
 */
struct KeyBinding {
    SDL_Keycode key; ///< The SDL key code
    SDL_Keymod modifier; ///< The SDL key modifier
    Action action; ///< The action associated with the key and modifier

    /**
     * @brief Equality operator
     *
     * @param other The KeyBinding instance to compare with
     * @return True if all members are equal, false otherwise
     */
    bool operator==(const KeyBinding& other) const {
        return key == other.key && modifier == other.modifier && action == other.action;
    }
};

/**
 * @struct MouseBinding
 * @brief Structure representing a mouse binding.
 *
 * This struct holds a mouse binding, consisting of a mouse button code,
 * a mouse event type, a key modifier and an associated action.
 */
struct MouseBinding {
    SDL_EventType eventType; ///< The SDL event type (e.g., SDL_MOUSEBUTTONDOWN or SDL_MOUSEBUTTONUP)
    Uint8 button; ///< The SDL mouse button code
    SDL_Keymod modifier; ///< The SDL key modifier
    Action action; ///< The action associated with the button and modifier

    /**
     * @brief Equality operator
     *
     * @param other The MouseBinding instance to compare with
     * @return True if all members are equal, false otherwise
     */
    bool operator==(const MouseBinding& other) const {
        return eventType == other.eventType && button == other.button && modifier == other.modifier && action == other.action;
    }
};


/**
 * @class BindingManager
 * @brief Class managing action bindings.
 *
 * This class holds a list of key and mouse bindings and provides functions
 * to add and remove key and mouse bindings, and to get an action associated
 * with a key or button press.
 */
class BindingManager {
public:
    /**
     * @brief Default constructor
     */
    BindingManager();

    /**
     * @brief Fetches the action associated with a key press.
     *
     * @param key The key pressed by the user
     * @param action The action associated with the key press
     * @return True if a matching key binding is found, false otherwise
     */
    bool getAction(const SDL_Keysym&, Action& action);

    /**
     * @brief Adds a new key binding.
     *
     * @param binding The key binding to be added
     */
    void addKeyBinding(const KeyBinding& binding);

    /**
     * @brief Removes a key binding.
     *
     * @param binding The key binding to be removed
     */
    void removeKeyBinding(const KeyBinding& binding);

    /**
     * @brief Fetches the action associated with a mouse button press.
     *
     * @param button The mouse button pressed by the user
     * @param action The action associated with the button press
     * @return True if a matching mouse binding is found, false otherwise
     */
    bool getMouseAction(const SDL_MouseButtonEvent&, Action& action);

    /**
     * @brief Adds a new mouse button binding.
     *
     * @param binding The mouse button binding to be added
     */
    void addMouseButtonBinding(const MouseBinding& binding);

    /**
     * @brief Removes a mouse button binding.
     *
     * @param binding The mouse button binding to be removed
     */
    void removeMouseButtonBinding(const MouseBinding& binding);

    const std::vector<MouseBinding>& getMouseBindings() const;

private:
    /**
     * @brief A list of KeyBindings that have been added.
     */
    std::vector<KeyBinding> m_keyBindings;

    /**
     * @brief A list of MouseBindings that have been added.
     */
    std::vector<MouseBinding> m_mouseBindings;
};
