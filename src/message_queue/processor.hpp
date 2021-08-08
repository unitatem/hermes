#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <functional>
#include <thread>

#include "message_queue.hpp"

class Processor {
 public:
  using Message = std::function<void()>;

 private:
  bool terminate = false;
  MessageQueue<Message> mq;
  std::thread thread;

 public:
  Processor()
      : thread{[&]() {
          while (!terminate) {
            auto e = mq.receive();
            if (!e) continue;
            (*e)();
          }
        }} {}

  ~Processor() {
    send([&]() { terminate = true; });
    thread.join();
  }

  void send(Message msg) { mq.send(msg); }
};

#endif  // PROCESSOR_HPP
