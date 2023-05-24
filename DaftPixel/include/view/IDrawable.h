#pragma once
#include <SDL.h>
#include "view/RenderManager.h"

class IDrawable {
public:
    IDrawable(RenderManager& renderManager) : renderManager(renderManager) {}
    virtual ~IDrawable() = default;

    // Renders the object using the provided renderer.
    virtual void render() const = 0;

protected:
    RenderManager& renderManager;
};
