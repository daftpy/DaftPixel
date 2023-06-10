/**
 * @file
 * @brief This file contains the declaration of the Action enum class.
 */

#pragma once

 /**
  * @enum Action
  * @brief Represents the possible actions that a user can perform in the application.
  *
  * These actions are used within the input and command manager to handle user inputs and execute corresponding commands.
  */
enum class Action {
    // TODO: More actions

    /**
     * @brief Represents an action to increase the scale factor of an object.
     *
     * When this action is triggered in the input manager, the command manager will execute a command to increase the scale factor.
     */
    IncreaseScaleFactor,

    /**
     * @brief Represents an action to decrease the scale factor of an object.
     *
     * When this action is triggered in the input manager, the command manager will execute a command to decrease the scale factor.
     */
    DecreaseScaleFactor,

    /**
     * @brief Represents an action to apply color to a specific pixel on the canvas.
     *
     * When this action is triggered in the input manager (typically by a mouse click or mouse drag event),
     * the command manager will execute a command to apply color to the pixel at the current mouse position.
     * The specific color to be applied may be determined by the current paint color setting in the application.
     */
    PaintPixel,

    /**
     * @brief Represents the absence of action. It must always come last in the enumeration.
     *
     * This is used when no action is triggered in the input manager.
     */
    None
};
