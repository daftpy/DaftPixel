/**
* @file Pixel.h
* @brief Header file for the Pixel class
*/

/**
* @class Pixel
* 
* @brief This class represents the most basic unit of the application. Each
* Pixel object stores the color data as RGBA as well as methods for
* manipulating the data.
*/


#pragma once
#include <cstdint>
#include <iostream>

class Pixel {
public:
    /**
    * @brief Constructs a new Pixel instance with default black values.
    */
    Pixel();

    /**
    * @brief Constructs a new Pixel instance with RGBA values.
    * 
    * @param r Red component (0-255)
    * @param g Green component (0-255)
    * @param b Blue component (0-255)
    */
    Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

    /**
    * @brief Get the red component of the pixel.
    *
    * @return uint8_t Red component (0-255)
    */
    uint8_t getRed() const;

    /**
    * @brief Get the green component of the pixel.
    * 
    * @return uint8_t Green component (0-255)
    */
    uint8_t getGreen() const;

    /**
    * @brief Get the blue component of the pixel.
    * 
    * @return uint8_t Blue component (0-255)
    */
    uint8_t getBlue() const;

    /**
    * @brief Get the alpha component of the pixel.
    * 
    * @return uint8_t Alpha component (0-255)
    */
    uint8_t getAlpha() const;

    void setRed(uint8_t r);
    void setGreen(uint8_t g);
    void setBlue(uint8_t b);
    void setAlpha(uint8_t a);

    /**
    * @brief Sets the color of the pixel.
    *
    * @param r The red component (0-255).
    * @param g The green component (0-255).
    * @param b The blue component (0-255).
    * @param a The alpha component (0-255), defaulting to 255 (opaque).
    */
    void set(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

    // << operator overload to output RGBA values.
    friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);

private:
    uint8_t red; ///< Red value of the pixel object
    uint8_t green; ///< Green value of the pixel object
    uint8_t blue; ///< Blue value of the pixel object
    uint8_t alpha; ///< Width of the pixel object
};
