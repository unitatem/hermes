#include "example/message_queue/processor.hpp"

#include <iostream>
#include <sstream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(ProcessorTest, single_thread_processing) {
    std::stringstream ss;

    // SUT
    {
        Processor proc;
        proc.send([&]() { ss << "M1 "; });
        proc.send([&]() { ss << "M2 "; });
        proc.send([&]() { ss << "M3 "; });
        proc.send([&]() { ss << "M4 "; });
    }

    EXPECT_EQ("M1 M2 M3 M4 ", ss.str());
}
