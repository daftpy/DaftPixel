/**
 * @file CanvasSurfaceView.h
 * @brief Header file for the CanvasSurfaceView class. This class is responsible for rendering a Canvas instance.
 */

 /**
  * @class CanvasSurfaceView
  *
  * @brief The CanvasSurfaceView class is responsible for rendering a Canvas instance. It implements the IDrawable interface.
  */
#pragma once

#include "model/canvas/CanvasSurface.h"
#include "view/canvas/ui/CanvasStatusBar.h"
#include "view/IDrawable.h"
#include "view/RenderManager.h"
#include "model/canvas/RenderContext.h"

class CanvasSurfaceView : public IDrawable {
public:
    /**
    * @brief Constructs a new CanvasSurfaceView instance with a reference to a Canvas, a TTF_Font, and a RenderManager.
    *
    * @param canvas Reference to a Canvas instance that this renderer will manage.
    * @param font Pointer to a TTF_Font used for rendering text on the screen.
    * @param renderManager Reference to a RenderManager for handling rendering operations.
    */
    explicit CanvasSurfaceView(CanvasSurface& canvas, TTF_Font* font, Canvas::RenderContext& renderContext);

    /**
    * @brief Renders the Canvas using the provided SDL_Renderer.
    *
    * @param renderer Pointer to an SDL_Renderer used for rendering.
    */
    void render(SDL_Renderer* renderer) const override;

private:
    TTF_Font* font; ///< Pointer to a TTF_Font used for rendering text on the screen.
    CanvasSurface& canvasSurface; ///< Reference to a Canvas instance that this renderer will manage.
    CanvasStatusBar statusBar; ///< CanvasStatusBar instance for rendering the status bar.
    Canvas::RenderContext& renderContext; ///< Reference to a RenderManager for handling rendering operations.
    uint8_t scaleFactor; ///< The current scale factor of the CanvasSurfaceView.
};
