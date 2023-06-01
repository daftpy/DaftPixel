/**
* @file EditorController.h
* @brief Header file for the EditorController class. This class is responsible for running the main application loop, handling events, managing canvases and rendering.
*/

/**
* @class EditorController
*
* @brief The EditorController class manages the application, running the main loop, handling events, managing Canvases, and overseeing rendering.
*/

#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include "view/RenderManager.h"
#include "model/Canvas.h"
#include "model/PixelBuffer.h"
#include "model/Pixel.h"
#include "controller/CanvasController.h"
#include "controller/CanvasRendererController.h"

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

private:
    std::string editorName; ///< The name of the editor. This is displayed in the window title.

    bool running; ///< @brief A flag indicating whether the application is currently running. This is used to control the main application loop.

    /**
     * @brief A vector containing unique pointers to Canvas objects.
     *
     * This vector serves as a container of all Canvas objects created and owned by the EditorController.
     * Any new Canvas that is created will be added to this list and can be accessed for rendering and editing.
     */
    std::vector<std::unique_ptr<Canvas>> canvases;

    RenderManager renderManager; ///< The RenderManager, which is responsible for drawing the Canvas objects and other UI elements to the screen.

    TTF_Font* font; ///< A pointer to the TTF_Font that is used for rendering text on the screen. The lifetime of the font object is managed by the EditorController.
};
