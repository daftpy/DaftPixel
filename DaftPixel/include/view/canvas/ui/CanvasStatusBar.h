#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "model/canvas/RenderContext.h"
#include "view/IDrawable.h"
#include "model/canvas/CanvasSurface.h"

class CanvasStatusBar : public IDrawable {
public:
	CanvasStatusBar(TTF_Font* font, Canvas::RenderContext& renderContext) : 
		font(font),
		renderContext(renderContext) {}
	~CanvasStatusBar() {}
	void render(SDL_Renderer* renderer) const override;

private:
	TTF_Font* font;
	Canvas::RenderContext& renderContext;
};