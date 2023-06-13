#include "model/editor/State.h"

// State constructor. Initializes various manager objects and resources required for the pixel editor.
Editor::State::State() :
    m_renderManager(800, 600), // initialize render manager with window size
    m_canvasSurface(32, 32), // initialize canvas surface with specified pixel grid size
    m_surfaceController(m_canvasSurface), // initialize surface controller with canvas surface reference
    m_editorFont(loadFont()), // load font resource
    m_renderContext(m_canvasSurface, m_editorFont, 1, m_renderManager.getWindow()), // initialize render context
    m_inputManager(m_bindingManager), // initialize input manager with reference to binding manager
    m_commandManager(m_renderContext, m_inputManager, m_surfaceController), // initialize command manager
    m_running(false) // initially, editor is not running
{
}

// State destructor. Frees resources and shuts down SDL_ttf library.
Editor::State::~State() {
    if (m_editorFont != nullptr) {
        TTF_CloseFont(m_editorFont); // close the loaded font
        m_editorFont = nullptr;
    }
    TTF_Quit(); // shut down SDL_ttf subsystem
}

// Function to load font resource from a file.
TTF_Font* Editor::State::loadFont() {
    // Initialize SDL_ttf library
    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        // handle error
    }

    // Load font from file
    TTF_Font* font = TTF_OpenFont("monogram.ttf", 16); // replace with your font file path and desired font size
    if (font == nullptr) {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        // handle error
    }
    return font;
}

// Getters for various manager objects and resources. Allow other parts of the application to interact with these resources.
InputManager& Editor::State::getInputManager() {
    return m_inputManager;
}

CommandManager& Editor::State::getCommandManager() {
    return m_commandManager;
}

RenderManager& Editor::State::getRenderManager() {
    return m_renderManager;
}

Canvas::Surface& Editor::State::getCanvasSurface() {
    return m_canvasSurface;
}

BindingManager& Editor::State::getBindingManager() {
    return m_bindingManager;
}

// Getter for running state. Allows other parts of the application to check if the editor is currently running.
bool& Editor::State::isRunning()
{
    return m_running;
}

// Getter for render context. Allows other parts of the application to access the render context.
Canvas::RenderContext& Editor::State::getRenderContext()
{
    return m_renderContext;
}
