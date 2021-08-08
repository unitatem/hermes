#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <queue>
#include <stdexcept>

// It is not thread safe.
template <typename T>
class MessageQueue {
 public:
  void send(T msg) { queue.push(msg); }

  T receive() {
    if (queue.empty()) throw std::out_of_range("MessageQueue is empty.");

    auto e = queue.front();
    queue.pop();
    return e;
  }

 private:
  std::queue<T> queue;
};

#endif  // MESSAGE_QUEUE_HPP
