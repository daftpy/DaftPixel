#pragma once
#include <SDL_ttf.h>
#include "view/ui/CanvasStatusBar.h"
#include "view/RenderManager.h"
#include "view/IDrawable.h"

class Canvas {
public:
	Canvas(uint16_t width, uint16_t height)
		: canvasWidth(width),
		canvasHeight(height) {}

	void setWidth(uint16_t width);
	uint16_t getWidth() const;

	void setHeight(uint16_t height);
	uint16_t getHeight() const;

private:
	uint16_t canvasWidth;
	uint16_t canvasHeight;
};
