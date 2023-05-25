/**
* @file Canvas.h
* @brief Header file for the Canvas class
*/

/**
* @class Canvas
*
* @brief This class represents a Canvas instance. Each Canvas object stores the width and height of the canvas.
*/

#pragma once
#include <SDL_ttf.h>
#include "view/ui/CanvasStatusBar.h"
#include "view/RenderManager.h"
#include "view/IDrawable.h"

class Canvas {
public:
    /**
    * @brief Constructs a new Canvas instance with specified width and height.
    *
    * @param width Width of the Canvas.
    * @param height Height of the Canvas.
    */
    Canvas(uint16_t width, uint16_t height)
        : canvasWidth(width),
        canvasHeight(height) {}

    /**
    * @brief Set the width of the Canvas.
    *
    * @param width Width of the Canvas.
    */
    void setWidth(uint16_t width);

    /**
    * @brief Get the width of the Canvas.
    *
    * @return uint16_t Width of the Canvas.
    */
    uint16_t getWidth() const;

    /**
    * @brief Set the height of the Canvas.
    *
    * @param height Height of the Canvas.
    */
    void setHeight(uint16_t height);

    /**
    * @brief Get the height of the Canvas.
    *
    * @return uint16_t Height of the Canvas.
    */
    uint16_t getHeight() const;

private:
    /**
    * @brief Width of the Canvas.
    */
    uint16_t canvasWidth;

    /**
    * @brief Height of the Canvas.
    */
    uint16_t canvasHeight;
};
