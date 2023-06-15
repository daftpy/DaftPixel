# Include Google Test using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Define paths to SDL2 and SDL2_ttf
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/deps/${SDL2_VERSION}/cmake")
set(SDL2_ttf_DIR "${CMAKE_SOURCE_DIR}/deps/${SDL2_TTF_VERSION}/cmake")

# Append these paths to CMAKE_PREFIX_PATH
list(APPEND CMAKE_PREFIX_PATH ${SDL2_DIR} ${SDL2_ttf_DIR})

# Find SDL2 and SDL2_ttf
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Define the source files for the test executable
set(TEST_SOURCES 
  test_main.cpp 
  model/test_PixelBuffer.cpp
  model/test_Canvas.cpp

  
  
  "../DaftPixel/src/model/canvas/Surface.cpp"
)

# Add test executable
add_executable(DaftPixelTests ${TEST_SOURCES})

# Define the include directories for the test executable
set(TEST_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/DaftPixel/include)

# Add include directories
target_include_directories(DaftPixelTests PRIVATE ${TEST_INCLUDE_DIRS})

# Link SDL2, SDL2_ttf, and GTest to the target
target_link_libraries(DaftPixelTests PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf gtest_main)

# Add the TESTING definition
target_compile_definitions(DaftPixelTests PRIVATE TESTING)

# Print out the paths for debugging purposes
message(STATUS "SDL2_ttf_DIR: ${SDL2_ttf_DIR}")
message(STATUS "SDL2_DIR: ${SDL2_DIR}")
message(STATUS "CMAKE_SRC: ${CMAKE_SOURCE_DIR}")
