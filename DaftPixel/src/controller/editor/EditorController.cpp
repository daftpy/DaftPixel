#include "controller/editor/EditorController.h"

// EditorController constructor
Editor::EditorController::EditorController()
    : m_canvasLayout(std::make_shared<Canvas::Ui::Layout>(editorContext.getRenderContext())),  // Initialize the Canvas Layout with the Render Context of the Editor State
    m_running(false) {  // The Editor is not running initially

    // Fills the canvas with random pixel colors
    editorContext.getCanvasSurface().getPixelBuffer().generateRandomPixels();

    // Add the Canvas Layout to the RenderManager. This will ensure it gets rendered.
    editorContext.getRenderManager().addDrawable(m_canvasLayout);

    // Add the Canvas Layout to the list of layouts that need to be updated during the rendering process.
    editorContext.getRenderManager().addLayout(m_canvasLayout);

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
    editorContext.getBindingManager().addKeyBinding(deacreaseKeyBinding);
    editorContext.getBindingManager().addKeyBinding(increaseKeyBinding);

    // Add mouse button bindings to the Binding Manager
    editorContext.getBindingManager().addMouseButtonBinding(paintPixelMouseBinding);
    editorContext.getBindingManager().addMouseButtonBinding(stopPaintPixelMouseBinding);
    editorContext.getBindingManager().addMouseButtonBinding(selectPixelMouseBinding);

    // Update all layouts. This prepares them for rendering.
    editorContext.getRenderManager().updateLayouts();
}

// Process all user input actions
void Editor::EditorController::processActions(const SDL_Event& event) {
    for (auto action : actions) {  // Loop over all possible actions
        if (editorContext.getInputManager().isActionTriggered(action)) {  // Check if the current action is triggered
            editorContext.getCommandManager().executeCommand(action, event);  // If so, execute the corresponding command

            // Render the state of the Editor after executing the command
            editorContext.getRenderManager().clear();
            editorContext.getRenderManager().render();
            editorContext.getRenderManager().present();
        }
    }
}

// Handle all incoming SDL events
void Editor::EditorController::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {  // Fetch all pending SDL events
        if (event.type == SDL_QUIT) {  // If the SDL_QUIT event is polled, stop running the Editor
            m_running = false;
        }
        else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
            // If the window is resized, update the window size in the Render Context and redraw the state of the Editor
            editorContext.getRenderContext().updateWindowSize(event.window.data1, event.window.data2);
            editorContext.getRenderManager().clear();
            editorContext.getRenderManager().render();
            editorContext.getRenderManager().present();
        }

        // Pass the SDL event to the Input Manager for processing
        editorContext.getInputManager().handleEvent(event);

        // Process the actions based on the SDL event
        processActions(event);
    }
}

// The main run loop for the Editor
void Editor::EditorController::run() {
    m_running = editorContext.isRunning();  // Check if the Editor is running

    if (!m_running) {  // If not, start running it
        m_running = true;
    }

    // Render the initial state of the Editor
    editorContext.getRenderManager().clear();
    editorContext.getRenderManager().render();
    editorContext.getRenderManager().present();

    // While the Editor is running, keep handling SDL events
    while (m_running) {
        handleEvents();
    }
}
