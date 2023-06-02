/**
 * @file CanvasRendererController.h
 * @brief Header file for the CanvasRendererController class.
 * This class is responsible for controlling the CanvasSurfaceView object.
 */

 /**
  * @class CanvasRendererController
  *
  * @brief The CanvasRendererController class manages the CanvasSurfaceView object,
  * providing methods to modify its state.
  */
#pragma once

#include "view/canvas/CanvasSurfaceView.h"
#include <stdexcept>

class CanvasRendererController {
public:
    /**
    * @brief Constructs a new CanvasRendererController with a reference to a CanvasSurfaceView.
    *
    * @param canvasRenderer A reference to a CanvasSurfaceView object that this controller will manage.
    */
    CanvasRendererController(CanvasSurfaceView& canvasRenderer);

    /**
    * @brief Changes the scale factor of the associated CanvasSurfaceView by a specified delta.
    *
    * @param delta The amount by which to change the scale factor.
    * This can be positive to increase the scale factor or negative to decrease it.
    * If the resulting scale factor would be less than or equal to zero, an exception is thrown.
    *
    * @throws std::out_of_range if the resulting scale factor would be less than or equal to zero.
    */
    void changeScaleFactor(int8_t delta);

private:
    CanvasSurfaceView& canvasRenderer; ///< A reference to the CanvasSurfaceView object this controller manages.
};
