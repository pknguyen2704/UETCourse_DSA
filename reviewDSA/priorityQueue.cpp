#include <iostream>
#include <vector>

struct PriorityQueue {
public:
    void push(int value) {
        elements.push_back(value);
        heapifyUp();
    }

    int top() {
        if (empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        return elements[0];
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Priority queue is empty");
        }

        elements[0] = elements.back();
        elements.pop_back();
        heapifyDown();
    }

    bool empty() {
        return elements.empty();
    }

    size_t size() {
        return elements.size();
    }

private:
    std::vector<T> elements;

    void heapifyUp() {
        int index = size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (elements[index] < elements[parentIndex]) {
                std::swap(elements[index], elements[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown() {
        int index = 0;
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int smallestIndex = index;

            if (leftChildIndex < size() && elements[leftChildIndex] < elements[smallestIndex]) {
                smallestIndex = leftChildIndex;
            }

            if (rightChildIndex < size() && elements[rightChildIndex] < elements[smallestIndex]) {
                smallestIndex = rightChildIndex;
            }

            if (smallestIndex != index) {
                std::swap(elements[index], elements[smallestIndex]);
                index = smallestIndex;
            } else {
                break;
            }
        }
    }
};

int main() {
    PriorityQueue<int> pq;
    
    pq.push(10);
    pq.push(5);
    pq.push(15);
    
    std::cout << "Top element: " << pq.top() << std::endl;
    pq.pop();
    std::cout << "After popping, top element: " << pq.top() << std::endl;

    return 0;
}
