#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <memory> // for std::unique_ptr
#include "view/RenderManager.h"
#include "view/Canvas.h"
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
	std::shared_ptr<Canvas> canvas;  // here is your smart pointer
	RenderManager renderManager;
	TTF_Font* font;
};
