#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "view/RenderManager.h"
#include "view/IDrawable.h"

class CanvasStatusBar : public IDrawable {
public:
	CanvasStatusBar(TTF_Font* font) : font(font) {}
	~CanvasStatusBar() {}
	void render(SDL_Renderer* renderer) const override {
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
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        // The position on the screen to render the text
        SDL_Rect dstrect = { 10, 10, textWidth, textHeight };  // replace with appropriate values

        // Render the texture on the screen
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        // Clean up
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
	}

private:
	TTF_Font* font;
};