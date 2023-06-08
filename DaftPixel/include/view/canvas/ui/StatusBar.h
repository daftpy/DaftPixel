#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "model/canvas/RenderContext.h"
#include "view/IDrawable.h"
#include "model/canvas/Surface.h"

/**
 * @namespace Canvas
 * @brief Main namespace for Canvas related classes.
 */
namespace Canvas {
    /**
     * @namespace Gui
     * @brief Namespace for GUI related classes and functions.
     */
    namespace Gui {
        /**
         * @class StatusBar
         * @brief Class representing a status bar in the GUI.
         * @extends IDrawable
         *
         * This class represents a status bar in the GUI. It is a visual component
         * that provides feedback to the user about the status of the application.
         */
        class StatusBar : public IDrawable {
        public:
            /**
             * @brief Construct a new StatusBar object.
             * @param renderContext Reference to the render context.
             */
            StatusBar(Canvas::RenderContext& renderContext) :
                renderContext(renderContext) {}

            /**
             * @brief Destroy the StatusBar object.
             */
            ~StatusBar() {}

            /**
             * @brief Render the status bar.
             * @param renderer Pointer to the SDL_Renderer object.
             */
            void render(SDL_Renderer* renderer) const override;

        private:
            Canvas::RenderContext& renderContext; ///< @brief Reference to the render context.
        };
    }
}