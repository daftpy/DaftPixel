#include "application.h"

Application::Application() : 
	m_renderManager(800, 600),
	m_inputManager(m_bindingManager),
	m_editorContext(m_renderManager, m_inputManager),
	m_editorController(m_editorContext) {

	// Fills the canvas with random pixel colors
	m_editorContext.getCanvasSurface().getPixelBuffer().generateRandomPixels();

	// Add the CanvasLayout to the application Render Manager
	m_renderManager.addDrawable(m_editorContext.getCanvasLayout());

	// Add the CanvasLayout to the Render Manager layout vector
	m_renderManager.addLayout(m_editorContext.getCanvasLayout());

	// Populate the actions vector with all possible actions.
	for (int i = 0; i < static_cast<int>(Action::None); ++i) {
		actions.push_back(static_cast<Action>(i));
	}

	// Create key bindings for actions
	KeyBinding deacreaseKeyBinding(SDLK_MINUS, KMOD_NONE, Action::DecreaseScaleFactor);
	KeyBinding increaseKeyBinding(SDLK_EQUALS, KMOD_NONE, Action::IncreaseScaleFactor);

	// Create mouse button bindings for actions
	MouseBinding paintPixelMouseBinding(SDL_MOUSEBUTTONDOWN, SDL_BUTTON_LEFT, KMOD_NONE, Action::PaintPixel);
	MouseBinding stopPaintPixelMouseBinding(SDL_MOUSEBUTTONUP, SDL_BUTTON_LEFT, KMOD_NONE, Action::PaintPixel);
	MouseBinding selectPixelMouseBinding(SDL_MOUSEBUTTONDOWN, SDL_BUTTON_RIGHT, KMOD_NONE, Action::SelectPixel);

	// Add key bindings to the Binding Manager
	m_bindingManager.addKeyBinding(deacreaseKeyBinding);
	m_bindingManager.addKeyBinding(increaseKeyBinding);

	// Add mouse button bindings to the Binding Manager
	m_bindingManager.addMouseButtonBinding(paintPixelMouseBinding);
	m_bindingManager.addMouseButtonBinding(stopPaintPixelMouseBinding);
	m_bindingManager.addMouseButtonBinding(selectPixelMouseBinding);

	// Update the layouts
	m_renderManager.updateLayouts();
}

void Application::processActions(const SDL_Event& event) {
	for (auto action : actions) {  // Loop over all possible actions
		if (m_inputManager.isActionTriggered(action)) {  // Check if the current action is triggered
			m_editorContext.getCommandManager().executeCommand(action, event);  // If so, execute the corresponding command

			// Render the state of the Editor after executing the command
			m_renderManager.clear();
			m_renderManager.render();
			m_renderManager.present();
		}
	}
}

void Application::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {  // Fetch all pending SDL events
		if (event.type == SDL_QUIT) {  // If the SDL_QUIT event is polled, stop running the Editor
			m_running = false;
		}
		else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
			// If the window is resized, update the window size in the Render Context and redraw the state of the Editor
			m_editorContext.getRenderContext().updateWindowSize(event.window.data1, event.window.data2);
			m_renderManager.clear();
			m_renderManager.render();
			m_renderManager.present();
		}

		// Pass the SDL event to the Input Manager for processing
		m_inputManager.handleEvent(event);

		// Process the actions based on the SDL event
		processActions(event);
	}
}

// The main run loop for the Editor
void Application::run() {
	m_running = m_editorContext.isRunning();  // Check if the Editor is running

	if (!m_running) {  // If not, start running it
		m_running = true;
	}

	// Render the initial state of the Editor
	m_renderManager.clear();
	m_renderManager.render();
	m_renderManager.present();

	// While the Editor is running, keep handling SDL events
	while (m_running) {
		handleEvents();
	}
}
