#include "controller/CanvasRendererController.h"
#include <iostream>

CanvasRendererController::CanvasRendererController(CanvasRenderer& canvasRenderer) :
	canvasRenderer(canvasRenderer) {}

void CanvasRendererController::changeScaleFactor(int8_t delta) {
	if (canvasRenderer.getScaleFactor() + delta <= 0) {
		throw std::out_of_range("Scale factor must be greater than zero");
	}
	canvasRenderer.setScaleFactor(canvasRenderer.getScaleFactor() + delta);
}