#include "controller/EditorController.h"
#include <memory>
#include "view/canvas/CanvasSurfaceView.h"

EditorController::EditorController() : editorName("DaftPixel"), running(false) {
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
	CanvasSurfaceController surfaceController(*canvases.front());
	std::shared_ptr<CanvasSurfaceView> canvasRenderer = std::make_shared<CanvasSurfaceView>(*canvases.front(), font, renderManager);
	CanvasRendererController crController(*canvasRenderer);
	crController.changeScaleFactor(9);
	renderManager.addDrawable(canvasRenderer);
};

EditorController::~EditorController() {
	// Cleanup
	TTF_CloseFont(font);
	font = nullptr;

	TTF_Quit();
}

void EditorController::createNewCanvas(uint16_t width, uint16_t height) {
	// Create the new Canvas
	std::unique_ptr<CanvasSurface> newCanvas = std::make_unique<CanvasSurface>(width, height);

	// Add the new Canvas to the list of canvases
	canvases.push_back(std::move(newCanvas));
}

void EditorController::handleEvents() {
	SDL_Event event;

	// Process SDL events.
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
	}
}

void EditorController::run() {
	// Run the main editor loop.
	running = true;
	while (running) {
		handleEvents();
		renderManager.clear();
		renderManager.render();
		renderManager.present();
	}
}
