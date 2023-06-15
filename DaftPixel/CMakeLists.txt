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
"include/model/Pixel.h"
 
"include/model/PixelBuffer.h" 
 
"include/view/RenderManager.h" 
"src/view/RenderManager.cpp" 
"include/view/canvas/ui/StatusBar.h" 
"include/model/canvas/Surface.h" 
"include/view/IDrawable.h" 
"src/controller/canvas/SurfaceController.cpp" 
"include/controller/canvas/SurfaceController.h"
"src/model/canvas/Surface.cpp"
"src/view/canvas/SurfaceView.cpp"
"include/view/canvas/SurfaceView.h"
"src/view/canvas/ui/StatusBar.cpp"
"include/model/canvas/RenderContext.h"
"include/manager/InputManager.h"
"src/manager/InputManager.cpp"
"include/manager/BindingManager.h"
"src/manager/BindingManager.cpp"
"include/model/Action.h"
"include/manager/CommandManager.h"
"src/manager/CommandManager.cpp"
"src/model/canvas/RenderContext.cpp"
"include/view/canvas/ui/InfoWidget.h"
"include/view/ILayout.h"
"src/view/canvas/ui/Layout.cpp"
"include/view/ILayout.h"
"include/view/IUpdatable.h"
"include/model/editor/Context.h"
"src/model/editor/Context.cpp"
"include/controller/editor/EditorController.h"
"src/controller/editor/EditorController.cpp" "include/application.h" "src/application.cpp" "src/view/editor/EditorView.cpp")

# Add include directories.
target_include_directories(DaftPixel PRIVATE include)

# Link SDL2 and SDL2_ttf to the target.
target_link_libraries(DaftPixel PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf)

# Conditionally adds the TESTING definition if we are using a Debug build configuration.
target_compile_definitions(DaftPixel PRIVATE $<$<CONFIG:Debug>:TESTING>)

# TODO: Add tests and install targets if needed.
message(STATUS "SDL2_ttf_DIR: ${SDL2_ttf_DIR}")
message(STATUS "SDL2_DIR: ${SDL2_DIR}")
