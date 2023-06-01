/**
* @file CanvasController.h
* @brief Header file for the CanvasController class. This class controls a Canvas instance, allowing for the setting of its dimensions and providing access to the Canvas instance.
*/

/**
* @class CanvasController
*
* @brief This class controls a Canvas instance. It allows the setting of the Canvas's dimensions and provides access to the Canvas instance.
*/

#pragma once
#include <memory>
#include "model/canvas/CanvasSurface.h"

class CanvasController {
public:
    /**
    * @brief Constructs a new CanvasController instance with a reference to a Canvas.
    *
    * @param canvas Reference to a Canvas instance.
    */
    explicit CanvasController(CanvasSurface& canvas);

    /**
    * @brief Set the dimensions of the Canvas.
    *
    * @param width Width of the Canvas.
    * @param height Height of the Canvas.
    */
    void setDimensions(uint16_t width, uint16_t height);

    /**
    * @brief Get a reference to the Canvas instance.
    *
    * @return Canvas& Reference to the Canvas instance.
    */
    CanvasSurface& getCanvas();

private:
    /**
    * @brief Reference to a Canvas instance.
    */
    CanvasSurface& canvas;
};
