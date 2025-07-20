#include <iostream>
#include <vector>
#include <deque>

// A monotonically decreasing queue.
// The front of the queue will always be the largest element.
class MonotonicQueue {
private:
    std::deque<int> dq;

public:
    // Pushes a value onto the queue, maintaining the decreasing property.
    void push(int val) {
        // Remove all elements from the back that are smaller than the new value.
        while (!dq.empty() && dq.back() < val) {
            dq.pop_back();
        }
        dq.push_back(val);
    }

    // Pops the element from the front of the queue.
    // In a sliding window, we only pop if the front element is the one
    // that's leaving the window.
    void pop(int val) {
        if (!dq.empty() && dq.front() == val) {
            dq.pop_front();
        }
    }

    // Returns the maximum element (the front of the queue).
    int front() {
        return dq.front();
    }
};
