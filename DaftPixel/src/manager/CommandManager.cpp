#include "manager/CommandManager.h"

CommandManager::CommandManager(Canvas::RenderContext& renderContext) : renderContext(renderContext) {}

void CommandManager::executeCommand(Action action, InputManager& inputManager, const SDL_Event& event, Canvas::Controller::SurfaceController surfaceController, Canvas::RenderContext& renderContext) {
    switch (action) {
    case Action::IncreaseScaleFactor:
        renderContext.changeScaleFactor(static_cast<int8_t>(1));
        break;
    case Action::DecreaseScaleFactor:
        renderContext.changeScaleFactor(static_cast<int8_t>(-1));
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
    case Action::None:
        // No action to be taken
        break;
        // Future actions
    }


	// Mark the action as handled in the input manager
	inputManager.markActionAsHandled(action);
}
