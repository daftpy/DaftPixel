#include <gtest/gtest.h>
#include <model/PixelBuffer.h>

TEST(PixelBufferTest, ConstructWithValidParameters) {
    Pixel defaultPixel;
    PixelBuffer buffer(10, 10, defaultPixel);
    EXPECT_EQ(buffer.getWidth(), 10);
    EXPECT_EQ(buffer.getHeight(), 10);
}

TEST(PixelBufferTest, ConstructWithInvalidParameters) {
    Pixel defaultPixel;
    EXPECT_THROW(PixelBuffer buffer(0, 10, defaultPixel), std::invalid_argument);
    EXPECT_THROW(PixelBuffer buffer(10, 0, defaultPixel), std::invalid_argument);
}

TEST(PixelBufferTest, AccessPixelInBounds) {
    Pixel defaultPixel;
    PixelBuffer buffer(10, 10, defaultPixel);
    EXPECT_NO_THROW(buffer.at(5, 5));
}

TEST(PixelBufferTest, AccessPixelOutOfBounds) {
    Pixel defaultPixel;
    PixelBuffer buffer(10, 10, defaultPixel);
    EXPECT_THROW(buffer.at(10, 10), std::out_of_range);
}