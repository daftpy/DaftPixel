/**
 * @file CanvasRenderer.h
 * @brief Header file for the CanvasRenderer class. This class is responsible for rendering a Canvas instance.
 */

 /**
  * @class CanvasRenderer
  *
  * @brief The CanvasRenderer class is responsible for rendering a Canvas instance. It implements the IDrawable interface.
  */
#pragma once

#include "model/canvas/Canvas.h"
#include "view/ui/CanvasStatusBar.h"
#include "view/IDrawable.h"
#include "view/RenderManager.h"

class CanvasRenderer : public IDrawable {
public:
    /**
    * @brief Constructs a new CanvasRenderer instance with a reference to a Canvas, a TTF_Font, and a RenderManager.
    *
    * @param canvas Reference to a Canvas instance that this renderer will manage.
    * @param font Pointer to a TTF_Font used for rendering text on the screen.
    * @param renderManager Reference to a RenderManager for handling rendering operations.
    */
    explicit CanvasRenderer(Canvas& canvas, TTF_Font* font, RenderManager& renderManager);

    /**
    * @brief Renders the Canvas using the provided SDL_Renderer.
    *
    * @param renderer Pointer to an SDL_Renderer used for rendering.
    */
    void render(SDL_Renderer* renderer) const override;

    /**
    * @brief Gets the current scale factor of the CanvasRenderer.
    *
    * @return The current scale factor as an int8_t.
    */
    int8_t getScaleFactor();

    /**
    * @brief Sets the scale factor of the CanvasRenderer.
    *
    * @param scaleFactor The new scale factor as a uint8_t.
    */
    void setScaleFactor(uint8_t scaleFactor);

private:
    TTF_Font* font; ///< Pointer to a TTF_Font used for rendering text on the screen.
    Canvas& canvas; ///< Reference to a Canvas instance that this renderer will manage.
    CanvasStatusBar statusBar; ///< CanvasStatusBar instance for rendering the status bar.
    RenderManager& renderManager; ///< Reference to a RenderManager for handling rendering operations.
    uint8_t scaleFactor; ///< The current scale factor of the CanvasRenderer.
};
