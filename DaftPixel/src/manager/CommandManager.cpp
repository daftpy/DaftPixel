#include "manager/CommandManager.h"

CommandManager::CommandManager(
    Canvas::RenderContext& renderContext, InputManager& inputManager, Canvas::Controller::SurfaceController& surfaceController
) : renderContext(renderContext), inputManager(inputManager), surfaceController(surfaceController) {}

void CommandManager::executeCommand(Action action, const SDL_Event& event) {
    auto canvasCoords = surfaceController.pointerToCanvasCoords(
        event.motion.x, event.motion.y, renderContext.scaleFactor, renderContext.getCanvasStartX(), renderContext.getCanvasStartY()
    );
    switch (action) {
    case Action::IncreaseScaleFactor:
        renderContext.changeScaleFactor(static_cast<int8_t>(1));
        // Mark the action as handled in the input manager
        inputManager.markActionAsHandled(action);
        break;
    case Action::DecreaseScaleFactor:
        renderContext.changeScaleFactor(static_cast<int8_t>(-1));
        // Mark the action as handled in the input manager
        inputManager.markActionAsHandled(action);
        break;
    case Action::PaintPixel:
    {
        std::cout << "Painting pixel command" << std::endl;
        // Get the new mouse position.
        int mouseX = event.motion.x;
        int mouseY = event.motion.y;

        // Convert mouse coordinates to canvas coordinates
        auto canvasCoords = surfaceController.pointerToCanvasCoords(mouseX, mouseY, renderContext.scaleFactor, renderContext.getCanvasStartX(), renderContext.getCanvasStartY());

        // If the mouse is within the canvas
        if (canvasCoords.has_value()) {
            // Set the pixel at the mouse position
            Pixel pixel(255, 0, 0, 255); // Red pixel
            surfaceController.setPixel(canvasCoords->first, canvasCoords->second, pixel);
            std::cout << "PIXEL SET" << std::endl;
        }
        break;
    }
    case Action::SelectPixel:
        std::cout << "Selecting?" << std::endl;
        if (canvasCoords.has_value()) {
            // Get the pixel at the mouse position
            Pixel pixelAtMousePosition = surfaceController.getPixel(canvasCoords->first, canvasCoords->second);

            inputManager.setCurrentPixel(pixelAtMousePosition);
        }
        // Mark the action as handled in the input manager
        inputManager.markActionAsHandled(action);
        break;
    case Action::None:
        // No action to be taken
        break;
        // Future actions
    }
}
