#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <view/ui/CanvasStatusBar.h>
#include "view/RenderManager.h"
#include "view/IDrawable.h"

class Canvas : public IDrawable {
public:
	Canvas(uint16_t width, uint16_t height, TTF_Font* font, RenderManager& renderManager)
		: canvasWidth(width),
		canvasHeight(height),
		font(font),
		renderManager(renderManager),
		statusBar(font) {}


	~Canvas() {}
	void render(SDL_Renderer* renderer) const override {
		statusBar.render(renderer);
	}


private:
	TTF_Font* font;
	RenderManager& renderManager;
	CanvasStatusBar statusBar;
	uint16_t canvasWidth;
	uint16_t canvasHeight;
};