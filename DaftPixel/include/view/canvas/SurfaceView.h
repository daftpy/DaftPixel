/**
 * @file SurfaceView.h
 * @brief Header file for the SurfaceView class. This class is responsible for rendering a CanvasSurface instance.
 */

 /**
  * @class SurfaceView
  *
  * @brief The SurfaceView class is responsible for rendering a CanvasSurface instance. It implements the IDrawable interface.
  */
#pragma once

#include "model/canvas/Surface.h"
#include "view/canvas/ui/StatusBar.h"
#include "view/IDrawable.h"
#include "view/RenderManager.h"
#include "model/canvas/RenderContext.h"

  /**
   * @file SurfaceView.h
   * @brief Header file for the SurfaceView class. This class is responsible for rendering a CanvasSurface instance.
   */

   /**
    * @namespace Canvas
    * @brief Main namespace for Canvas related classes.
    */
namespace Canvas {
    /**
     * @namespace View
     * @brief Namespace for all View related classes and functions.
     */
    namespace View {
        /**
        * @class SurfaceView
        *
        * @brief The SurfaceView class is responsible for rendering a CanvasSurface instance. It implements the IDrawable interface.
        */
        class SurfaceView : public IDrawable {
        public:
            /**
            * @brief Constructs a new SurfaceView instance with a reference to a RenderContext object.
            *
            * @param renderContext reference to a RenderContext object which maintains a reference to the relevant
            *        CanvasSurface and maintains display characteristics such as scale factor, positioning, etc.
            */
            explicit SurfaceView(Canvas::RenderContext& renderContext);

            /**
            * @brief Renders the CanvasSurface using the provided SDL_Renderer.
            *
            * @param renderer Pointer to an SDL_Renderer used for rendering.
            */
            void render(SDL_Renderer* renderer) const override;

            void updateWidgets(SDL_Renderer* renderer);

        private:
            Canvas::Gui::StatusBar statusBar; ///< StatusBar instance for rendering the status bar.
            Canvas::RenderContext& renderContext; ///< Reference to a RenderContext for handling rendering operations.
        };
    }
}
