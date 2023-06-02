#include "view/canvas/CanvasSurfaceView.h"
#include <iostream>

/**
* @brief Constructs a new CanvasSurfaceView instance with a reference to a Canvas and a TTF_Font.
*
* @param canvasSurface Reference to a CanvasSurface instance.
* @param font TTF_Font used for rendering.
*/
CanvasSurfaceView::CanvasSurfaceView(CanvasSurface& canvasSurface, TTF_Font* font, Canvas::RenderContext& renderContext) :
    canvasSurface(canvasSurface), statusBar(font, canvasSurface, renderContext), font(font), renderContext(renderContext), scaleFactor(1) {}

/**
* @brief Renders the CanvasSurface using the provided SDL_Renderer.
*
* @param renderer SDL_Renderer used for rendering.
*/
void CanvasSurfaceView::render(SDL_Renderer* renderer) const {
    statusBar.render(renderer);

    auto& pixelBuffer = canvasSurface.getPixelBuffer();

    int windowWidth, windowHeight;
    SDL_GetWindowSize(renderContext.renderManager.getWindow(), &windowWidth, &windowHeight);

    // Calculate the starting point to render the PixelBuffer centered
    int startX = (windowWidth - pixelBuffer.getWidth() * renderContext.scaleFactor) / 2;
    int startY = (windowHeight - pixelBuffer.getHeight() * renderContext.scaleFactor) / 2;

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