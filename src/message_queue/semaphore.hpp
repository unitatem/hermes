#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <chrono>
#include <condition_variable>
#include <mutex>

class Semaphore {
 private:
  std::mutex mutex;
  std::condition_variable condition;
  int count;

 public:
  Semaphore(int cnt) : count{cnt} {}

  // Increase semaphore count.
  void release() {
    std::scoped_lock<decltype(mutex)> lock{mutex};
    ++count;
    condition.notify_one();
  }

  // Decrease semaphore count.
  void acquire() {
    std::unique_lock<decltype(mutex)> lock{mutex};
    while (!count) {
      condition.wait(lock);
    }
    --count;
  }

  bool try_acquire_for(std::chrono::milliseconds ms) {
    std::unique_lock<decltype(mutex)> lock{mutex};
    if (!count) {
      if (condition.wait_for(lock, ms) == std::cv_status::timeout) {
        return false;
      }
    }
    --count;
    return true;
  }
};

#endif  // SEMAPHORE_HPP
