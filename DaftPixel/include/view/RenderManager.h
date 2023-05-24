#pragma once
#include <SDL.h>
#include <iostream>

class RenderManager {
public:
	RenderManager(uint16_t windowWidth = 800, uint16_t windowHeight = 600);
	~RenderManager();
	SDL_Renderer* getRenderer() {
		return renderer;
	}
	void render();
	void clear();
	void present();

private:
	SDL_Renderer* renderer; ///< The SDL_Renderer instance.
	SDL_Window* window; ///< The SDL_Window instance.
	uint16_t windowWidth;
	uint16_t windowHeight;
};