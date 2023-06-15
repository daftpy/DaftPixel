#include "view/RenderManager.h"

RenderManager::RenderManager(uint16_t windowWidth, uint16_t windowHeight) :
	window(nullptr),
	renderer(nullptr),
	windowWidth(windowWidth),
	windowHeight(windowHeight) {

	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return;
	}

	// Create an SDL window.
	window = SDL_CreateWindow(
		"DaftPixel",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

	// Create an SDL renderer for hardware-accelerated rendering.
	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
}

void RenderManager::render() {
	// Update layouts and render all registered drawable objects
	updateLayouts();

	for (const auto& drawable : drawables) {
		drawable->render(renderer);
	}
}

void RenderManager::clear() {
	// Set the render color to black and clear the current rendering target.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void RenderManager::present() {
	// Update the screen with any rendering performed since the last call to present.
	SDL_RenderPresent(renderer);
}

void RenderManager::addDrawable(std::shared_ptr<IDrawable> drawable) {
	// Add a drawable object to the list of drawable objects
	drawables.push_back(drawable);
}

void RenderManager::addLayout(std::shared_ptr<ILayout> layout) {
	// Add a layout to the list of layouts
	layouts.push_back(layout);
}

SDL_Window* RenderManager::getWindow() const {
	// Return the window object
	return window;
}

SDL_Renderer* RenderManager::getRenderer() const {
	// Return the renderer object
	return renderer;
}

RenderManager::~RenderManager() {
	// Destroy the renderer and window, then quit SDL upon destruction of RenderManager.
	if (renderer != nullptr) {
		SDL_DestroyRenderer(renderer);
	}

	if (window != nullptr) {
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}

void RenderManager::updateLayouts() {
	// Iterate over all layouts, updating each widget contained within them
	for (auto& layout : layouts) {
		layout->updateWidgets(renderer);
	}
}
