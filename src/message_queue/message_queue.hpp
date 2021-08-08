#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <optional>
#include <queue>
#include <stdexcept>

#include "semaphore.hpp"

template <typename T>
class MessageQueue {
 public:
  MessageQueue() : queue_semaphore(0) {}

  void send(T msg) {
    std::scoped_lock<decltype(queue_mutex)> lock(queue_mutex);
    queue.push(msg);

    queue_semaphore.release();
  }

  // Active listener
  std::optional<T> receive() {
    std::chrono::milliseconds duration(100);
    if (!queue_semaphore.try_acquire_for(duration)) {
      return {};
    }

    std::scoped_lock<decltype(queue_mutex)> lock(queue_mutex);
    auto e = queue.front();
    queue.pop();

    return e;
  }

 private:
  std::queue<T> queue;
  std::mutex queue_mutex;
  Semaphore queue_semaphore;
};

#endif  // MESSAGE_QUEUE_HPP
