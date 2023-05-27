#include <gtest/gtest.h>
#include <SDL.h>

// This is a simple dummy test case
TEST(DummyTest, AlwaysTrue) {
    ASSERT_TRUE(true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}