#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "view/RenderManager.h"

class CanvasStatusBar {
public:
	CanvasStatusBar(TTF_Font* font, RenderManager& renderManager) : font(font), renderManager(renderManager) {}
	~CanvasStatusBar() {}
	void render() const {
        std::string canvasSize = "Hello, World!";

        int textWidth, textHeight;
        if (TTF_SizeText(font, canvasSize.c_str(), &textWidth, &textHeight) != 0) {
            std::cerr << "TTF_SizeText: " << TTF_GetError() << std::endl;
        }

        // The color of the text
        SDL_Color color = { 255, 255, 255 };  // white

        // Create an SDL_Surface with the text
        SDL_Surface* surface = TTF_RenderText_Solid(font, "Hello, world!", color);

        // Create an SDL_Texture from the SDL_Surface
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderManager.getRenderer(), surface);

        // The position on the screen to render the text
        SDL_Rect dstrect = { 500, 400, textWidth, textHeight };  // replace with appropriate values

        // Render the texture on the screen
        SDL_RenderCopy(renderManager.getRenderer(), texture, NULL, &dstrect);

        // Clean up
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
	}

private:
	TTF_Font* font;
	RenderManager& renderManager;
};