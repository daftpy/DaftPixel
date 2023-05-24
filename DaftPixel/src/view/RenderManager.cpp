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
	std::cout << "SDL Initialized." << std::endl;

	// Create an SDL window.
	window = SDL_CreateWindow(
		"DaftPixel",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
	std::cout << "Window created." << std::endl;

	// Create an SDL renderer.
	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	std::cout << "Render Manager initialized." << std::endl;
}

void RenderManager::render() {
	// Set the render color (in this case, black).
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer);

	for (const auto& drawable : drawables) {
		drawable->render(renderer);
	}

	// Update the screen with any rendering performed since the previous call.
	SDL_RenderPresent(renderer);
}

void RenderManager::clear() {
	// Set the render color (in this case, black).
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer);
}

void RenderManager::present() {
	// Update the screen with any rendering performed since the previous call.
	SDL_RenderPresent(renderer);
}

void RenderManager::addDrawable(std::shared_ptr<IDrawable> drawable) {
	drawables.push_back(drawable);
}

RenderManager::~RenderManager() {
	// Clean up the renderer and window.
	if (renderer != nullptr) {
		SDL_DestroyRenderer(renderer);
	}

	if (window != nullptr) {
		SDL_DestroyWindow(window);
	}

	// Quit SDL when the RenderManager is destroyed.
	SDL_Quit();
}
