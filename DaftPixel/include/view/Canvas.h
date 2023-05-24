#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <view/ui/CanvasStatusBar.h>
#include "view/RenderManager.h"
#include "view/IDrawable.h"

class Canvas : public IDrawable {
public:
	Canvas(uint16_t width, uint16_t height, TTF_Font* font, RenderManager& renderManager)
		: IDrawable(renderManager),
		canvasWidth(width),
		canvasHeight(height),
		font(font),
		renderManager(renderManager),
		statusBar(font, renderManager) {}


	~Canvas() {}
	void render() const override {
		statusBar.render();
	}


private:
	TTF_Font* font;
	RenderManager& renderManager;
	CanvasStatusBar statusBar;
	uint16_t canvasWidth;
	uint16_t canvasHeight;
};