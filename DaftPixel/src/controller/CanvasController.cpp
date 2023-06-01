#include "controller/CanvasController.h"

/**
* @brief Constructs a new CanvasController instance with a reference to a Canvas.
*
* @param canvas Reference to a Canvas instance.
*/
CanvasController::CanvasController(CanvasSurface& canvas) : canvas(canvas) {
	// Initialization if needed
}

/**
* @brief Set the dimensions of the Canvas.
*
* @param width Width of the Canvas.
* @param height Height of the Canvas.
*/
void CanvasController::setDimensions(uint16_t width, uint16_t height) {
	canvas.setWidth(width);
	canvas.setHeight(height);
}

/**
* @brief Get a reference to the Canvas instance.
*
* @return Canvas& Reference to the Canvas instance.
*/
CanvasSurface& CanvasController::getCanvas() {
	return canvas;
}
