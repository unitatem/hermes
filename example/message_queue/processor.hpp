#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <functional>
#include <thread>

#include "message_queue.hpp"

// Safety wrapper around thread processing messages from internal message queue.
class Processor {
public:
    using Message = std::function<void()>;

private:
    bool terminate = false;
    MessageQueue<Message> mq;
    std::thread thread;

public:
    // Starts thread for messages processing.
    Processor()
        : thread{[&]() {
              while (!terminate) {
                  // Get next message from the queue and start processing.
                  // All logic for processing is encapsulated inside message.
                  mq.receive()();
              }
          }} {}

    ~Processor() {
        // Adds last message in the queue. Message will allow while from
        // processing thread to finish.
        send([&]() { terminate = true; });
        thread.join();
    }

    // Stores message in the queue for later processing.
    void send(Message msg) { mq.send(msg); }
};

#endif  // PROCESSOR_HPP
