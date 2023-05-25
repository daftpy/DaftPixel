# DaftPixel

DaftPixel is an application that serves as a basic pixel editor, allowing users to manipulate individual pixels on a canvas to create custom images. The project uses SDL for rendering and managing user interactions.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

## Prerequisites

Before you begin, ensure you have met the following requirements:

- You have installed the latest version of [CMake](https://cmake.org/download/).
- You have downloaded [SDL2 version 2.26.5](https://libsdl.org/download-2.0.php) and [SDL2_ttf version 2.20.2](https://www.libsdl.org/projects/SDL_ttf/) libraries.

After downloading and extracting the SDL2 and SDL2_ttf libraries, move them to a directory named `deps` in the root of your project. The resulting directory structure should look like this:

* deps
	* SDL2_ttf-2.20.2
	* SDL2-2.26.5

This project's CMake configuration is set up to look for the SDL2 and SDL2_ttf libraries inside these directories.

### Building

To build DaftPixel, follow these steps:

1. Install CMake: [https://cmake.org/download/](https://cmake.org/download/)
2. Clone the repository: `git clone https://github.com/username/DaftPixel.git`
3. Navigate to the directory: `cd DaftPixel`
4. Generate the build files:
   - On Unix (Linux, macOS, etc.), run: `cmake .`
   - On Windows, run: `cmake -G "Visual Studio 17 2022" .`
5. Build the project:
   - On Unix, run: `make`
   - On Windows, open the generated `.sln` file in Visual Studio and build the project.

## Project Progress

The project is in the early stages of development. We have defined the primary components of the application and their roles. These components include the `EditorController`, `Canvas`, `Pixel`, `PixelBuffer`, and `CanvasRenderer`.

Currently, `EditorController` is responsible for managing the application's lifecycle. `Canvas` represents the drawable area where pixels can be edited. `Pixel` serves as the basic unit in the application, representing a single pixel with color data. `PixelBuffer` forms an image of pixels, essentially a 2D grid of `Pixel` objects. `CanvasRenderer` is tasked with rendering the `Canvas` onto the screen.

We are in the process of implementing the primary functionalities of these components, and testing their integration. Once the basic editing features are implemented and tested, we'll focus on refining the user interface and enhancing the user experience.

## Authors

- [Daftpy](https://github.com/Daftpy)

## License

TBD.

## Acknowledgments

- SDL2 and SDL2_ttf for providing the tools to build this application.
- [Vmenezio](https://twitter.com/vmenezio) for creating and distributing monogram.ttf freely.