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
#include "view/IDrawable.h"
#include "view/ILayout.h"

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
    * @brief Adds a drawable object to the RenderManager's drawing queue.
    *
    * This method allows the RenderManager to keep track of all drawable objects
    * that need to be rendered in the scene. When the RenderManager's `render`
    * method is called, it will iterate over this list and call each object's
    * `render` method.
    *
    * @param drawable The drawable object to add. This should be an object of a
    * class that implements the IDrawable interface.
    */
    void addDrawable(std::shared_ptr<IDrawable> drawable);

    void addLayout(std::shared_ptr<ILayout> layout);

    /**
    * @brief Returns a pointer to the SDL_Window managed by this RenderManager instance.
    *
    * This allows access to the underlying SDL_Window instance that the RenderManager is responsible for.
    *
    * @return SDL_Window* The pointer to the SDL_Window instance.
    */
    SDL_Window* getWindow() const;

    SDL_Renderer* getRenderer() const;

    void updateLayouts();

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
     * @brief A vector containing shared pointers to objects implementing the IDrawable interface.
     *
     * This vector serves as a drawing queue for the RenderManager. When the RenderManager's `render`
     * method is called, it will iterate over this list and call each object's `render` method.
     * Drawable objects can be added to this list through the `addDrawable` method.
     */
    std::vector<std::shared_ptr<IDrawable>> drawables;

    std::vector<std::shared_ptr<ILayout>> layouts; ///< Vector of drawable objects, representing UI layouts.
};
