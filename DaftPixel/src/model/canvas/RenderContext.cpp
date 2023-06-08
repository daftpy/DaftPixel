#include "model/canvas/RenderContext.h"

void Canvas::RenderContext::updateWindowSize(int newWidth, int newHeight) {
    windowWidth = newWidth;
    windowHeight = newHeight;
}

void Canvas::RenderContext::changeScaleFactor(int8_t delta) {
    int8_t newScaleFactor = scaleFactor + delta;
    try {
        if (newScaleFactor <= 0) {
            throw std::out_of_range("Scale factor must be greater than 0.");
        }
    }
    catch (const std::out_of_range& e) {
        // Handle the exception (e.g., log an error message)
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    scaleFactor = newScaleFactor;
}

int Canvas::RenderContext::getCanvasStartX() const {
    return (windowWidth - canvasSurface.getWidth() * scaleFactor) / 2;
}

int Canvas::RenderContext::getCanvasStartY() const {
    return (windowHeight - canvasSurface.getHeight() * scaleFactor) / 2;
}