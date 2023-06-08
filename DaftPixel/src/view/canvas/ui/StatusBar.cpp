#include "view/canvas/ui/StatusBar.h"

void Canvas::Gui::StatusBar::render(SDL_Renderer* renderer) const {
    std::string canvasSize = "Scale Factor: x" + std::to_string(renderContext.scaleFactor);
    canvasSize += "   Canvas: ";
    canvasSize += std::to_string(renderContext.canvasSurface.getWidth());
    canvasSize += " x ";
    canvasSize += std::to_string(renderContext.canvasSurface.getHeight());

    int textWidth, textHeight;
    if (TTF_SizeText(renderContext.font, canvasSize.c_str(), &textWidth, &textHeight) != 0) {
        std::cerr << "TTF_SizeText: " << TTF_GetError() << std::endl;
    }

    // The color of the text
    SDL_Color color = { 255, 255, 255 };  // white

    // Create an SDL_Surface with the text
    SDL_Surface* surface = TTF_RenderText_Solid(renderContext.font, canvasSize.c_str(), color);

    // Create an SDL_Texture from the SDL_Surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // The position on the screen to render the text
    SDL_Rect dstrect = { (renderContext.windowWidth - textWidth) - 8, (renderContext.windowHeight - textHeight) - 8, textWidth, textHeight };

    // Render the texture on the screen
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    // Clean up
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}