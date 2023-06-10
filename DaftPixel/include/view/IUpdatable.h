#include <SDL.h>

class IUpdatable {
public:
    virtual ~IUpdatable() = default;
    virtual void updateWidgets(SDL_Renderer* renderer) = 0;
};