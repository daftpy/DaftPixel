#include "view/canvas/ui/StatusBar.h"

// Define padding constants
const int INNER_PADDING = 8;
const int OUTER_PADDING = 16;


Canvas::Ui::StatusBar::StatusBar(Canvas::RenderContext& renderContext, int32_t& width, int32_t& height) :
    renderContext(renderContext), statusBarWidth(width), statusBarHeight(height) {

    // Ensure initialization
    if (&statusBarWidth == nullptr || &statusBarHeight == nullptr) {
        throw std::invalid_argument("Width and height must be initialized.");
    }

    // Set up the canvasDimensions widget
    canvasDimensionsWidget.setName("Canvas");
    canvasDimensionsWidget.padding = INNER_PADDING;

    // Set up the scaleFactor widget
    scaleFactorWidget.setName("Scale Factor");
    scaleFactorWidget.padding = INNER_PADDING;

    // Set initial texture to nullptr
    statusBarTexture = nullptr;
}

void Canvas::Ui::StatusBar::render(SDL_Renderer* renderer) const {
    std::cout << "statusbar render" << std::endl;
    if (statusBarTexture) {
        int textWidth, textHeight;
        if (SDL_QueryTexture(statusBarTexture, NULL, NULL, &textWidth, &textHeight) != 0) {
            std::cerr << "SDL_QueryTexture: " << SDL_GetError() << std::endl;
        }
        SDL_Rect dstrect = { (statusBarWidth - textWidth) - INNER_PADDING, (statusBarHeight - textHeight) - INNER_PADDING, textWidth, textHeight };

        SDL_SetRenderDrawColor(renderer, 131, 156, 166, 255);

        SDL_Rect statusBarBackground = { 0, (statusBarHeight - textHeight) - OUTER_PADDING, statusBarWidth, textHeight + OUTER_PADDING };

        SDL_RenderFillRect(renderer, &statusBarBackground);
        SDL_RenderCopy(renderer, statusBarTexture, NULL, &dstrect);
    }
}

void Canvas::Ui::StatusBar::updateWidget(InfoWidget& widget, const std::string& data) {
    widget.widgetData = data;
}

void Canvas::Ui::StatusBar::updateWidgets(SDL_Renderer* renderer) {
    std::cout << "updateWidgets: scaleFactor: " << std::to_string(renderContext.scaleFactor) << std::endl;
    updateWidget(canvasDimensionsWidget, std::to_string(renderContext.canvasSurface.getWidth()) + " x " + std::to_string(renderContext.canvasSurface.getHeight()));
    updateWidget(scaleFactorWidget, "x" + std::to_string(renderContext.scaleFactor));
}

void Canvas::Ui::StatusBar::updateTexture(SDL_Renderer* renderer) {
    std::cout << "Updated texture" << std::endl;
    std::ostringstream canvasSizeStream;
    canvasSizeStream << scaleFactorWidget.widgetName << scaleFactorWidget.widgetData << " " << canvasDimensionsWidget.widgetName << canvasDimensionsWidget.widgetData;
    std::string canvasSize = canvasSizeStream.str();

    SDL_Color color = { 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(renderContext.font, canvasSize.c_str(), color);

    if (surface) {
        if (statusBarTexture) {
            SDL_DestroyTexture(statusBarTexture);
        }

        statusBarTexture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!statusBarTexture) {
            std::cerr << "SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface(surface);
    }
    else {
        std::cerr << "TTF_RenderText_Solid: " << TTF_GetError() << std::endl;
    }
}
