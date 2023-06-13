#pragma once

#include <iostream>
#include <SDL.h>

// Include models
#include "model/editor/State.h"
#include "model/Action.h"

// Include views
#include "view/canvas/ui/Layout.h"

// Include managers to create bindings in constructor
#include "manager/BindingManager.h"

/**
 * @namespace Editor
 * @brief The Editor namespace is used to encapsulate the EditorController class and its associated data and functions.
 */
namespace Editor {

	/**
	 * @class EditorController
	 * @brief The EditorController class orchestrates the various components of the pixel editor application.
	 */
	class EditorController {
	public:
		/**
		 * @brief Constructs a new EditorController object.
		 */
		EditorController();

		/**
		 * @brief Processes triggered actions from the user.
		 *
		 * @param event The SDL event associated with the triggered action.
		 */
		void processActions(const SDL_Event& event);

		/**
		 * @brief Runs the editor by rendering the initial state, and then enters a loop to handle user events.
		 */
		void run();

		/**
		 * @brief Handles all incoming SDL events and processes actions accordingly.
		 */
		void handleEvents();

	private:
		/**
		 * @brief Represents the current state of the pixel editor.
		 */
		Editor::State editorState;

		/**
		 * @brief The layout of the canvas to be rendered in the editor.
		 */
		std::shared_ptr<Canvas::Ui::Layout> m_canvasLayout;

		/**
		 * @brief Flag to keep track of whether the editor is currently running or not.
		 */
		bool m_running;

		/**
		 * @brief A list of Actions that have been triggered and are waiting to be processed.
		 */
		std::vector<Action> actions;
	};

}  // namespace Editor
