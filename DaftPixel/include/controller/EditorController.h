/**
* @file EditorController.h
* @brief Header file for the EditorController class. This class is responsible for running the main application loop, handling events, and managing canvases.
*/

/**
* @class EditorController
*
* @brief The EditorController class manages the application, running the main loop, handling events, and managing Canvases.
*/

#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include "view/RenderManager.h"
#include "model/canvas/CanvasSurface.h"
#include "model/PixelBuffer.h"
#include "model/Pixel.h"
#include "controller/canvas/CanvasSurfaceController.h"
#include "model/canvas/RenderContext.h"
#include "manager/InputManager.h"
#include "manager/KeyBindingManager.h"
#include "model/Action.h"
#include "manager/CommandManager.h"

class EditorController {
public:
    /**
    * @brief Constructs a new EditorController, initializing SDL, setting up the RenderManager, and setting up the first Canvas.
    */
    EditorController();

    /**
    * @brief Destructor for the EditorController, cleaning up resources used by SDL, the font, and the RenderManager.
    */
    ~EditorController();

    /**
    * @brief Runs the main application loop, processing events and managing rendering. This function does not return until the application is closed.
    */
    void run();

    /**
    * @brief Handles all SDL events, such as keyboard and mouse input. Updates the state of the application based on these events.
    */
    void handleEvents();

    /**
    * @brief Creates a new Canvas with the specified width and height and adds it to the list of managed canvases.
    * @param width The width of the new Canvas.
    * @param height The height of the new Canvas.
    */
    void createNewCanvas(uint16_t width, uint16_t height);

    void processActions();

private:
    /**
    * @brief The name of the editor. Displayed in the window title.
    */
    std::string editorName;

    /**
    * @brief A flag indicating whether the application is currently running.
    *
    * This is used to control the main application loop.
    */
    bool running;

    /**
     * @brief A vector containing unique pointers to Canvas objects.
     *
     * This vector serves as a container of all Canvas objects created and owned by the EditorController.
     * Any new Canvas that is created will be added to this list and can be accessed for rendering and editing.
     */
    std::vector<std::unique_ptr<CanvasSurface>> canvases;

    /**
    * @brief The RenderManager is responsible for drawing the Canvas objects and other UI elements to the screen.
    */
    RenderManager renderManager;

    /**
    * @brief A pointer to the TTF_Font used for rendering text on the screen.
    *
    * The lifetime of the font object is managed by the EditorController.
    */
    TTF_Font* font;

    /**
    * @brief A list of Actions that have been triggered and are waiting to be processed.
    */
    std::vector<Action> actions;


    // TEMPORARY DEBUG CODE

    /**
    * @brief A unique pointer to the RenderContext.
    *
    * This object is responsible for holding the current rendering context for a Canvas.
    */
    std::unique_ptr<Canvas::RenderContext> renderContext;

    /**
    * @brief A unique pointer to the CommandManager object.
    *
    * This object is responsible for managing the execution, undoing, and redoing of commands.
    */
    std::unique_ptr<CommandManager> commandManager;

    /**
    * @brief A unique pointer to the CanvasSurfaceController object.
    *
    * This object is responsible for handling interactions with the CanvasSurface.
    */
    std::unique_ptr<CanvasSurfaceController> surfaceController;

    /**
    * @brief A unique pointer to the InputManager object.
    *
    * This object is responsible for managing input from the user, such as keyboard and mouse events.
    */
    std::unique_ptr<InputManager> inputManager;

    /**
    * @brief The KeyBindingManager object.
    *
    * This object is responsible for managing the key bindings that determine how user input is mapped to Actions.
    */
    KeyBindingManager keyBindingManager;
};
