#include "src/message_queue/stage.hpp"

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(StageTest, format_string) {
  // Given
  std::stringstream ss;
  using StringEditor = Stage<std::string>;

  // When
  {
    StringEditor print{[&](std::string str) { ss << str; }};

    StringEditor to_lower{[&](std::string str) {
      std::string tmp;
      for (const auto& c : str) tmp += std::tolower(c);
      print.process(tmp);
    }};

    StringEditor remove_white_space{[&](std::string str) {
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
