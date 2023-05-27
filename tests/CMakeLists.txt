# Set the path to the SDL2 directory
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/deps/${SDL2_VERSION}/cmake")
set(SDL2_ttf_DIR "${CMAKE_SOURCE_DIR}/deps/${SDL2_TTF_VERSION}/cmake")

list(APPEND CMAKE_PREFIX_PATH ${SDL2_DIR})
list(APPEND CMAKE_PREFIX_PATH ${SDL2_ttf_DIR})

# Include Google Test using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Add test executable
add_executable(DaftPixelTests test_main.cpp)

# Add include directories
target_include_directories(DaftPixelTests PRIVATE include)

# Link SDL2, SDL2_ttf, and GTest to the target
target_link_libraries(DaftPixelTests PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf gtest_main)

message(STATUS "SDL2_ttf_DIR: ${SDL2_ttf_DIR}")
message(STATUS "SDL2_DIR: ${SDL2_DIR}")
message(STATUS "GTEST_ROOT: ${GTEST_ROOT}")
