#pragma once
#include "view/canvas/ui/Layout.h"
#include "view/IDrawable.h"

namespace Editor {
	namespace View {
		class EditorView : public IDrawable {
		public:
			EditorView();

			/**
			 * @brief Renders the editor.
			 *
			 * @param renderer Pointer to the SDL_Renderer object.
			 */
			void render(SDL_Renderer* renderer) const override;


		private:
			Canvas::Ui::Layout& m_canvasLayout;
		};
	}
}