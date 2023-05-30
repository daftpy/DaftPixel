/**
 * @file test_PixelBuffer.cpp
 * @brief This file contains the unit tests for the PixelBuffer class.
 *
 * Each TEST in this file corresponds to a particular functionality of the PixelBuffer class.
 * Here's a quick guide for adding tests to this file:
 *
 * - TEST: Provide a brief identifier for the test.
 * - DESCRIPTION: Describe the specific functionality or conditions the test is verifying.
 *
 * Please ensure that every aspect of the PixelBuffer class is covered by a test in this file,
 * and that your tests are easy to understand and maintain for future developers.
 */

#include <gtest/gtest.h>
#include <model/PixelBuffer.h>

 /*
  * TEST: ConstructWithValidParameters
  * DESCRIPTION:
  * This test verifies that a PixelBuffer can be constructed with valid width, height, and a 
  * default pixel.
  */
TEST(PixelBufferTest, ConstructWithValidParameters) {
    Pixel defaultPixel;
    PixelBuffer buffer(10, 10, defaultPixel);
    EXPECT_EQ(buffer.getWidth(), 10);
    EXPECT_EQ(buffer.getHeight(), 10);
}

/*
 * TEST: ConstructWithInvalidParameters
 * DESCRIPTION:
 * This test verifies that attempting to construct a PixelBuffer with invalid width or 
 * height (0 in this case) results in an exception.
 */
TEST(PixelBufferTest, ConstructWithInvalidParameters) {
    Pixel defaultPixel;
    EXPECT_THROW(PixelBuffer buffer(0, 10, defaultPixel), std::invalid_argument);
    EXPECT_THROW(PixelBuffer buffer(10, 0, defaultPixel), std::invalid_argument);
}

/*
 * TEST: AccessPixelInBounds
 * DESCRIPTION:
 * This test verifies that we can access a pixel within the bounds of the PixelBuffer without 
 * any exceptions.
 */
TEST(PixelBufferTest, AccessPixelInBounds) {
    Pixel defaultPixel;
    PixelBuffer buffer(10, 10, defaultPixel);
    EXPECT_NO_THROW(buffer.at(5, 5));
}

/*
 * TEST: AccessPixelOutOfBounds
 * DESCRIPTION:
 * This test verifies that attempting to access a pixel outside the bounds of the PixelBuffer 
 * results in an exception.
 */
TEST(PixelBufferTest, AccessPixelOutOfBounds) {
    Pixel defaultPixel;
    PixelBuffer buffer(10, 10, defaultPixel);
    EXPECT_THROW(buffer.at(10, 10), std::out_of_range);
}
