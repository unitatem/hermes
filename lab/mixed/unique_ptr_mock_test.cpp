#include <iostream>
#include <memory>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ByMove;
using ::testing::Return;

class BaseLogger {
 public:
  virtual ~BaseLogger();
  virtual std::string log() const = 0;
};
BaseLogger::~BaseLogger() {}

class FileLogger : public BaseLogger {
 public:
  static const std::string ID;

  std::string log() const override { return ID; }
};
const std::string FileLogger::ID = "FileLogger::log()";

class LoggerFactory {
 public:
  std::unique_ptr<BaseLogger> create_logger() {
    return std::unique_ptr<BaseLogger>(new FileLogger());
  }
};

TEST(PolymorphicTest, get_FileLogger) {
  std::unique_ptr<BaseLogger> logger = LoggerFactory().create_logger();
  EXPECT_EQ(FileLogger::ID, logger->log());
}

// It is easy to compile it when raw pointer is returned.
class LoggerFactoryMock {
 public:
  MOCK_METHOD0(create_logger, std::unique_ptr<BaseLogger>());
};

TEST(PolymorphicTest, get_FileLoggerMock) {
  LoggerFactoryMock factory_mock;
  // ByMove is neede in order to return unique_ptr
  EXPECT_CALL(factory_mock, create_logger()).WillOnce(Return(ByMove(nullptr)));

  EXPECT_EQ(nullptr, factory_mock.create_logger());
}
