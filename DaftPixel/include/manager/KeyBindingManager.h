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
 * @class KeyBindingManager
 * @brief Class managing key bindings.
 *
 * This class holds a list of key bindings and provides functions
 * to add and remove key bindings, and to get an action associated
 * with a key press.
 */
class KeyBindingManager {
public:
    /**
     * @brief Default constructor
     */
    KeyBindingManager();

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

private:
    /**
    * @brief A list of KeyBindings that have been added.
    */
    std::vector<KeyBinding> m_keyBindings;
};
