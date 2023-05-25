#pragma once
#include <SDL_ttf.h>
#include "view/ui/CanvasStatusBar.h"
#include "view/RenderManager.h"
#include "view/IDrawable.h"

class Canvas : public IDrawable {
public:
	Canvas(uint16_t width, uint16_t height, TTF_Font* font, RenderManager& renderManager)
		: canvasWidth(width),
		canvasHeight(height),
		font(font),
		renderManager(renderManager),
		statusBar(font) {}

	~Canvas() = default;

	void render(SDL_Renderer* renderer) const override;

	void setWidth(uint16_t width);
	uint16_t getWidth() const;

	void setHeight(uint16_t height);
	uint16_t getHeight() const;

private:
	TTF_Font* font;
	RenderManager& renderManager;
	CanvasStatusBar statusBar;
	uint16_t canvasWidth;
	uint16_t canvasHeight;
};
