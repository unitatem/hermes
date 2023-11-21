#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <optional>
#include <queue>
#include <stdexcept>

#include "semaphore.hpp"

// Thread safe queue without max element limit.
template <typename T>
class MessageQueue {
public:
    MessageQueue() : queue_semaphore{0} {}

    // Add object to the queue.
    void send(T msg) {
        std::scoped_lock<decltype(queue_mutex)> lock{queue_mutex};
        queue.push(msg);

        queue_semaphore.release();
    }

    // Retrieve object from the queue.
    T receive() {
        queue_semaphore.acquire();

        std::scoped_lock<decltype(queue_mutex)> lock{queue_mutex};
        auto e = queue.front();
        queue.pop();

        return e;
    }

    std::optional<T> try_receive() {
        std::chrono::milliseconds duration{100};
        if (!queue_semaphore.try_acquire_for(duration)) {
            return {};
        }

        std::scoped_lock<decltype(queue_mutex)> lock{queue_mutex};
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
