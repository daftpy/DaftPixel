#pragma once
#include <iostream>
#include "controller/canvas/CanvasSurfaceController.h"

class InputManager {
public:
	InputManager(CanvasSurfaceController& surfaceController);

private:
	CanvasSurfaceController& surfaceController;
};