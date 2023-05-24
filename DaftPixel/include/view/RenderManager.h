#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include "IDrawable.h"

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
	void addDrawable(std::shared_ptr<IDrawable> drawable);

private:
	SDL_Renderer* renderer; ///< The SDL_Renderer instance.
	SDL_Window* window; ///< The SDL_Window instance.
	uint16_t windowWidth;
	uint16_t windowHeight;
	std::vector<std::shared_ptr<IDrawable>> drawables;
};