#pragma once
#include <cstdint>
#include <optional>
#include <SDL_ttf.h>

// Include Managers
#include "manager/InputManager.h"
#include "manager/CommandManager.h"
#include "view/RenderManager.h"
#include "manager/BindingManager.h"

// Include models
#include "model/Pixel.h"
#include "model/canvas/RenderContext.h"
#include "model/canvas/Surface.h"

// Include controllers
#include "controller/canvas/SurfaceController.h"

// Include views
#include "view/canvas/ui/Layout.h"

namespace Editor {

	/**
	* @class Context
	* @brief The Context class represents the current Context of the pixel editor.
	* It manages the key elements such as rendering, input, and commands. This class
	* is crucial in orchestrating the overall functionality of the pixel editor.
	*/
	class Context {
	public:
		/**
		* @brief Constructor for the Context class.
		*/
		Context(RenderManager& renderManager, InputManager& inputManager);

		/**
		* @brief Destructor for the Context class.
		*/
		~Context();

		/**
		* @brief Load the font from a file.
		* @return A pointer to the loaded font.
		*/
		TTF_Font* loadFont();

		/**
		* @brief Getter for CommandManager.
		* @return Reference to CommandManager.
		*/
		CommandManager& getCommandManager();

		/**
		* @brief Getter for RenderContext.
		* @return Reference to RenderContext.
		*/
		Canvas::RenderContext& getRenderContext();

		/**
		* @brief Getter for CanvasSurface.
		* @return Reference to CanvasSurface.
		*/
		Canvas::Surface& getCanvasSurface();

		/**
		* @brief Getter for CanvasLayout.
		* @return Reference to CanvasLayout.
		*/
		std::shared_ptr<Canvas::Ui::Layout> getCanvasLayout();

		/**
		* @brief Check if the editor is currently running.
		* @return Reference to the boolean indicating the running Context.
		*/
		bool& isRunning();

		// Returns the current pixel under the mouse pointer
		std::optional<Pixel> getCurrentPixel() const;


	private:
		int hoverPixelX = -1; ///< The x-coordinate of the hovered pixel.
		int hoverPixelY = -1; ///< The y-coordinate of the hovered pixel.

		/**
		* @brief An optional Pixel object representing the current Pixel that the user is hovering over. It can be empty if no Pixel is currently being hovered over.
		*/
		std::optional<Pixel> m_currentPixel;

		Canvas::Surface m_canvasSurface; ///< The CanvasSurface instance.
		Canvas::Controller::SurfaceController m_surfaceController; ///< The SurfaceController instance.
		TTF_Font* m_editorFont; ///< The font used in the editor.
		Canvas::RenderContext m_renderContext; ///< The RenderContext instance.
		CommandManager m_commandManager; ///< The CommandManager instance.
		bool m_running; ///< The running state of the editor.

		/**
		* @brief The layout of the canvas to be rendered in the editor.
		*/
		std::shared_ptr<Canvas::Ui::Layout> m_canvasLayout;

		/**
		* @brief A list of Actions that have been triggered and are waiting to be processed.
		*/
		std::vector<Action> actions;
	};
}
