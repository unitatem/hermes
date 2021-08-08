#include "../../src/message_queue/message_queue.hpp"

#include <iostream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(MessageQueueTest, send_receive) {
  MessageQueue<int> mq;

  // SUT
  mq.send(1);
  mq.send(2);

  EXPECT_EQ(1, mq.receive());
  EXPECT_EQ(2, mq.receive());
}

TEST(MessageQueueTest, send_receive_from_empty_queue) {
  MessageQueue<int> mq;

  // SUT
  mq.send(1);

  EXPECT_EQ(1, mq.receive());
  EXPECT_THROW(mq.receive(), std::out_of_range);
}