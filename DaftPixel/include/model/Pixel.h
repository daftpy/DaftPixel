#pragma once
#include <cstdint>
#include <iostream>

/**
 * @class Pixel
 * @brief Represents an ARGB color pixel.
 *
 * A pixel contains color data (Red, Green, Blue, and Alpha values).
 * The color is stored in a single 32-bit integer where each 8-bit segment represents
 * a color or the alpha channel in the ARGB format.
 */
class Pixel {
public:
    /**
     * @brief Default constructor
     *
     * Creates a pixel with a default color of opaque black.
     */
    Pixel() : color(0xFF000000) {}

    /**
     * @brief Constructor with color values
     *
     * @param r Red color value
     * @param g Green color value
     * @param b Blue color value
     * @param a Alpha value (opacity), default value is 255 (opaque)
     *
     * Creates a pixel with the provided color and alpha values.
     */
    Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
        set(r, g, b, a);
    }

    /**
     * @brief Get the Red color value
     *
     * @return Red color value as an 8-bit unsigned integer
     */
    uint8_t getRed() const {
        return (color >> 16) & 0xFF;
    }

    /**
     * @brief Get the Green color value
     *
     * @return Green color value as an 8-bit unsigned integer
     */
    uint8_t getGreen() const {
        return (color >> 8) & 0xFF;
    }

    /**
     * @brief Get the Blue color value
     *
     * @return Blue color value as an 8-bit unsigned integer
     */
    uint8_t getBlue() const {
        return color & 0xFF;
    }

    /**
     * @brief Get the Alpha (opacity) value
     *
     * @return Alpha value as an 8-bit unsigned integer
     */
    uint8_t getAlpha() const {
        return (color >> 24) & 0xFF;
    }

    /**
     * @brief Set the Red color value
     *
     * @param r New Red color value
     */
    void setRed(uint8_t r) {
        color = (color & 0xFF00FFFF) | (r << 16);
    }

    /**
     * @brief Set the Green color value
     *
     * @param g New Green color value
     */
    void setGreen(uint8_t g) {
        color = (color & 0xFFFF00FF) | (g << 8);
    }

    /**
     * @brief Set the Blue color value
     *
     * @param b New Blue color value
     */
    void setBlue(uint8_t b) {
        color = (color & 0xFFFFFF00) | b;
    }

    /**
     * @brief Set the Alpha (opacity) value
     *
     * @param a New Alpha value
     */
    void setAlpha(uint8_t a) {
        color = (color & 0x00FFFFFF) | (a << 24);
    }

    /**
     * @brief Set the pixel color
     *
     * @param r Red color value
     * @param g Green color value
     * @param b Blue color value
     * @param a Alpha value (opacity), default value is 255 (opaque)
     */
    void set(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
        color = (a << 24) | (r << 16) | (g << 8) | b;
    }

    /**
     * @brief Get the raw 32-bit color value
     *
     * @return Raw 32-bit color value
     */
    uint32_t getRawColor() const {
        return color;
    }

    /**
     * @brief Output operator
     *
     * Overloads the output operator to print pixel data in "R: G: B: A:" format.
     *
     * @param os Output stream
     * @param pixel Pixel instance
     * @return Updated output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
        os << "R: " << static_cast<int>(pixel.getRed()) << ", "
            << "G: " << static_cast<int>(pixel.getGreen()) << ", "
            << "B: " << static_cast<int>(pixel.getBlue()) << ", "
            << "A: " << static_cast<int>(pixel.getAlpha());
        return os;
    }

private:
    uint32_t color;  ///< 32-bit color value in ARGB format
};
