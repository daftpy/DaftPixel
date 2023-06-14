// DaftPixel.cpp : Defines the entry point for the application.
//
#define SDL_MAIN_HANDLED
#include "../include/main.h"
#include <SDL.h>
#include "application.h"

int main(int argc, char* argv[])
{
	Application application;
	SDL_SetMainReady();
	application.run();

	return 0;
}
