#include "controller/canvas/CanvasSurfaceController.h"

/**
* @brief Constructs a new CanvasController instance with a reference to a CanvasSurface.
*
* @param canvasSurface Reference to a CanvasSurface instance.
*/
CanvasSurfaceController::CanvasSurfaceController(CanvasSurface& canvasSurface) : canvasSurface(canvasSurface) {
	// Initialization if needed
}

/**
* @brief Set the dimensions of the CanvasSurface.
*
* @param width Width of the CanvasSurface.
* @param height Height of the CanvasSurface.
*/
void CanvasSurfaceController::setDimensions(uint16_t width, uint16_t height) {
	canvasSurface.setWidth(width);
	canvasSurface.setHeight(height);
}

/**
* @brief Get a reference to the CanvasSurface instance.
*
* @return CanvasSurface& Reference to the CanvasSurface instance.
*/
CanvasSurface& CanvasSurfaceController::getCanvasSurface() {
	return canvasSurface;
}
