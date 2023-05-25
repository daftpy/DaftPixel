/**
* @file EditorController.h
* @brief Header file for the EditorController class
*/

/**
* @class EditorController
*
* @brief The EditorController class is responsible for managing the application,
* including running the main loop and handling events.
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

class EditorController {
public:
    /**
    * @brief Constructs a new EditorController, initializing SDL and setting up the render manager and canvas.
    */
    EditorController();

    /**
    * @brief Destructor for the EditorController, cleaning up resources used by the class.
    */
    ~EditorController();

    /**
    * @brief Runs the main application loop. This function does not return until the application is closed.
    */
    void run();

    /**
    * @brief Handles all events, such as keyboard and mouse input.
    */
    void handleEvents();

private:
    std::string editorName; ///< The name of the editor. This is displayed in the window title.
    bool running; ///< A flag indicating whether the application is currently running.
    std::shared_ptr<Canvas> canvas; ///< A shared pointer to the canvas, which contains the pixel data that is displayed.
    RenderManager renderManager; ///< The RenderManager, which is responsible for drawing the canvas and other UI elements to the screen.
    TTF_Font* font; ///< A pointer to the TTF_Font that is used for rendering text.
};
