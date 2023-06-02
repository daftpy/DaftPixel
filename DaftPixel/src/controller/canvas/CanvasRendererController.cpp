#include "controller/canvas/CanvasRendererController.h"
#include <iostream>

CanvasRendererController::CanvasRendererController(CanvasSurfaceView& canvasRenderer) :
	canvasRenderer(canvasRenderer) {}

void CanvasRendererController::changeScaleFactor(int8_t delta) {
	// todo: convert this to CanvasContextController

	/*if (canvasRenderer.getScaleFactor() + delta <= 0) {
		throw std::out_of_range("Scale factor must be greater than zero");
	}
	canvasRenderer.setScaleFactor(canvasRenderer.getScaleFactor() + delta);*/
}