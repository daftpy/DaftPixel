/**
 * @file SurfaceView.h
 * @brief Header file for the SurfaceView class, responsible for rendering a CanvasSurface instance.
 */
#pragma once

#include "model/canvas/Surface.h"
#include "view/canvas/ui/StatusBar.h"
#include "view/IDrawable.h"
#include "view/RenderManager.h"
#include "model/canvas/RenderContext.h"
   /**
   * @namespace Canvas::View
   * @brief Namespace for Canvas view related classes and functions.
   */
namespace Canvas {
    namespace View {
        /**
        * @class SurfaceView
        * @brief Responsible for rendering a CanvasSurface instance, implements the IDrawable interface.
        *
        * The SurfaceView class connects the model data from CanvasSurface with rendering operations provided
        * by SDL2. It maintains a reference to RenderContext, which stores display characteristics such as
        * scale factor and positioning.
        */
        class SurfaceView : public IDrawable {
        public:
            /**
            * @brief Constructs a new SurfaceView instance with a reference to a RenderContext object.
            *
            * @param renderContext Reference to a RenderContext object which contains information about
            * the CanvasSurface and display characteristics.
            */
            explicit SurfaceView(Canvas::RenderContext& renderContext);

            /**
            * @brief Destructor that cleans up the SurfaceView resources.
            */
            ~SurfaceView();

            /**
            * @brief Renders the CanvasSurface using the provided SDL_Renderer.
            *
            * @param renderer SDL_Renderer used for rendering.
            */
            void render(SDL_Renderer* renderer) const override;

            /**
            * @brief Sets up a texture using the provided SDL_Renderer.
            *
            * @param renderer SDL_Renderer used for setting up the texture.
            */
            void setupTexture(SDL_Renderer* renderer);

        private:
            Canvas::RenderContext& renderContext; ///< Reference to a RenderContext for handling rendering operations.

            SDL_Texture* canvasTexture; ///< SDL_Texture that represents the canvas texture for rendering.
        };
    }
}
