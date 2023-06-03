#pragma once
#include "view/RenderManager.h"

namespace Canvas {
    /**
     * @struct RenderContext
     * @brief This struct represents the context for rendering a Canvas.
     */
    struct RenderContext {
        RenderManager& renderManager; ///< Reference to a RenderManager object.
        uint8_t scaleFactor; ///< The current scale factor.

        /**
         * @brief Constructs a new RenderContext instance.
         *
         * @param renderManager Reference to a RenderManager object.
         * @param scaleFactor The scale factor to be used for rendering.
         */
        RenderContext(RenderManager& renderManager, uint8_t scaleFactor)
            : renderManager(renderManager), scaleFactor(scaleFactor) {}


        void changeScaleFactor(uint8_t delta) {
            if (scaleFactor + delta <= 0) {
                throw std::out_of_range("Scale factor must be greater than 0.");
            }
            scaleFactor += delta;
        }
    };
}
