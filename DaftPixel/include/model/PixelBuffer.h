/**
* @file PixelBuffer.h
* @brief Header file for the PixelBuffer class
*/

/**
* @class PixelBuffer
*
* @brief This class represents an image of pixels.
*
* Each PixelBuffer has a width and height. It can optionally be initialized
* with a default pixel which will be used to populate the buffer.
* If no default pixel is passed the buffer is initialized with black pixels.
*/

#pragma once
#include <sstream>
#include <vector>
#include "model/Pixel.h"

class PixelBuffer {
public:
	/**
	* @brief Constructor for PixelBuffer class
	*
	* @param bufferWidth Width of the pixel buffer
	* @param bufferHeight Height of the pixel buffer
	* @param defaultPixel Default pixel value to populate the buffer
	*
	* Creates a new PixelBuffer with given dimensions and default pixel value.
	* If no default pixel is provided, initializes the buffer with black pixels.
	*/
	PixelBuffer(
		uint16_t bufferWidth,
		uint16_t bufferHeight,
		const Pixel& defaultPixel = Pixel(0, 0, 0, 255)
	);

	/**
	* @brief Access pixel at specified coordinates
	*
	* @param x x-coordinate of the pixel
	* @param y y-coordinate of the pixel
	*
	* @return Reference to Pixel at specified coordinates
	*
	* Throws an out_of_range exception if the coordinates are out of bounds.
	*/
	Pixel& at(uint16_t x, uint16_t y);

	/**
	* @brief Access pixel at specified coordinates (const version)
	*
	* @param x x-coordinate of the pixel
	* @param y y-coordinate of the pixel
	*
	* @return Const reference to Pixel at specified coordinates
	*
	* This function is used when you want to access pixels in a const context.
	*/
	const Pixel& at(uint16_t x, uint16_t y) const;

	/**
	* @brief Get the width of the pixel buffer
	*
	* @return Width of the pixel buffer
	*/
	uint16_t getWidth() const;

	/**
	* @brief Get the height of the pixel buffer
	*
	* @return Height of the pixel buffer
	*/
	uint16_t getHeight() const;

	#ifdef TESTING
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
	uint16_t bufferWidth; ///< Width of the pixel buffer
	uint16_t bufferHeight; ///< Height of the pixel buffer
	std::vector<Pixel> pixelData; ///< Vector storing the pixels in the buffer
};
