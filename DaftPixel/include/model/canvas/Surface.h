/**
* @file CanvasSurface.h
* @brief Header file for the CanvasSurface class
*/

/**
* @class CanvasSurface
*
* @brief This class represents a CanvasSurface instance. Each CanvasSurface object stores the width and height of the CanvasSurface.
*/

#pragma once
#include <memory>
#include "model/PixelBuffer.h"

namespace Canvas {
    class Surface {
    public:
        Surface();

        Surface(uint16_t width, uint16_t height);

        /**
        * @brief Constructs a new CanvasSurface instance with specified width and height.
        *
        * @param width Width of the CanvasSurface.
        * @param height Height of the CanvasSurface.
        */
        Surface(uint16_t width, uint16_t height, std::shared_ptr<PixelBuffer> pixelBuffer)
            : canvasWidth(width),
            canvasHeight(height),
            pixelBuffer(std::move(pixelBuffer)) {}

        /**
        * @brief Set the width of the CanvasSurface.
        *
        * @param width Width of the CanvasSurface.
        */
        void setWidth(uint16_t width);

        /**
        * @brief Get the width of the CanvasSurface.
        *
        * @return uint16_t Width of the CanvasSurface.
        */
        uint16_t getWidth() const;

        /**
        * @brief Set the height of the CanvasSurface.
        *
        * @param height Height of the CanvasSurface.
        */
        void setHeight(uint16_t height);

        /**
        * @brief Get the height of the CanvasSurface.
        *
        * @return uint16_t Height of the CanvasSurface.
        */
        uint16_t getHeight() const;

        // In the Canvas class:
        #ifdef TESTING
        std::pair<int, int> _testGetPixelBufferDimensions() const {
            return std::make_pair(pixelBuffer->getWidth(), pixelBuffer->getHeight());
        }
        #endif

        /**
        * @brief Get a reference to the PixelBuffer.
        *
        * @return PixelBuffer& Reference to the PixelBuffer.
        */
        PixelBuffer& getPixelBuffer();


    private:
        /**
        * @brief Width of the CanvasSurface.
        */
        uint16_t canvasWidth;

        /**
        * @brief Height of the CanvasSurface.
        */
        uint16_t canvasHeight;

        /**
        * @brief a smart pointer to the pixelBuffer data.
        */
        std::shared_ptr<PixelBuffer> pixelBuffer;
    };

}