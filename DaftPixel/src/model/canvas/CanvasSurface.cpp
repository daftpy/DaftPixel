#include <stdexcept>
#include "model/canvas/CanvasSurface.h"

// Creates a 32x32 Canvas if no height or width is given.
CanvasSurface::CanvasSurface() : canvasWidth(32), canvasHeight(32),
// Creates a shared pointer to a matching 32x32 Pixel Buffer.
pixelBuffer(std::make_shared<PixelBuffer>(32, 32)) {}

CanvasSurface::CanvasSurface(uint16_t width, uint16_t height) : canvasWidth(width), canvasHeight(height),
pixelBuffer(std::make_shared<PixelBuffer>(width, height)) {}

void CanvasSurface::setWidth(uint16_t width) {
	// Check Canvas width is not set to 0.
	if (width == 0) {
		throw std::invalid_argument("Canvas width must be greater than 0.");
	}
	canvasWidth = width;
}

uint16_t CanvasSurface::getWidth() const {
	return canvasWidth;
}

void CanvasSurface::setHeight(uint16_t height) {
	// Check Canvas height is not set to 0.
	if (height == 0) {
		throw std::invalid_argument("Canvas height must be greater than 0.");
	}
	canvasHeight = height;
}

uint16_t CanvasSurface::getHeight() const {
	return canvasHeight;
}

PixelBuffer& CanvasSurface::getPixelBuffer() {
	return *pixelBuffer;
}
