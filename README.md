# DaftPixel

DaftPixel is an application that serves as a basic pixel editor, allowing users to manipulate individual pixels on a canvas to create custom images. The project uses SDL for rendering and managing user interactions.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- SDL2
- SDL2_ttf
- A C++17 compatible compiler

## Project Progress

The project is in the early stages of development. We have defined the primary components of the application and their roles. These components include the `EditorController`, `Canvas`, `Pixel`, `PixelBuffer`, and `CanvasRenderer`.

Currently, `EditorController` is responsible for managing the application's lifecycle. `Canvas` represents the drawable area where pixels can be edited. `Pixel` serves as the basic unit in the application, representing a single pixel with color data. `PixelBuffer` forms an image of pixels, essentially a 2D grid of `Pixel` objects. `CanvasRenderer` is tasked with rendering the `Canvas` onto the screen.

We are in the process of implementing the primary functionalities of these components, and testing their integration. Once the basic editing features are implemented and tested, we'll focus on refining the user interface and enhancing the user experience.

## Authors

- [Daftpy](https://github.com/Daftpy)

## Acknowledgments

- SDL2 and SDL2_ttf for providing the tools to build this application.
