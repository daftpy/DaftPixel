#pragma once
#include <SDL.h>
#include "view/RenderManager.h"

class IDrawable {
public:
    IDrawable() {}
    virtual ~IDrawable() = default;

    // Renders the object using the provided renderer.
    virtual void render(SDL_Renderer* renderer) const = 0;
};
