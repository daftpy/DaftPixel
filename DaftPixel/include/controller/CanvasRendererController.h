/**
 * @file CanvasRendererController.h
 * @brief Header file for the CanvasRendererController class.
 * This class is responsible for controlling the CanvasRenderer object.
 */

 /**
  * @class CanvasRendererController
  *
  * @brief The CanvasRendererController class manages the CanvasRenderer object,
  * providing methods to modify its state.
  */
#pragma once

#include "view/CanvasRenderer.h"
#include <stdexcept>

class CanvasRendererController {
public:
    /**
    * @brief Constructs a new CanvasRendererController with a reference to a CanvasRenderer.
    *
    * @param canvasRenderer A reference to a CanvasRenderer object that this controller will manage.
    */
    CanvasRendererController(CanvasRenderer& canvasRenderer);

    /**
    * @brief Changes the scale factor of the associated CanvasRenderer by a specified delta.
    *
    * @param delta The amount by which to change the scale factor.
    * This can be positive to increase the scale factor or negative to decrease it.
    * If the resulting scale factor would be less than or equal to zero, an exception is thrown.
    *
    * @throws std::out_of_range if the resulting scale factor would be less than or equal to zero.
    */
    void changeScaleFactor(int8_t delta);

private:
    CanvasRenderer& canvasRenderer; ///< A reference to the CanvasRenderer object this controller manages.
};
