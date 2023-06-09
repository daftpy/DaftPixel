#include "view/canvas/SurfaceView.h"
#include <iostream>

/**
* @brief Constructs a new CanvasSurfaceView instance with a reference to a Canvas and a TTF_Font.
*
* @param renderContext reference to RenderContext instance is responsible for maintaining
* display characteristics for the CanvasSurfaceView such as scale factor, positioning, etc.
*/
Canvas::View::SurfaceView::SurfaceView(Canvas::RenderContext& renderContext) :
    statusBar(renderContext), renderContext(renderContext) {}

/**
* @brief Renders the CanvasSurface using the provided SDL_Renderer.
*
* @param renderer SDL_Renderer used for rendering.
*/
void Canvas::View::SurfaceView::render(SDL_Renderer* renderer) const {
    statusBar.render(renderer);

    auto& pixelBuffer = renderContext.canvasSurface.getPixelBuffer();

    // Calculate the starting point to render the PixelBuffer centered
    int startX = (renderContext.windowWidth - pixelBuffer.getWidth() * renderContext.scaleFactor) / 2;
    int startY = (renderContext.windowHeight - pixelBuffer.getHeight() * renderContext.scaleFactor) / 2;

    for (uint16_t y = 0; y < pixelBuffer.getHeight(); y++) {
        for (uint16_t x = 0; x < pixelBuffer.getWidth(); x++) {
            Pixel pixel = pixelBuffer.at(x, y);

            // Create the SDL_Rect for the pixel
            SDL_Rect rect;
            rect.x = startX + x * renderContext.scaleFactor;
            rect.y = startY + y * renderContext.scaleFactor;
            rect.w = renderContext.scaleFactor;
            rect.h = renderContext.scaleFactor;

            // Set the draw color to the pixel's color
            SDL_SetRenderDrawColor(renderer, pixel.getRed(), pixel.getGreen(), pixel.getBlue(), pixel.getAlpha());

            // Draw the pixel
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void Canvas::View::SurfaceView::updateWidgets(SDL_Renderer* renderer) {
    statusBar.updateWidgets(renderer);
    statusBar.updateTexture(renderer);
}