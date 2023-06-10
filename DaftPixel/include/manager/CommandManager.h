/**
 * @file CommandManager.h
 * @brief Command Manager interface file
 */

#pragma once
#include "model/Action.h"
#include "manager/InputManager.h"
#include "model/canvas/RenderContext.h"
#include "controller/canvas/SurfaceController.h"

 /**
  * @class CommandManager
  * @brief A class that manages the execution of commands on the canvas.
  *
  * This class takes an action and an input, and executes the corresponding command on the canvas.
  */
class CommandManager {
public:
    /**
     * @brief Construct a new Command Manager object.
     *
     * This constructor creates a Command Manager that operates on a given RenderContext.
     *
     * @param renderContext The RenderContext that this CommandManager operates on.
     */
    CommandManager(Canvas::RenderContext& renderContext);

    /**
     * @brief Execute a command on the canvas.
     *
     * This method takes an action and an input, and performs the corresponding command on the canvas.
     *
     * @param action The action to be performed.
     * @param inputManager The InputManager that provides the input for the action.
     * @param event The SDL_Event that represents the user event that triggered the action.
     * @param surfaceController The SurfaceController that interfaces with the canvas.
     * @param renderContext The RenderContext that this command operates on.
     */
    void executeCommand(Action action, InputManager& inputManager, const SDL_Event& event, Canvas::Controller::SurfaceController surfaceController, Canvas::RenderContext& renderContext);

private:
    /**
     * @brief The RenderContext that this CommandManager operates on.
     */
    Canvas::RenderContext& renderContext;
};
