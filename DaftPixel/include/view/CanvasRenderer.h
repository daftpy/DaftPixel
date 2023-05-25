/**
* @file CanvasRenderer.h
* @brief Header file for the CanvasRenderer class
*/

/**
* @class CanvasRenderer
*
* @brief This class is responsible for rendering a Canvas instance. It implements the IDrawable interface.
*/

#include "model/Canvas.h"
#include "view/ui/CanvasStatusBar.h"
#include "view/IDrawable.h"

class CanvasRenderer : public IDrawable {
public:
    /**
    * @brief Constructs a new CanvasRenderer instance with a shared pointer to a Canvas and a TTF_Font.
    *
    * @param canvas Shared pointer to a Canvas instance.
    * @param font TTF_Font used for rendering.
    */
    explicit CanvasRenderer(std::shared_ptr<Canvas> canvas, TTF_Font* font);

    /**
    * @brief Renders the Canvas using the provided SDL_Renderer.
    *
    * @param renderer SDL_Renderer used for rendering.
    */
    void render(SDL_Renderer* renderer) const override;

private:
    /**
    * @brief TTF_Font used for rendering.
    */
    TTF_Font* font;

    /**
    * @brief Shared pointer to a Canvas instance.
    */
    std::shared_ptr<Canvas> canvas;

    /**
    * @brief CanvasStatusBar instance for rendering the status bar.
    */
    CanvasStatusBar statusBar;
};
