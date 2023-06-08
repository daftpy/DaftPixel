/**
* @file SurfaceController.h
* @brief Header file for the SurfaceController class. This class controls a CanvasSurface instance, allowing for the setting of its dimensions and providing access to the CanvasSurface instance.
*/

/**
* @class SurfaceController
*
* @brief This class controls a CanvasSurface instance. It allows the setting of the Canvas's dimensions and provides access to the CanvasSurface instance.
*/

#pragma once
#include <memory>
#include "model/canvas/Surface.h"
#include "model/Pixel.h"
#include <optional>

namespace Canvas {
    namespace Controller {
        class SurfaceController {
        public:
            /**
            * @brief Constructs a new SurfaceController instance with a reference to a CanvasSurface.
            *
            * @param canvasSurface Reference to a CanvasSurface instance.
            */
            explicit SurfaceController(Canvas::Surface& canvas);

            /**
            * @brief Set the dimensions of the CanvasSurface.
            *
            * @param width Width of the CanvasSurface.
            * @param height Height of the CanvasSurface.
            */
            void setDimensions(uint16_t width, uint16_t height);

            /**
            * @brief Get a reference to the CanvasSurface instance.
            *
            * @return Canvas& Reference to the CanvasSurface instance.
            */
            Canvas::Surface& getCanvasSurface();



            /**
            * @brief Converts screen coordinates to canvas coordinates.
            *
            * @param screenX X coordinate of the pointer on the screen.
            * @param screenY Y coordinate of the pointer on the screen.
            * @param scaleFactor The scale factor of the canvas.
            * @param canvasStartX The X coordinate of the top-left corner of the canvas on the screen.
            * @param canvasStartY The Y coordinate of the top-left corner of the canvas on the screen.
            * @return std::pair<int, int> The canvas coordinates corresponding to the given screen coordinates.
            */
            std::optional<std::pair<int, int>> pointerToCanvasCoords(int screenX, int screenY, float scaleFactor, int canvasStartX, int canvasStartY);

            /**
            * @brief Returns the color of the pixel at the given canvas coordinates.
            *
            * @param canvasX X coordinate of the pixel on the canvas.
            * @param canvasY Y coordinate of the pixel on the canvas.
            * @return Pixel The pixel at the given canvas coordinates.
            */
            Pixel getPixel(int canvasX, int canvasY);



        private:
            /**
            * @brief Reference to a CanvasSurface instance.
            */
            Canvas::Surface& canvasSurface;
        };

    }
}
