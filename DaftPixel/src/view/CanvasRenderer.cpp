#include "view/CanvasRenderer.h"

CanvasRenderer::CanvasRenderer(Canvas& canvas, TTF_Font* font) : 
	canvas(canvas), statusBar(font), font(font) {}

void CanvasRenderer::render(SDL_Renderer* renderer) const {
	statusBar.render(renderer);
}