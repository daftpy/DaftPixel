#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include "view/RenderManager.h"
#include "model/Canvas.h"
#include "model/PixelBuffer.h"
#include "model/Pixel.h"

class EditorController {
public:
	EditorController();
	~EditorController();
	void run();
	void handleEvents();

private:
	std::string editorName;
	bool running;
	std::shared_ptr<Canvas> canvas;
	RenderManager renderManager;
	TTF_Font* font;
};
