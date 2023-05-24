#include "model/PixelBuffer.h"
#include <stdexcept>

// Construct a new PixelBuffer with a given width, height and default pixel
PixelBuffer::PixelBuffer(
	uint16_t bufferWidth,
	uint16_t bufferHeight,
	const Pixel& defaultPixel
) : bufferWidth(bufferWidth),
bufferHeight(bufferHeight),
pixelData(bufferWidth* bufferHeight, defaultPixel) {
	if (bufferWidth == 0 || bufferHeight == 0) {
		throw std::invalid_argument(
			"Buffer width and buffer height must both be greater than 0."
		);
	}
}

// Get reference to pixel at specified coordinates. Throw an exception if coordinates are out of bounds.
Pixel& PixelBuffer::at(uint16_t x, uint16_t y) {
	if (x >= bufferWidth || y >= bufferHeight) {
		std::ostringstream message;
		message << "Coordinate: (" << x << ", " << y << ") are out of bounds." << std::endl
			<< "Buffer dimension are (" << bufferWidth << ", " << bufferHeight << ")" << std::endl;
		throw std::out_of_range(message.str());
	}
	// Translate 2D coordinates to 1D index and return reference to pixel
	return pixelData[y * bufferWidth + x];
}

// Const version of the above method. Useful for read-only access.
const Pixel& PixelBuffer::at(uint16_t x, uint16_t y) const {
	if (x >= bufferWidth || y >= bufferHeight) {
		std::ostringstream message;
		message << "Coordinate: (" << x << ", " << y << ") are out of bounds." << std::endl
			<< "Buffer dimension are (" << bufferWidth << ", " << bufferHeight << ")" << std::endl;
		throw std::out_of_range(message.str());
	}
	return pixelData[y * bufferWidth + x];
}

// Return width of pixel buffer
uint16_t PixelBuffer::getWidth() const {
	return bufferWidth;
}

// Return height of pixel buffer
uint16_t PixelBuffer::getHeight() const {
	return bufferHeight;
}
