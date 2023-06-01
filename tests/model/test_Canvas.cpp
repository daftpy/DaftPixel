/**
 * @file test_Canvas.cpp
 * @brief This file contains the unit tests for the Canvas class.
 *
 * Each TEST in this file corresponds to a particular functionality of the Canvas class.
 * Here's a quick guide for adding tests to this file:
 *
 * - TEST: Provide a brief identifier for the test.
 * - DESCRIPTION: Describe the specific functionality or conditions the test is verifying.
 *
 * Please ensure that every aspect of the Canvas class is covered by a test in this file,
 * and that your tests are easy to understand and maintain for future developers.
 */

#include <gtest/gtest.h>
#include <model/canvas/CanvasSurface.h>

 /*
  * TEST: Default Constructor
  * DESCRIPTION:
  * This test verifies that the default Canvas constructor creates a canvas of size 32x32.
  */
TEST(CanvasTest, DefaultConstructor) {
    CanvasSurface canvas;
    EXPECT_EQ(canvas.getWidth(), 32);
    EXPECT_EQ(canvas.getHeight(), 32);
    EXPECT_EQ(canvas._testGetPixelBufferDimensions().first, 32);
    EXPECT_EQ(canvas._testGetPixelBufferDimensions().second, 32);
}

/*
 * TEST: Set And Get Valid Width An dHeight
 * DESCRIPTION:
 * This test verifies that we can set and get valid width and height for the Canvas.
 */
TEST(CanvasTest, SetAndGetValidWidthAndHeight) {
    CanvasSurface canvas;
    EXPECT_NO_THROW(canvas.setWidth(10));
    EXPECT_EQ(canvas.getWidth(), 10);
    EXPECT_NO_THROW(canvas.setHeight(20));
    EXPECT_EQ(canvas.getHeight(), 20);
}

/*
 * TEST: Set Invalid Width And Height
 * DESCRIPTION:
 * This test verifies that attempting to set an invalid width or height (0 in this case) results 
 * in an exception.
 */
TEST(CanvasTest, SetInvalidWidthAndHeight) {
    CanvasSurface canvas;
    EXPECT_THROW(canvas.setWidth(0), std::invalid_argument);
    EXPECT_THROW(canvas.setHeight(0), std::invalid_argument);
}

/*
 * TEST: Verify Pixel Buffer Dimensions
 * DESCRIPTION:
 * This test verifies the internal dimensions of a Canvas' pixel buffer are equal to the dimensions of
 * the canvas object.
 */
TEST(CanvasTest, VerifyPixelBufferDimensions) {
    CanvasSurface canvas;
    EXPECT_EQ(canvas.getWidth(), canvas._testGetPixelBufferDimensions().first);
    EXPECT_EQ(canvas.getHeight(), canvas._testGetPixelBufferDimensions().second);
}