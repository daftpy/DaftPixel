#include "view/canvas/ui/Layout.h"

Canvas::Ui::Layout::Layout(RenderContext& renderContext) : renderContext(renderContext), 
surfaceView(renderContext), statusBar(renderContext, layoutWidth, layoutHeight), layoutWidth(renderContext.windowWidth),
layoutHeight(renderContext.windowHeight) {}

void Canvas::Ui::Layout::render(SDL_Renderer* renderer) const {
	surfaceView.render(renderer);
	statusBar.render(renderer);
}

void Canvas::Ui::Layout::updateWidgets(SDL_Renderer* renderer) {
	std::cout << "UPDATED WIDGETS" << std::endl;
	statusBar.updateWidgets(renderer);
	statusBar.updateTexture(renderer);
}