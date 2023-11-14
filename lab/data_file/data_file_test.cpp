#include <fstream>
#include <string>

#include "gtest/gtest.h"

TEST(DataFileTest, loadFile) {
    const std::string myPath{"lab/data_file/resources/config.txt"};
    // Read-only mode is necessary when running under bazel sandbox
    std::ifstream myFile{myPath};

    if (!myFile.is_open()) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
    }
    EXPECT_TRUE(myFile.is_open());

    std::string myPayload;
    myFile >> myPayload;
    EXPECT_EQ("secret", myPayload);
}
