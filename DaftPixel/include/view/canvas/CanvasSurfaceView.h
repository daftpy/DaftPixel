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
#include "view/canvas/ui/StatusBar.h"
#include "view/IDrawable.h"
#include "view/RenderManager.h"
#include "model/canvas/RenderContext.h"

class CanvasSurfaceView : public IDrawable {
public:
    /**
    * @brief Constructs a new CanvasSurfaceView instance with a reference to a Canvas, a TTF_Font, and a RenderManager.
    *
    * @param renderContext reference to a RenderContext object which is responsible for maintaining a reference to the
      relevant CanvasSurface and maintaing display characteristics such as scale factor, positioning, etc.
    */
    explicit CanvasSurfaceView(Canvas::RenderContext& renderContext);

    /**
    * @brief Renders the Canvas using the provided SDL_Renderer.
    *
    * @param renderer Pointer to an SDL_Renderer used for rendering.
    */
    void render(SDL_Renderer* renderer) const override;

private:
    Canvas::Gui::StatusBar statusBar; ///< StatusBar instance for rendering the status bar.
    Canvas::RenderContext& renderContext; ///< Reference to a RenderManager for handling rendering operations.
};
