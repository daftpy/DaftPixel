#include "model/Canvas.h"

class CanvasController {
public:
	explicit CanvasController(Canvas& canvas);

	void setDimensions(uint16_t width, uint16_t height);
	
private:
	Canvas& canvas;
};