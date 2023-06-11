#include "view/canvas/ui/Layout.h"

Canvas::Ui::Layout::Layout(RenderContext& renderContext) : renderContext(renderContext), 
surfaceView(renderContext), statusBar(renderContext, layoutWidth, layoutHeight), layoutWidth(renderContext.windowWidth),
layoutHeight(renderContext.windowHeight) {
	// TODO constructor
}

void Canvas::Ui::Layout::render(SDL_Renderer* renderer) const {
	surfaceView.render(renderer);
	statusBar.render(renderer);
}

void Canvas::Ui::Layout::updateWidgets(SDL_Renderer* renderer) {
	std::cout << "UPDATED" << std::endl;
	statusBar.updateTexture(renderer);
	statusBar.updateWidgets(renderer);
}