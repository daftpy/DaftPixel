#include "view/canvas/ui/StatusBar.h"

Canvas::Gui::StatusBar::StatusBar(Canvas::RenderContext& renderContext) :
    renderContext(renderContext) {

    // Set up the canvasDimensions widget
    canvasDimensionsWidget.setName("Canvas");
    canvasDimensionsWidget.widgetData = std::to_string(renderContext.canvasSurface.getWidth()) + " x " + std::to_string(renderContext.canvasSurface.getHeight());
    canvasDimensionsWidget.padding = 8;


    // Set up the scaleFactor widget
    std::string scaleFactor = "Scale Factor: x" + std::to_string(renderContext.scaleFactor);
    scaleFactorWidget.setName("Scale Factor");
    scaleFactorWidget.widgetData = "x" + std::to_string(renderContext.scaleFactor);
    scaleFactorWidget.padding = 8;
    
}

void Canvas::Gui::StatusBar::render(SDL_Renderer* renderer) const {
    std::string canvasSize = scaleFactorWidget.widgetName + scaleFactorWidget.widgetData + " " + canvasDimensionsWidget.widgetName + canvasDimensionsWidget.widgetData;
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

void Canvas::Gui::StatusBar::updateWidgets() {
    canvasDimensionsWidget.widgetData = std::to_string(renderContext.canvasSurface.getWidth()) + " x " + std::to_string(renderContext.canvasSurface.getHeight());
    scaleFactorWidget.widgetData = "x" + std::to_string(renderContext.scaleFactor);
}