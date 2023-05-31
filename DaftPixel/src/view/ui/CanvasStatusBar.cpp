#include "view/ui/CanvasStatusBar.h"

void CanvasStatusBar::render(SDL_Renderer* renderer) const {
    std::string canvasSize = std::to_string(canvas.getWidth()) + " x " + std::to_string(canvas.getHeight());

    int textWidth, textHeight;
    if (TTF_SizeText(font, canvasSize.c_str(), &textWidth, &textHeight) != 0) {
        std::cerr << "TTF_SizeText: " << TTF_GetError() << std::endl;
    }

    // The color of the text
    SDL_Color color = { 255, 255, 255 };  // white

    // Create an SDL_Surface with the text
    SDL_Surface* surface = TTF_RenderText_Solid(font, canvasSize.c_str(), color);

    // Create an SDL_Texture from the SDL_Surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // The position on the screen to render the text
    SDL_Rect dstrect = { 10, 10, textWidth, textHeight };

    // Render the texture on the screen
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    // Clean up
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}