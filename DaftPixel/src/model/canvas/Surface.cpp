#include <stdexcept>
#include "model/canvas/Surface.h"

// Creates a 32x32 Canvas if no height or width is given.
Canvas::Surface::Surface() : canvasWidth(32), canvasHeight(32),
// Creates a shared pointer to a matching 32x32 Pixel Buffer.
pixelBuffer(std::make_shared<PixelBuffer>(32, 32)) {}

Canvas::Surface::Surface(uint16_t width, uint16_t height) : canvasWidth(width), canvasHeight(height),
pixelBuffer(std::make_shared<PixelBuffer>(width, height)) {}

void Canvas::Surface::setWidth(uint16_t width) {
	// Check Canvas width is not set to 0.
	if (width == 0) {
		throw std::invalid_argument("Canvas width must be greater than 0.");
	}
	canvasWidth = width;
}

uint16_t Canvas::Surface::getWidth() const {
	return canvasWidth;
}

void Canvas::Surface::setHeight(uint16_t height) {
	// Check Canvas height is not set to 0.
	if (height == 0) {
		throw std::invalid_argument("Canvas height must be greater than 0.");
	}
	canvasHeight = height;
}

uint16_t Canvas::Surface::getHeight() const {
	return canvasHeight;
}

PixelBuffer& Canvas::Surface::getPixelBuffer() {
	return *pixelBuffer;
}
