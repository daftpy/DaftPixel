#include "model/editor/Context.h"

// Context constructor. Initializes various manager objects and resources required for the pixel editor.
Editor::Context::Context() :
    m_renderManager(800, 600), // initialize render manager with window size
    m_canvasSurface(32, 32), // initialize canvas surface with specified pixel grid size
    m_surfaceController(m_canvasSurface), // initialize surface controller with canvas surface reference
    m_editorFont(loadFont()), // load font resource
    m_renderContext(m_canvasSurface, m_editorFont, 1, m_renderManager.getWindow()), // initialize render context
    m_inputManager(m_bindingManager), // initialize input manager with reference to binding manager
    m_commandManager(m_renderContext, m_inputManager, m_surfaceController), // initialize command manager
    m_running(false), // initially, editor is not running
    m_canvasLayout(std::make_shared<Canvas::Ui::Layout>(m_renderContext))
{
    m_renderManager.addDrawable(m_canvasLayout);
    m_renderManager.addLayout(m_canvasLayout);
}

// Context destructor. Frees resources and shuts down SDL_ttf library.
Editor::Context::~Context() {
    if (m_editorFont != nullptr) {
        TTF_CloseFont(m_editorFont); // close the loaded font
        m_editorFont = nullptr;
    }
    TTF_Quit(); // shut down SDL_ttf subsystem
}

// Function to load font resource from a file.
TTF_Font* Editor::Context::loadFont() {
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
InputManager& Editor::Context::getInputManager() {
    return m_inputManager;
}

CommandManager& Editor::Context::getCommandManager() {
    return m_commandManager;
}

RenderManager& Editor::Context::getRenderManager() {
    return m_renderManager;
}

Canvas::Surface& Editor::Context::getCanvasSurface() {
    return m_canvasSurface;
}

BindingManager& Editor::Context::getBindingManager() {
    return m_bindingManager;
}

// Getter for running state. Allows other parts of the application to check if the editor is currently running.
bool& Editor::Context::isRunning()
{
    return m_running;
}

// Getter for render context. Allows other parts of the application to access the render context.
Canvas::RenderContext& Editor::Context::getRenderContext()
{
    return m_renderContext;
}

Canvas::Ui::Layout& Editor::Context::getCanvasLayout()
{
    return *m_canvasLayout;
}