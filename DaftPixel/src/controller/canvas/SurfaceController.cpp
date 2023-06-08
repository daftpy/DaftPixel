#include "controller/canvas/SurfaceController.h"

/**
* @brief Constructs a new CanvasController instance with a reference to a CanvasSurface.
*
* @param canvasSurface Reference to a CanvasSurface instance.
*/
Canvas::Controller::SurfaceController::SurfaceController(CanvasSurface& canvasSurface) : canvasSurface(canvasSurface) {
	// Initialization if needed
}

/**
* @brief Set the dimensions of the CanvasSurface.
*
* @param width Width of the CanvasSurface.
* @param height Height of the CanvasSurface.
*/
void Canvas::Controller::SurfaceController::setDimensions(uint16_t width, uint16_t height) {
	canvasSurface.setWidth(width);
	canvasSurface.setHeight(height);
}

/**
* @brief Get a reference to the CanvasSurface instance.
*
* @return CanvasSurface& Reference to the CanvasSurface instance.
*/
CanvasSurface& Canvas::Controller::SurfaceController::getCanvasSurface() {
	return canvasSurface;
}

std::optional<std::pair<int, int>> Canvas::Controller::SurfaceController::pointerToCanvasCoords(int screenX, int screenY, float scaleFactor, int canvasStartX, int canvasStartY) {
    int canvasX = (screenX - canvasStartX) / scaleFactor;
    int canvasY = (screenY - canvasStartY) / scaleFactor;

    if (canvasX < 0 || canvasY < 0 || canvasX >= canvasSurface.getWidth() || canvasY >= canvasSurface.getHeight()) {
        // The pointer is outside the bounds of the canvas.
        return std::nullopt;
    }

    return std::make_pair(canvasX, canvasY);
}


Pixel Canvas::Controller::SurfaceController::getPixel(int canvasX, int canvasY) {
	return canvasSurface.getPixelBuffer().at(canvasX, canvasY);
}