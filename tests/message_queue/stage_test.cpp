#include "../../src/message_queue/stage.hpp"

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(StageTest, format_string) {
  std::stringstream ss;

  // When
  {
    Stage print{[&](std::string str) { ss << str; }};

    Stage to_lower{[&](std::string str) {
      std::string tmp;
      for (const auto& c : str) tmp += std::tolower(c);
      print.process(tmp);
    }};

    Stage remove_white_space{[&](std::string str) {
      std::string tmp;
      for (const auto& c : str) {
        if (c == ' ') continue;
        tmp += c;
      }
      to_lower.process(tmp);
    }};

    remove_white_space.process("T  E    S T\n");
  }

  // Then
  EXPECT_EQ("test\n", ss.str());
}
