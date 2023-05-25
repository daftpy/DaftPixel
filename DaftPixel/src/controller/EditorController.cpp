#include "controller/EditorController.h"
#include <memory>
#include "view/CanvasRenderer.h"

EditorController::EditorController() : editorName("DaftPixel"), running(false), canvas(nullptr) {
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

	/*canvas = std::make_shared<Canvas>(800, 600, font, renderManager);*/
	/*renderManager.addDrawable(canvas);*/

	std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>(800, 600);

	std::shared_ptr<CanvasRenderer> canvasRenderer = std::make_shared<CanvasRenderer>(canvas, font);

	renderManager.addDrawable(canvasRenderer);

	/*
		Debug code below
	*/
	std::cout << "EditorController initialized." << std::endl;
	Pixel p1;
	Pixel p2(200, 180, 180, 255);
	std::cout << p1 << std::endl;
	PixelBuffer pixelBuffer(32, 32, p2);
	std::cout << pixelBuffer.at(1, 1);
};

EditorController::~EditorController() {
	// Cleanup
	TTF_CloseFont(font);
	font = nullptr;

	TTF_Quit();
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
