#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "model/canvas/RenderContext.h"
#include "view/IDrawable.h"
#include "model/canvas/Surface.h"
#include "view/canvas/ui/InfoWidget.h"

/**
 * @namespace Canvas
 * @brief Main namespace for Canvas related classes.
 */
namespace Canvas {
    /**
     * @namespace Ui
     * @brief Namespace for GUI related classes and functions.
     */
    namespace Ui {
        /**
         * @class StatusBar
         * @brief Represents a status bar in the GUI.
         *
         * The StatusBar class is a visual component that provides feedback to the user
         * about the status of the application.
         */
        class StatusBar : public IDrawable {
        public:
            /**
             * @brief Constructs a new StatusBar object.
             *
             * @param renderContext Reference to the render context.
             * @param width Reference to the width of the status bar.
             * @param height Reference to the height of the status bar.
             */
            StatusBar(Canvas::RenderContext& renderContext, int32_t& width, int32_t& height);

            /**
             * @brief Destroys the StatusBar object.
             */
            ~StatusBar() {}

            /**
             * @brief Renders the status bar.
             *
             * @param renderer Pointer to the SDL_Renderer object.
             */
            void render(SDL_Renderer* renderer) const override;

            /**
             * @brief Helper method to update a widget.
             *
             * @param widget Reference to the widget to update.
             * @param data The new data for the widget.
             */
            void updateWidget(InfoWidget& widget, const std::string& data);

            /**
             * @brief Updates the widgets of the status bar.
             *
             * @param renderer Pointer to the SDL_Renderer object.
             */
            void updateWidgets(SDL_Renderer* renderer);

            /**
             * @brief Updates the texture of the status bar.
             *
             * @param renderer Pointer to the SDL_Renderer object.
             */
            void updateTexture(SDL_Renderer* renderer);

        private:
            Canvas::RenderContext& renderContext; ///< Reference to the render context.
            InfoWidget canvasDimensionsWidget; ///< Widget displaying the canvas dimensions.
            InfoWidget scaleFactorWidget; ///< Widget displaying the scale factor.
            int32_t& statusBarWidth; ///< Reference to the width of the status bar.
            int32_t& statusBarHeight; ///< Reference to the height of the status bar.

            SDL_Texture* statusBarTexture = nullptr; ///< Texture used for rendering the status bar.
        };
    }
}
