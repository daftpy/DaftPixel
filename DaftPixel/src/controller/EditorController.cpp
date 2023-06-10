#include "controller/EditorController.h"
#include <memory>

EditorController::EditorController() : editorName("DaftPixel"), running(false), renderContext(nullptr) {
	// Initialize SDL_ttf library
	if (TTF_Init() == -1) {
		std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
		// handle error
	}

	// Load font
	font = TTF_OpenFont("monogram.ttf", 16); // replace with your font file path and desired font size
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
		// handle error
	}

	KeyBinding deacreaseKeyBinding(SDLK_MINUS, KMOD_NONE, Action::DecreaseScaleFactor);
	KeyBinding increaseKeyBinding(SDLK_EQUALS, KMOD_NONE, Action::IncreaseScaleFactor);
	MouseBinding paintPixelMouseBinding(SDL_MOUSEBUTTONDOWN, KMOD_NONE, Action::PaintPixel);

	// Add actions to handle
	for (int i = 0; i < static_cast<int>(Action::None); ++i) {
		actions.push_back(static_cast<Action>(i));
	}

	// Initialize BindingManager and bind keys to actions
	bindingManager.addKeyBinding(increaseKeyBinding);
	bindingManager.addKeyBinding(deacreaseKeyBinding);
	bindingManager.addMouseButtonBinding(paintPixelMouseBinding);

	inputManager = std::make_unique<InputManager>(bindingManager);

	/*
		Debug code below
	*/
	std::cout << "EditorController initialized." << std::endl;
	Pixel p1;
	Pixel p2(200, 180, 180, 255);
	std::cout << p1 << std::endl;
	PixelBuffer pixelBuffer(32, 32, p2);
	std::cout << pixelBuffer.at(1, 1);

	// More debug code
	createNewCanvas(32, 32);
	canvases.front()->getPixelBuffer().generateRandomPixels(); // only used for testing
	surfaceController = std::make_unique<Canvas::Controller::SurfaceController>(*canvases.front());

	// Still debug code
	renderContext = std::make_unique< Canvas::RenderContext>(*canvases.front(), font, 1, renderManager.getWindow());

	commandManager = std::make_unique<CommandManager>(*renderContext);

	std::shared_ptr<Canvas::View::SurfaceView> canvasRenderer = std::make_shared<Canvas::View::SurfaceView>(*renderContext);
	surfaceView = canvasRenderer;

	renderManager.addDrawable(canvasRenderer);

	surfaceView->updateWidgets(renderManager.getRenderer());
};

EditorController::~EditorController() {
	// Cleanup
	TTF_CloseFont(font);
	font = nullptr;

	TTF_Quit();
}

#ifdef TESTING
void EditorController::_testPrintMouseCoords(SDL_Event& event) const {
	// Get the new mouse position.
	int mouseX = event.motion.x;
	int mouseY = event.motion.y;

	// Convert mouse coordinates to canvas coordinates
	auto canvasCoords = surfaceController->pointerToCanvasCoords(mouseX, mouseY, renderContext->scaleFactor, renderContext->getCanvasStartX(), renderContext->getCanvasStartY());

	// If the mouse is within the canvas
	if (canvasCoords.has_value()) {
		// Get the pixel at the mouse position
		Pixel pixelAtMousePosition = surfaceController->getPixel(canvasCoords->first, canvasCoords->second);

		// Print the pixel at mouse position
		std::cout << "Pixel at mouse position: " << pixelAtMousePosition << "\n";
	}
}
#endif

void EditorController::createNewCanvas(uint16_t width, uint16_t height) {
	// Create the new Canvas
	std::unique_ptr<Canvas::Surface> newCanvas = std::make_unique<Canvas::Surface>(width, height);

	// Add the new Canvas to the list of canvases
	canvases.push_back(std::move(newCanvas));
}

// TEMPORARY DEBUG CODE
// TODO: InputManager
void EditorController::handleEvents() {
	SDL_Event event;

	// Process SDL events.
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		else if (event.type == SDL_MOUSEMOTION) {
			#ifdef TESTING
			_testPrintMouseCoords(event);
			#endif
			// Check if the left mouse button (button 1) is being held down.
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
				// Perform the painting operation...
				commandManager->executeCommand(Action::PaintPixel, *inputManager, event, *surfaceController, *renderContext);
				surfaceView->updateWidgets(renderManager.getRenderer()); // Update widgets when an action is triggered

				renderManager.clear();
				renderManager.render();
				renderManager.present();
			}
		}
		else if (event.type == SDL_WINDOWEVENT) {
			if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
				// handle window resize event...
				renderContext->updateWindowSize(event.window.data1, event.window.data2);

				renderManager.clear();
				renderManager.render();
				renderManager.present();
			}
		}
		else {
			// Pass the event to the InputManager
			inputManager->handleEvent(event);

			// Process actions
			processActions(event);
		}
	}
}


void EditorController::processActions(const SDL_Event& event) {
	for (auto action : actions) {
		if (inputManager->isActionTriggered(action)) {
			commandManager->executeCommand(action, *inputManager, event, *surfaceController, *renderContext);
			surfaceView->updateWidgets(renderManager.getRenderer()); // Update widgets when an action is triggered

			renderManager.clear();
			renderManager.render();
			renderManager.present();
		}
	}
}

void EditorController::run() {
	// Run the main editor loop.
	running = true;

	// Initial rendering draw
	renderManager.clear();
	renderManager.render();
	renderManager.present();

	while (running) {
		handleEvents();
	}
}
