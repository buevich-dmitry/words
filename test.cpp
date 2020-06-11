#include "text_processing.h"
#include <gtest/gtest.h>

TEST(TextProcessing, Test) {
    const std::vector<std::string> lines = {
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit,",
            "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
            "Ut enim ad minim veniam,",
            "quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.",
            "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore",
            "eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident,",
            "sunt in culpa qui officia deserunt mollit anim id est laborum"};

    const std::string word = "ut";

    const std::vector<std::string> expected_output = {
            " enim ad minim veniam,",
            "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore",
            "eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident,",
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit,",
            "quis nostrud exercitation ullamco laboris nisi  aliquip ex ea commodo consequat.",
            "sed do eiusmod tempor incididunt  labore et dolore magna aliqua.",
            "sunt in culpa qui officia deserunt mollit anim id est laborum"
    };
    ASSERT_EQ(expected_output, ProcessLines(lines, word));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}