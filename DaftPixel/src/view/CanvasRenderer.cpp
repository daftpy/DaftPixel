#include "view/CanvasRenderer.h"

/**
* @brief Constructs a new CanvasRenderer instance with a reference to a Canvas and a TTF_Font.
*
* @param canvas Reference to a Canvas instance.
* @param font TTF_Font used for rendering.
*/
CanvasRenderer::CanvasRenderer(Canvas& canvas, TTF_Font* font) :
	canvas(canvas), statusBar(font), font(font) {}

/**
* @brief Renders the Canvas using the provided SDL_Renderer.
*
* @param renderer SDL_Renderer used for rendering.
*/
void CanvasRenderer::render(SDL_Renderer* renderer) const {
	statusBar.render(renderer);
}
