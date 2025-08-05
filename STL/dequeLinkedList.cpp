#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * Deque implementation using a doubly linked list
 */
template<typename T>
class DequeLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val): data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    DequeLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~DequeLinkedList() {
        while (!empty()) pop_front();
    }

    void push_front(const T& value) {
        Node* node = new Node(value);
        if (empty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++count;
    }

    void push_back(const T& value) {
        Node* node = new Node(value);
        if (empty()) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        ++count;
    }

    void pop_front() {
        if (empty()) throw std::underflow_error("Deque is empty");
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        --count;
    }

    void pop_back() {
        if (empty()) throw std::underflow_error("Deque is empty");
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
        --count;
    }

    T& front() {
        if (empty()) throw std::underflow_error("Deque is empty");
        return head->data;
    }

    T& back() {
        if (empty()) throw std::underflow_error("Deque is empty");
        return tail->data;
    }

    bool empty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }
};
