#include "view/editor/EditorView.h"

void Editor::View::EditorView::render(SDL_Renderer* renderer) const {
	m_canvasLayout.render(renderer);
}