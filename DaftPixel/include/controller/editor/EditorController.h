#pragma once

#include <iostream>
#include <SDL.h>

// Include models
#include "model/editor/Context.h"
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
		EditorController(Editor::Context& editorContext);

	private:
		/**
		 * @brief Represents the current state of the pixel editor.
		 */
		Editor::Context& m_editorContext;
	};

}  // namespace Editor
