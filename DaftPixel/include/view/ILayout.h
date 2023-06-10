#pragma once
#include <SDL.h>
#include "view/RenderManager.h"
#include "view/IUpdatable.h"

class ILayout : public IDrawable, public IUpdatable {
public:
    /**
    * @brief Constructs a new Layout instance.
    */
    ILayout() {}

    /**
    * @brief Destroys the Layout instance.
    */
    virtual ~ILayout() = default;

    /**
    * @brief Render the object using the provided SDL_Renderer. This is an override of the render method in IDrawable.
    *
    * @param renderer SDL_Renderer used for rendering.
    */
    virtual void render(SDL_Renderer* renderer) const = 0;

    /**
    * @brief Updates the widgets of the Layout using the provided SDL_Renderer. This is an override of the updateWidgets method in IUpdatable.
    *
    * @param renderer SDL_Renderer used for rendering.
    */
    virtual void updateWidgets(SDL_Renderer* renderer) = 0;
};
