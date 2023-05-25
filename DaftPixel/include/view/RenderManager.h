/**
* @file RenderManager.h
* @brief Header file for the RenderManager class
*/

/**
* @class RenderManager
*
* @brief This class manages the rendering process, providing an interface to create, maintain and interact with an SDL window and renderer.
*/

#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include "IDrawable.h"

class RenderManager {
public:
    /**
    * @brief Constructs a new RenderManager instance with the specified window width and height.
    *
    * @param windowWidth Width of the window.
    * @param windowHeight Height of the window.
    */
    RenderManager(uint16_t windowWidth = 800, uint16_t windowHeight = 600);

    /**
    * @brief Destroys the RenderManager instance, cleaning up the created SDL_Window and SDL_Renderer.
    */
    ~RenderManager();

    /**
    * @brief Returns the SDL_Renderer instance associated with this RenderManager.
    *
    * @return SDL_Renderer* The SDL_Renderer instance.
    */
    SDL_Renderer* getRenderer() {
        return renderer;
    }

    /**
    * @brief Renders all drawable objects that have been added to this RenderManager.
    */
    void render();

    /**
    * @brief Clears the rendering target in the current rendering context.
    */
    void clear();

    /**
    * @brief Updates the screen with any rendering performed since the previous call.
    */
    void present();

    /**
    * @brief Adds a drawable object to the RenderManager.
    *
    * @param drawable The drawable object to add.
    */
    void addDrawable(std::shared_ptr<IDrawable> drawable);

private:
    /**
    * @brief The SDL_Renderer instance.
    */
    SDL_Renderer* renderer;

    /**
    * @brief The SDL_Window instance.
    */
    SDL_Window* window;

    /**
    * @brief Width of the SDL_Window.
    */
    uint16_t windowWidth;

    /**
    * @brief Height of the SDL_Window.
    */
    uint16_t windowHeight;

    /**
    * @brief Vector of drawable objects.
    */
    std::vector<std::shared_ptr<IDrawable>> drawables;
};
