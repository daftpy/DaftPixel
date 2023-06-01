/**
* @file CanvasSurfaceController.h
* @brief Header file for the CanvasController class. This class controls a CanvasSurface instance, allowing for the setting of its dimensions and providing access to the CanvasSurface instance.
*/

/**
* @class CanvasSurfaceController
*
* @brief This class controls a CanvasSurface instance. It allows the setting of the Canvas's dimensions and provides access to the CanvasSurface instance.
*/

#pragma once
#include <memory>
#include "model/canvas/CanvasSurface.h"

class CanvasSurfaceController {
public:
    /**
    * @brief Constructs a new CanvasSurfaceController instance with a reference to a CanvasSurface.
    *
    * @param canvasSurface Reference to a CanvasSurface instance.
    */
    explicit CanvasSurfaceController(CanvasSurface& canvas);

    /**
    * @brief Set the dimensions of the CanvasSurface.
    *
    * @param width Width of the CanvasSurface.
    * @param height Height of the CanvasSurface.
    */
    void setDimensions(uint16_t width, uint16_t height);

    /**
    * @brief Get a reference to the CanvasSurface instance.
    *
    * @return Canvas& Reference to the CanvasSurface instance.
    */
    CanvasSurface& getCanvasSurface();

private:
    /**
    * @brief Reference to a CanvasSurface instance.
    */
    CanvasSurface& canvasSurface;
};
