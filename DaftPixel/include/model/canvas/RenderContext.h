#pragma once
#include "view/RenderManager.h"
#include "model/canvas/Surface.h"
#include <SDL_ttf.h>
#include <vector>
#include "view/IDrawable.h"

namespace Canvas {
    /**
     * @struct RenderContext
     * @brief This struct represents the context for rendering a Canvas.
     *
     * RenderContext is a data structure that holds a collection of necessary information
     * for rendering a Canvas. It includes references and pointers to objects like CanvasSurface,
     * SDL_TTF font object, along with window size and scale factor details.
     */
    struct RenderContext {
        Canvas::Surface& canvasSurface; ///< Reference to a CanvasSurface object, which is being rendered.
        TTF_Font* font; ///< Pointer to an SDL_TTF font object, used in text rendering.
        int32_t windowWidth; ///< The current width of the window, used for scaling and positioning.
        int32_t windowHeight; ///< The current height of the window, used for scaling and positioning.
        uint8_t scaleFactor; ///< The current scale factor, used in resizing the Canvas.

        /**
         * @brief Constructs a new RenderContext instance.
         *
         * @param canvasSurface Reference to a CanvasSurface object.
         * @param font Pointer to an SDL_TTF font object.
         * @param scaleFactor The scale factor to be used for rendering.
         * @param window Pointer to an SDL_Window object.
         */
        RenderContext(Canvas::Surface& canvasSurface, TTF_Font* font, uint8_t scaleFactor, SDL_Window* window)
            : canvasSurface(canvasSurface), font(font), scaleFactor(scaleFactor) {
            SDL_GetWindowSize(window, &windowWidth, &windowHeight);
        }

        /**
         * @brief Updates the current window size.
         *
         * @param newWidth The new window width.
         * @param newHeight The new window height.
         */
        void updateWindowSize(int32_t newWidth, int32_t newHeight);

        /**
         * @brief Changes the current scale factor by a given amount.
         *
         * @param delta The amount to change the scale factor by.
         */
        void changeScaleFactor(int8_t delta);

        /**
         * @brief Returns the x-coordinate of the starting point of the canvas.
         *
         * @return The x-coordinate of the starting point of the canvas.
         */
        int getCanvasStartX() const;

        /**
         * @brief Returns the y-coordinate of the starting point of the canvas.
         *
         * @return The y-coordinate of the starting point of the canvas.
         */
        int getCanvasStartY() const;
    };
}
