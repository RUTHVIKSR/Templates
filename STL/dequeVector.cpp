/**
 * Deque implementation using a vector
 * Note: push_front and pop_front are O(n)
 */
template<typename T>
class DequeVector {
private:
    std::vector<T> data;

public:
    DequeVector() = default;

    void push_front(const T& value) {
        data.insert(data.begin(), value);
    }

    void push_back(const T& value) {
        data.push_back(value);
    }

    void pop_front() {
        if (empty()) throw std::underflow_error("Deque is empty");
        data.erase(data.begin());
    }

    void pop_back() {
        if (empty()) throw std::underflow_error("Deque is empty");
        data.pop_back();
    }

    T& front() {
        if (empty()) throw std::underflow_error("Deque is empty");
        return data.front();
    }

    T& back() {
        if (empty()) throw std::underflow_error("Deque is empty");
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

// Example usage
int main() {
    DequeLinkedList<int> dll;
    dll.push_back(1);
    dll.push_front(0);
    dll.push_back(2);
    std::cout << "LinkedList Deque: ";
    while (!dll.empty()) {
        std::cout << dll.front() << " ";
        dll.pop_front();
    }
    std::cout << std::endl;

    DequeVector<int> dv;
    dv.push_back(1);
    dv.push_front(0);
    dv.push_back(2);
    std::cout << "Vector Deque: ";
    while (!dv.empty()) {
        std::cout << dv.front() << " ";
        dv.pop_front();
    }
    std::cout << std::endl;

    return 0;
}
