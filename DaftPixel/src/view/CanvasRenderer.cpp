#include "view/CanvasRenderer.h"

/**
* @brief Constructs a new CanvasRenderer instance with a reference to a Canvas and a TTF_Font.
*
* @param canvas Reference to a Canvas instance.
* @param font TTF_Font used for rendering.
*/
CanvasRenderer::CanvasRenderer(Canvas& canvas, TTF_Font* font, RenderManager& renderManager) :
    canvas(canvas), statusBar(font, canvas, renderManager), font(font), renderManager(renderManager), scaleFactor(1) {}

/**
* @brief Renders the Canvas using the provided SDL_Renderer.
*
* @param renderer SDL_Renderer used for rendering.
*/
void CanvasRenderer::render(SDL_Renderer* renderer) const {
    statusBar.render(renderer);

    auto& pixelBuffer = canvas.getPixelBuffer();

    int windowWidth, windowHeight;
    SDL_GetWindowSize(renderManager.getWindow(), &windowWidth, &windowHeight);

    // Calculate the starting point to render the PixelBuffer centered
    int startX = (windowWidth - pixelBuffer.getWidth() * scaleFactor) / 2;
    int startY = (windowHeight - pixelBuffer.getHeight() * scaleFactor) / 2;

    for (uint16_t y = 0; y < pixelBuffer.getHeight(); y++) {
        for (uint16_t x = 0; x < pixelBuffer.getWidth(); x++) {
            Pixel pixel = pixelBuffer.at(x, y);

            // Create the SDL_Rect for the pixel
            SDL_Rect rect;
            rect.x = startX + x * scaleFactor;
            rect.y = startY + y * scaleFactor;
            rect.w = scaleFactor;
            rect.h = scaleFactor;

            // Set the draw color to the pixel's color
            SDL_SetRenderDrawColor(renderer, pixel.getRed(), pixel.getGreen(), pixel.getBlue(), pixel.getAlpha());

            // Draw the pixel
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}