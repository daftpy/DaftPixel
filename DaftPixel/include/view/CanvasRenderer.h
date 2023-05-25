#include "model/Canvas.h"
#include "view/ui/CanvasStatusBar.h"
#include "view/IDrawable.h"

class CanvasRenderer : public IDrawable {
public:
	explicit CanvasRenderer(std::shared_ptr<Canvas> canvas, TTF_Font* font);

	void render(SDL_Renderer* renderer) const override;

private:
	TTF_Font* font;
	std::shared_ptr<Canvas> canvas;
	CanvasStatusBar statusBar;
};