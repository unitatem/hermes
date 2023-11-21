#include "example/message_queue/message_queue.hpp"

#include <algorithm>
#include <iostream>
#include <thread>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

template <typename T>
void check_optional(const T& ref, const std::optional<T>& opt) {
    EXPECT_TRUE(opt);
    EXPECT_EQ(*opt, ref);
}

TEST(MessageQueueTest_SingleThread, send_receive) {
    // Given
    MessageQueue<int> mq;

    // When
    mq.send(1);
    mq.send(2);

    EXPECT_EQ(1, mq.receive());
    EXPECT_EQ(2, mq.receive());
}

TEST(MessageQueueTest_SingleThread, send_try_receive) {
    // Given
    MessageQueue<int> mq;

    // When
    mq.send(1);
    mq.send(2);

    check_optional(1, mq.try_receive());
    check_optional(2, mq.try_receive());
}

// TEST(MessageQueueTest_SingleThread, send_receive_from_empty_queue)
// Call to receive() on empty queue will hang

TEST(MessageQueueTest_SingleThread, send_try_receive_from_empty_queue) {
    // Given
    MessageQueue<int> mq;

    // When
    mq.send(1);

    check_optional(1, mq.try_receive());
    EXPECT_FALSE(mq.try_receive());
}

TEST(MessageQueueTest_MultiThread, send_receive) {
    // Given
    MessageQueue<int> mq;

    // When
    std::thread t_r{[&]() {
        for (int i = 1; i <= 2; ++i) {
            EXPECT_EQ(i, mq.receive());
        }
    }};

    std::thread t_s{[&]() {
        for (int i = 1; i <= 2; ++i) {
            mq.send(i);
        }
    }};

    t_s.join();
    t_r.join();
}

TEST(MessageQueueTest_MultiThread, send_receive_2) {
    // Given
    constexpr int producers_cnt = 10;
    constexpr int work_per_producer_cnt = 5000;
    constexpr int total_work_cnt = producers_cnt * work_per_producer_cnt;

    MessageQueue<int> mq;

    // When
    std::thread t_r{[&]() {
        std::vector<int> cnt_array(work_per_producer_cnt, 0);
        for (int i = 0; i < total_work_cnt; ++i) {
            auto e = mq.receive();
            ++cnt_array[e];
        }

        auto it = std::find_if(cnt_array.begin(), cnt_array.end(),
                               [](const int e) { return e != producers_cnt; });
        EXPECT_EQ(it, cnt_array.end())
            << "Unexpected amount of work done: " << *it;
    }};

    auto worker = [&]() {
        for (int i = 0; i < work_per_producer_cnt; ++i) {
            mq.send(i);
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < producers_cnt; ++i) {
        threads.emplace_back(worker);
    }

    for (auto& t : threads) {
        t.join();
    }
    t_r.join();
}
