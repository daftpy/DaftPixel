#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "view/RenderManager.h"
#include "view/IDrawable.h"
#include "model/canvas/Canvas.h"

class CanvasStatusBar : public IDrawable {
public:
	CanvasStatusBar(TTF_Font* font, Canvas& canvas, RenderManager& renderManager) : 
		font(font), 
		canvas(canvas),
		renderManager(renderManager) {}
	~CanvasStatusBar() {}
	void render(SDL_Renderer* renderer) const override;

private:
	TTF_Font* font;
	Canvas& canvas;
	RenderManager& renderManager;
};