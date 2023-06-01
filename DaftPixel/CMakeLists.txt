# Set the path to the SDL2 directory
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/deps/${SDL2_VERSION}/cmake")
set(SDL2_ttf_DIR "${CMAKE_SOURCE_DIR}/deps/${SDL2_TTF_VERSION}/cmake")


list(APPEND CMAKE_PREFIX_PATH ${SDL2_DIR})
list(APPEND CMAKE_PREFIX_PATH ${SDL2_ttf_DIR})

# Find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Add source to this project's executable.
add_executable (DaftPixel 
"src/main.cpp" 
"src/controller/EditorController.cpp" 
"include/model/Pixel.h"
"src/model/Pixel.cpp" 
"include/model/PixelBuffer.h" 
"src/model/PixelBuffer.cpp" 
"include/view/RenderManager.h" 
"src/view/RenderManager.cpp" 
"include/view/ui/CanvasStatusBar.h" 
"include/model/canvas/Canvas.h" 
"include/view/IDrawable.h" 
"src/controller/CanvasController.cpp" 
"include/controller/CanvasController.h"
"src/model/canvas/Canvas.cpp" "src/view/CanvasRenderer.cpp" "include/view/CanvasRenderer.h" "src/view/ui/CanvasStatusBar.cpp" "include/controller/CanvasRendererController.h" "src/controller/CanvasRendererController.cpp")

# Add include directories.
target_include_directories(DaftPixel PRIVATE include)

# Link SDL2 and SDL2_ttf to the target.
target_link_libraries(DaftPixel PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf)

# Conditionally adds the TESTING definition if we are using a Debug build configuration.
target_compile_definitions(DaftPixel PRIVATE $<$<CONFIG:Debug>:TESTING>)

# TODO: Add tests and install targets if needed.
message(STATUS "SDL2_ttf_DIR: ${SDL2_ttf_DIR}")
message(STATUS "SDL2_DIR: ${SDL2_DIR}")
