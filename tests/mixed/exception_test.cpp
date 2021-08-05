#include <iostream>
#include <sstream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct Base {
  static std::stringstream ss;

  static void reset() { ss = std::stringstream(); }
};
std::stringstream Base::ss;

class ExceptionTestFixture : public ::testing::Test {
 public:
  void SetUp() override { Base::reset(); }
};

struct ThrowInCtorBody : public Base {
  ThrowInCtorBody() {
    ss << "T";
    throw "ERROR";
  }
  ~ThrowInCtorBody() { ss << "t"; }
};

TEST_F(ExceptionTestFixture, after_failed_constructor_there_is_no_destructor) {
  try {
    auto obj = ThrowInCtorBody();
  } catch (...) {
    EXPECT_EQ(Base::ss.str(), "T");
    return;
  }
  FAIL() << "Should not reach this line";
}

struct Item : public Base {
  Item() { ss << "I"; }
  ~Item() { ss << "i"; }
};

struct CorruptedItem : public Base {
  CorruptedItem() {
    ss << "C";
    throw "ERROR";
  }
  ~CorruptedItem() { ss << "c"; }
};

struct Composite : public Base {
  Composite() = default;
  ~Composite() { ss << "o"; }

  Item o1;
  CorruptedItem o2;
  Item o3;
};

TEST_F(ExceptionTestFixture, contructed_members_are_destructed) {
  try {
    auto obj = Composite();
  } catch (...) {
    EXPECT_EQ(Base::ss.str(), "ICi");
    return;
  }
  FAIL() << "Should not reach this line";
}
