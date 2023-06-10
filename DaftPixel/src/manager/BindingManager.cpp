#include "manager/BindingManager.h"
#include <iostream>

// Constructor
BindingManager::BindingManager() {};

// Fetches the action associated with a key press
bool BindingManager::getAction(const SDL_Keysym& key, Action& action) {
    // Iterate over all key bindings
    for (const KeyBinding& binding : m_keyBindings) {
        // If key and modifier match, set the action and return true
        if (binding.key == key.sym && binding.modifier == key.mod) {
            action = binding.action;
            return true;
        }
    }
    // If no matching key binding is found, return false
    return false;
}

// Adds a new key binding
void BindingManager::addKeyBinding(const KeyBinding& binding) {
    std::cout << "Keybinding added" << std::endl;
    m_keyBindings.push_back(binding);
}

// Removes a key binding
void BindingManager::removeKeyBinding(const KeyBinding& binding) {
    // Search for the key binding
    auto it = std::find(m_keyBindings.begin(), m_keyBindings.end(), binding);
    // If found, erase it from the vector
    if (it != m_keyBindings.end()) {
        m_keyBindings.erase(it);
    }
}
