#include "view/canvas/ui/StatusBar.h"

/**
 * @brief Constructor for StatusBar class
 *
 * @param renderContext Reference to the render context.
 */
Canvas::Gui::StatusBar::StatusBar(Canvas::RenderContext& renderContext) :
    renderContext(renderContext) {

    // Set up the canvasDimensions widget
    canvasDimensionsWidget.setName("Canvas");
    canvasDimensionsWidget.widgetData = std::to_string(renderContext.canvasSurface.getWidth()) + " x " + std::to_string(renderContext.canvasSurface.getHeight());
    canvasDimensionsWidget.padding = 8;

    // Set up the scaleFactor widget
    scaleFactorWidget.setName("Scale Factor");
    scaleFactorWidget.widgetData = "x" + std::to_string(renderContext.scaleFactor);
    scaleFactorWidget.padding = 8;

    // Set initial texture to nullptr
    statusBarTexture = nullptr;
}

/**
 * @brief Render the status bar
 *
 * Renders the status bar using the status bar texture.
 *
 * @param renderer SDL_Renderer used for rendering.
 */
void Canvas::Gui::StatusBar::render(SDL_Renderer* renderer) const {
    if (statusBarTexture) {
        // The position on the screen to render the text
        int textWidth, textHeight;
        if (SDL_QueryTexture(statusBarTexture, NULL, NULL, &textWidth, &textHeight) != 0) {
            std::cerr << "SDL_QueryTexture: " << SDL_GetError() << std::endl;
        }
        SDL_Rect dstrect = { (renderContext.windowWidth - textWidth) - 8, (renderContext.windowHeight - textHeight) - 8, textWidth, textHeight };

        // Render the texture on the screen
        SDL_RenderCopy(renderer, statusBarTexture, NULL, &dstrect);
    }
    else {
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
}

/**
 * @brief Update the status bar widgets
 *
 * Updates the status bar widget data.
 */
void Canvas::Gui::StatusBar::updateWidgets(SDL_Renderer* renderer) {
    // Update the widget data
    canvasDimensionsWidget.widgetData = std::to_string(renderContext.canvasSurface.getWidth()) + " x " + std::to_string(renderContext.canvasSurface.getHeight());
    scaleFactorWidget.widgetData = "x" + std::to_string(renderContext.scaleFactor);
}

/**
 * @brief Update the status bar texture
 *
 * Creates a new texture using the updated widget data.
 *
 * @param renderer SDL_Renderer used for creating the texture.
 */
void Canvas::Gui::StatusBar::updateTexture(SDL_Renderer* renderer) {
    std::cout << "Updated texture" << std::endl;
    // Update the texture
    std::string canvasSize = scaleFactorWidget.widgetName + scaleFactorWidget.widgetData + " " + canvasDimensionsWidget.widgetName + canvasDimensionsWidget.widgetData;

    // The color of the text
    SDL_Color color = { 255, 255, 255 };  // white

    // Create an SDL_Surface with the text
    SDL_Surface* surface = TTF_RenderText_Solid(renderContext.font, canvasSize.c_str(), color);

    // Clean up the old texture, if it exists
    if (statusBarTexture) {
        SDL_DestroyTexture(statusBarTexture);
        statusBarTexture = nullptr;
    }

    // Create an SDL_Texture from the SDL_Surface
    statusBarTexture = SDL_CreateTextureFromSurface(renderer, surface);

    // Clean up
    SDL_FreeSurface(surface);
}
