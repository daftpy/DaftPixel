#pragma once
#include <memory>
#include "model/Canvas.h"

class CanvasController {
public:
	explicit CanvasController(std::shared_ptr<Canvas> canvas);

	void setDimensions(uint16_t width, uint16_t height);
	
	std::shared_ptr<Canvas> getCanvas() {
		return canvas;
	}

private:
	std::shared_ptr<Canvas> canvas;
};