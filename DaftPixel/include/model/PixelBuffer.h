#pragma once
#include <sstream>
#include <vector>
#include "model/Pixel.h"

/**
 * @class PixelBuffer
 * @brief Stores a buffer of Pixels in row-major order.
 *
 * The PixelBuffer class is essentially a 2D array of Pixels that are stored in a
 * 1D std::vector in row-major order. This means that each row of pixels is stored
 * one after the other in the vector.
 */
class PixelBuffer {
public:
    /**
     * @brief Constructs a new PixelBuffer instance.
     *
     * @param bufferWidth Width of the pixel buffer.
     * @param bufferHeight Height of the pixel buffer.
     * @param defaultPixel Default pixel value to fill the buffer with (default is opaque black).
     */
    PixelBuffer(uint16_t bufferWidth, uint16_t bufferHeight, const Pixel& defaultPixel = Pixel(0, 0, 0, 255))
        : bufferWidth(bufferWidth), bufferHeight(bufferHeight), pixelData(bufferWidth* bufferHeight, defaultPixel) {}

    /**
     * @brief Get a reference to the Pixel at the given position.
     *
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return Reference to the Pixel at the specified position.
     */
    Pixel& at(uint16_t x, uint16_t y) {
        return pixelData[y * bufferWidth + x];
    }

    /**
     * @brief Get a constant reference to the Pixel at the given position.
     *
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return Constant reference to the Pixel at the specified position.
     */
    const Pixel& at(uint16_t x, uint16_t y) const {
        return pixelData[y * bufferWidth + x];
    }

    /**
     * @brief Get the width of the Pixel buffer.
     *
     * @return Width of the Pixel buffer.
     */
    uint16_t getWidth() const {
        return bufferWidth;
    }

    /**
     * @brief Get the height of the Pixel buffer.
     *
     * @return Height of the Pixel buffer.
     */
    uint16_t getHeight() const {
        return bufferHeight;
    }

    /**
     * @brief Get a pointer to the raw pixel data.
     *
     * @return A pointer to the raw pixel data.
     */
    const uint32_t* getPixelData() const {
        static_assert(sizeof(Pixel) == sizeof(uint32_t));
        return reinterpret_cast<const uint32_t*>(pixelData.data());
    }

#ifdef TESTING
    /**
     * @brief Generate random Pixels for testing.
     */
    void generateRandomPixels() {
        for (uint16_t x = 0; x < this->getWidth(); ++x) {
            for (uint16_t y = 0; y < this->getHeight(); ++y) {
                // Generate random RGB values between 0 and 255.
                uint8_t red = rand() % 256;
                uint8_t green = rand() % 256;
                uint8_t blue = rand() % 256;

                // Set the pixel color.
                this->at(x, y).set(red, green, blue);
            }
        }
    }
#endif

private:
    uint16_t bufferWidth; ///< Width of the pixel buffer.
    uint16_t bufferHeight; ///< Height of the pixel buffer.
    std::vector<Pixel> pixelData; ///< Vector storing the pixels in the buffer in row-major order.
};
