#include "view/canvas/SurfaceView.h"
#include <iostream>

/**
* @brief Constructs a new CanvasSurfaceView instance with a reference to a Canvas and a TTF_Font.
*
* @param renderContext reference to RenderContext instance is responsible for maintaining
* display characteristics for the CanvasSurfaceView such as scale factor, positioning, etc.
*/
Canvas::View::SurfaceView::SurfaceView(Canvas::RenderContext& renderContext) :
    renderContext(renderContext), canvasTexture(nullptr) {
}

Canvas::View::SurfaceView::~SurfaceView() {
    SDL_DestroyTexture(canvasTexture);
}

/**
* @brief Renders the CanvasSurface using the provided SDL_Renderer.
*
* @param renderer SDL_Renderer used for rendering.
*/
void Canvas::View::SurfaceView::render(SDL_Renderer* renderer) const {
    auto& pixelBuffer = renderContext.canvasSurface.getPixelBuffer();

    // Lock texture for update
    void* mPixels;
    int mPitch;
    SDL_LockTexture(canvasTexture, NULL, &mPixels, &mPitch);

    // Get the address of the first pixel in the pixelBuffer
    const uint32_t* pixelBufferData = pixelBuffer.getPixelData();

    // Copy the entire pixel buffer data to mPixels
    memcpy(mPixels, pixelBufferData, pixelBuffer.getWidth() * pixelBuffer.getHeight() * sizeof(uint32_t));

    // Unlock texture
    SDL_UnlockTexture(canvasTexture);

    // Calculate the starting point to render the texture centered
    int startX = (renderContext.windowWidth - pixelBuffer.getWidth() * renderContext.scaleFactor) / 2;
    int startY = (renderContext.windowHeight - pixelBuffer.getHeight() * renderContext.scaleFactor) / 2;

    std::cout << "WINDOW WIDTH: " << std::to_string(renderContext.windowWidth);
    std::cout << "START X: " << std::to_string(startX) << " START Y: " << std::to_string(startY) << std::endl;

    // Define the rendering quad with respect to scale factor
    SDL_Rect renderQuad = {
        startX,
        startY,
        pixelBuffer.getWidth() * renderContext.scaleFactor,
        pixelBuffer.getHeight() * renderContext.scaleFactor
    };

    // Render the updated texture
    SDL_RenderCopy(renderer, canvasTexture, NULL, &renderQuad);
}


void Canvas::View::SurfaceView::setupTexture(SDL_Renderer* renderer) {
    // Access the pixelBuffer width and height
    auto& pixelBuffer = renderContext.canvasSurface.getPixelBuffer();
    int width = pixelBuffer.getWidth();
    int height = pixelBuffer.getHeight();

    // Create a texture of the same dimensions as the pixelBuffer
    canvasTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    // Set the blend mode of the texture to allow for transparent pixels
    SDL_SetTextureBlendMode(canvasTexture, SDL_BLENDMODE_BLEND);

    // Note: Add error handling here. SDL_CreateTexture could fail and return nullptr.
}
