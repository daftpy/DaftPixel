#include "view/canvas/ui/StatusBar.h"

/**
 * @brief Constructor for StatusBar class
 *
 * @param renderContext Reference to the render context.
 */
Canvas::Ui::StatusBar::StatusBar(Canvas::RenderContext& renderContext) :
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
void Canvas::Ui::StatusBar::render(SDL_Renderer* renderer) const {
    std::cout << "statusbar render" << std::endl;
    if (statusBarTexture) {
        std::cout << "texture found" << std::endl;
        // The position on the screen to render the text
        int textWidth, textHeight;
        if (SDL_QueryTexture(statusBarTexture, NULL, NULL, &textWidth, &textHeight) != 0) {
            std::cerr << "SDL_QueryTexture: " << SDL_GetError() << std::endl;
        }
        SDL_Rect dstrect = { (renderContext.windowWidth - textWidth) - 8, (renderContext.windowHeight - textHeight) - 8, textWidth, textHeight };

        // Render the texture on the screen
        SDL_RenderCopy(renderer, statusBarTexture, NULL, &dstrect);
    }
}

/**
 * @brief Update the status bar widgets
 *
 * Updates the status bar widget data.
 */
void Canvas::Ui::StatusBar::updateWidgets(SDL_Renderer* renderer) {
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
void Canvas::Ui::StatusBar::updateTexture(SDL_Renderer* renderer) {
    std::cout << "Updated texture" << std::endl;
    // Update the texture
    std::string canvasSize = scaleFactorWidget.widgetName + scaleFactorWidget.widgetData + " " + canvasDimensionsWidget.widgetName + canvasDimensionsWidget.widgetData;

    // The color of the text
    SDL_Color color = { 255, 255, 255 };  // white

    // Create an SDL_Surface with the text
    SDL_Surface* surface = TTF_RenderText_Solid(renderContext.font, canvasSize.c_str(), color);
    if (surface == nullptr) {
        std::cerr << "TTF_RenderText_Solid: " << TTF_GetError() << std::endl;
    }
    else {
        // Clean up the old texture, if it exists
        if (statusBarTexture) {
            SDL_DestroyTexture(statusBarTexture);
        }

        // Create an SDL_Texture from the SDL_Surface
        statusBarTexture = SDL_CreateTextureFromSurface(renderer, surface);
        if (statusBarTexture == nullptr) {
            std::cerr << "SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
        }

        // Clean up
        SDL_FreeSurface(surface);
    }
}
