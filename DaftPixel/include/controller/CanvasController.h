/**
* @file CanvasController.h
* @brief Header file for the CanvasController class
*/

/**
* @class CanvasController
*
* @brief This class controls a Canvas instance. It allows to set the dimensions of the Canvas
* and retrieve the shared pointer to the current Canvas instance.
*/

#pragma once
#include <memory>
#include "model/Canvas.h"

class CanvasController {
public:
    /**
    * @brief Constructs a new CanvasController instance with a shared pointer to a Canvas.
    *
    * @param canvas Shared pointer to a Canvas instance.
    */
    explicit CanvasController(std::shared_ptr<Canvas> canvas);

    /**
    * @brief Set the dimensions of the Canvas.
    *
    * @param width Width of the Canvas.
    * @param height Height of the Canvas.
    */
    void setDimensions(uint16_t width, uint16_t height);

    /**
    * @brief Get the shared pointer to the Canvas instance.
    *
    * @return std::shared_ptr<Canvas> Shared pointer to the Canvas instance.
    */
    std::shared_ptr<Canvas> getCanvas() {
        return canvas;
    }

private:
    /**
    * @brief Shared pointer to a Canvas instance.
    */
    std::shared_ptr<Canvas> canvas;
};
