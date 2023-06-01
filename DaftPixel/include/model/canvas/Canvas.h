/**
* @file Canvas.h
* @brief Header file for the Canvas class
*/

/**
* @class Canvas
*
* @brief This class represents a Canvas instance. Each Canvas object stores the width and height of the canvas.
*/

#pragma once
#include <memory>
#include "model/PixelBuffer.h"

class Canvas {
public:
    Canvas();

    Canvas(uint16_t width, uint16_t height);

    /**
    * @brief Constructs a new Canvas instance with specified width and height.
    *
    * @param width Width of the Canvas.
    * @param height Height of the Canvas.
    */
    Canvas(uint16_t width, uint16_t height, std::shared_ptr<PixelBuffer> pixelBuffer)
        : canvasWidth(width),
        canvasHeight(height),
        pixelBuffer(std::move(pixelBuffer)) {}

    /**
    * @brief Set the width of the Canvas.
    *
    * @param width Width of the Canvas.
    */
    void setWidth(uint16_t width);

    /**
    * @brief Get the width of the Canvas.
    *
    * @return uint16_t Width of the Canvas.
    */
    uint16_t getWidth() const;

    /**
    * @brief Set the height of the Canvas.
    *
    * @param height Height of the Canvas.
    */
    void setHeight(uint16_t height);

    /**
    * @brief Get the height of the Canvas.
    *
    * @return uint16_t Height of the Canvas.
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
    * @brief Width of the Canvas.
    */
    uint16_t canvasWidth;

    /**
    * @brief Height of the Canvas.
    */
    uint16_t canvasHeight;

    /**
    * @brief a smart pointer to the pixelBuffer data.
    */
    std::shared_ptr<PixelBuffer> pixelBuffer;
};
