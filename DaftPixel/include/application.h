#pragma once
// include controllers
#include "controller/editor/EditorController.h"

// include models & contexts
#include "model/editor/Context.h"

// include managers
#include "view/RenderManager.h"
#include "manager/BindingManager.h"
#include "manager/InputManager.h"

class Application {
public:
	Application();

	void run();

	void processActions(const SDL_Event& event);

	void handleEvents();

private:
	RenderManager m_renderManager;

	BindingManager m_bindingManager; ///< The BindingManager instance.
	InputManager m_inputManager; ///< The InputManager instance.

	Editor::Context m_editorContext;
	Editor::EditorController m_editorController;

	/**
	* @brief A list of Actions that have been triggered and are waiting to be processed.
	*/
	std::vector<Action> actions;

	bool m_running = false;
};