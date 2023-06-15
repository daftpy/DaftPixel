#include "application.h"

Application::Application() :
	m_renderManager(800, 600),  // Initialize RenderManager with initial window size
	m_inputManager(m_bindingManager),  // Initialize InputManager with a reference to the BindingManager
	m_editorContext(m_renderManager, m_inputManager),  // Initialize EditorContext with references to RenderManager and InputManager
	m_editorController(m_editorContext) {  // Initialize EditorController with a reference to the EditorContext

	// Generate a random pixel pattern for the initial CanvasSurface
	m_editorContext.getCanvasSurface().getPixelBuffer().generateRandomPixels();

	// Register the CanvasLayout as a drawable entity in the RenderManager
	m_renderManager.addDrawable(m_editorContext.getCanvasLayout());

	// Add the CanvasLayout to the RenderManager's list of layouts to manage
	m_renderManager.addLayout(m_editorContext.getCanvasLayout());

	// Generate a list of all possible actions for use in the application
	for (int i = 0; i < static_cast<int>(Action::None); ++i) {
		actions.push_back(static_cast<Action>(i));
	}

	// Define key bindings for zooming in and out
	KeyBinding deacreaseKeyBinding(SDLK_MINUS, KMOD_NONE, Action::DecreaseScaleFactor);
	KeyBinding increaseKeyBinding(SDLK_EQUALS, KMOD_NONE, Action::IncreaseScaleFactor);

	// Define mouse button bindings for painting and selecting pixels
	MouseBinding paintPixelMouseBinding(SDL_MOUSEBUTTONDOWN, SDL_BUTTON_LEFT, KMOD_NONE, Action::PaintPixel);
	MouseBinding stopPaintPixelMouseBinding(SDL_MOUSEBUTTONUP, SDL_BUTTON_LEFT, KMOD_NONE, Action::PaintPixel);
	MouseBinding selectPixelMouseBinding(SDL_MOUSEBUTTONDOWN, SDL_BUTTON_RIGHT, KMOD_NONE, Action::SelectPixel);

	// Register the defined key bindings in the BindingManager
	m_bindingManager.addKeyBinding(deacreaseKeyBinding);
	m_bindingManager.addKeyBinding(increaseKeyBinding);

	// Register the defined mouse button bindings in the BindingManager
	m_bindingManager.addMouseButtonBinding(paintPixelMouseBinding);
	m_bindingManager.addMouseButtonBinding(stopPaintPixelMouseBinding);
	m_bindingManager.addMouseButtonBinding(selectPixelMouseBinding);

	// Update the positions and sizes of the layouts in the RenderManager
	m_renderManager.updateLayouts();

	// Setup the initial texture for the SurfaceView
	m_editorContext.getCanvasLayout()->getSurfaceView().setupTexture(m_renderManager.getRenderer());
}

void Application::processActions(const SDL_Event& event) {
	for (auto action : actions) {  // Loop over all possible actions
		if (m_inputManager.isActionTriggered(action)) {  // If a corresponding action is triggered by the user
			m_editorContext.getCommandManager().executeCommand(action, event);  // Execute the command associated with the action

			// Log the action and the current pixel being modified
			std::cout << "ACTION TRIGGERED. CURRENT PIXEL: " << m_editorContext.getCurrentPixel() << std::endl;

			// Render the updated state of the Editor
			m_renderManager.clear();
			m_renderManager.render();
			m_renderManager.present();
		}
	}
}

void Application::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {  // Process all pending SDL events
		if (event.type == SDL_QUIT) {  // If the SDL_QUIT event is polled, stop running the Editor
			m_running = false;
		}
		// If window is resized, maximized, or render targets are reset
		else if (
			(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) ||
			(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_MAXIMIZED) ||
			(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) ||
			(event.type == SDL_RENDER_TARGETS_RESET))
		{
			std::cout << "WINDOW RESIZE" << std::endl;

			int windowWidth, windowHeight;
			SDL_GetWindowSize(m_renderManager.getWindow(), &windowWidth, &windowHeight);

			// Update the window size in the RenderContext and redraw the CanvasLayout
			m_editorContext.getRenderContext().updateWindowSize(windowWidth, windowHeight);

			// Render the updated state of the Editor
			m_renderManager.clear();
			// Recreate the texture to match the new window size
			m_editorContext.getCanvasLayout()->getSurfaceView().setupTexture(m_renderManager.getRenderer());
			m_renderManager.render();
			m_renderManager.present();
		}

		// Pass the SDL event to the InputManager for further processing
		m_inputManager.handleEvent(event);

		// Execute the command associated with the triggered action, if any
		processActions(event);
	}
}

// The main loop for the Application
void Application::run() {
	// Set the running status of the Application based on the running status of the Editor
	m_running = m_editorContext.isRunning();

	if (!m_running) {  // If Editor is not running, start it
		m_running = true;
	}

	// Render the initial state of the Editor
	m_renderManager.clear();
	m_renderManager.render();
	m_renderManager.present();

	// As long as the Application is running, keep processing SDL events
	while (m_running) {
		handleEvents();
	}
}
