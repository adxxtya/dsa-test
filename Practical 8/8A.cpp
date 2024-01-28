#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

public:
    void Insert(int value) {
        heap.push_back(value);
        HeapifyUp(heap.size() - 1);
    }

    void Display() {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

private:
    void HeapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }
};

int main() {
    MinHeap minHeap;

    int n, value;
    std::cout << "Enter the number of elements in the MinHeap: ";
    std::cin >> n;

    std::cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        minHeap.Insert(value);
    }

    std::cout << "MinHeap elements: ";
    minHeap.Display();

    return 0;
}
