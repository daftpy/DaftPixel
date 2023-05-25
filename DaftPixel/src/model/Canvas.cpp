#include "model/Canvas.h"

void Canvas::setWidth(uint16_t width) {
	canvasWidth = width;
}

uint16_t Canvas::getWidth() const {
	return canvasWidth;
}

void Canvas::setHeight(uint16_t height) {
	canvasHeight = height;
}

uint16_t Canvas::getHeight() const {
	return canvasHeight;
}
