// DaftPixel.cpp : Defines the entry point for the application.
//
#define SDL_MAIN_HANDLED
#include "../include/main.h"
#include <SDL.h>

int main(int argc, char* argv[])
{
	EditorController Editor;
	SDL_SetMainReady();
	Editor.run();

	return 0;
}
