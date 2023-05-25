/**
* @file IDrawable.h
* @brief Header file for the IDrawable interface
*/

/**
* @interface IDrawable
*
* @brief This interface declares the methods that must be implemented by any class that is to be drawable by an SDL_Renderer.
*/

#pragma once
#include <SDL.h>
#include "view/RenderManager.h"

class IDrawable {
public:
    /**
    * @brief Constructs a new IDrawable instance.
    */
    IDrawable() {}

    /**
    * @brief Destroys the IDrawable instance.
    */
    virtual ~IDrawable() = default;

    /**
    * @brief Render the object using the provided SDL_Renderer. Must be implemented by any class that inherits from IDrawable.
    *
    * @param renderer SDL_Renderer used for rendering.
    */
    virtual void render(SDL_Renderer* renderer) const = 0;
};
