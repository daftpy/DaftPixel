#pragma once
#include "view/RenderManager.h"
#include "model/canvas/CanvasSurface.h"
#include <SDL_ttf.h>

namespace Canvas {
    /**
     * @struct RenderContext
     * @brief This struct represents the context for rendering a Canvas.
     */
    struct RenderContext {
        CanvasSurface& canvasSurface; ///< Reference to a CanvasSurface object.
        TTF_Font* font; ///< Pointer to an SDL_TTF font object.
        int32_t windowWidth; ///< Window width, used for scaling and positioning.
        int32_t windowHeight; ///< Window height, used for scaling and positioning.
        uint8_t scaleFactor; ///< The current scale factor.

        /**
         * @brief Constructs a new RenderContext instance.
         *
         * @param renderManager Reference to a RenderManager object.
         * @param scaleFactor The scale factor to be used for rendering.
         */
        RenderContext(CanvasSurface& canvasSurface, TTF_Font* font, uint8_t scaleFactor, SDL_Window* window)
            : canvasSurface(canvasSurface), font(font), scaleFactor(scaleFactor) {
            SDL_GetWindowSize(window, &windowWidth, &windowHeight);
        }

        void changeScaleFactor(int8_t delta) {
            int8_t newScaleFactor = scaleFactor + delta;
            try {
                if (newScaleFactor <= 0) {
                    throw std::out_of_range("Scale factor must be greater than 0.");
                }
            }
            catch (const std::out_of_range& e) {
                // Handle the exception (e.g., log an error message)
                std::cerr << "Error: " << e.what() << std::endl;
                return;
            }
            scaleFactor = newScaleFactor;
        }
    };
}
