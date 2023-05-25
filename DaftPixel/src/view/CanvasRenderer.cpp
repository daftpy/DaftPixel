#include "view/CanvasRenderer.h"

CanvasRenderer::CanvasRenderer(std::shared_ptr<Canvas> canvas, TTF_Font* font) : 
	canvas(std::move(canvas)), statusBar(font), font(font) {}

void CanvasRenderer::render(SDL_Renderer* renderer) const {
	statusBar.render(renderer);
}