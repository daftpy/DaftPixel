#include "controller/CanvasController.h"

CanvasController::CanvasController(Canvas& canvas) : canvas(canvas) {
	// Initialization if needed
}

void CanvasController::setDimensions(uint16_t width, uint16_t height) {
	canvas.setWidth(width);
	canvas.setHeight(height);
}
