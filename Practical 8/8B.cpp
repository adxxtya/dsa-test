
    #include <iostream>
    #include <vector>

    class MaxHeap {
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
                if (heap[index] > heap[parentIndex]) {
                    std::swap(heap[index], heap[parentIndex]);
                    index = parentIndex;
                } else {
                    break;
                }
            }
        }
    };

    int main() {
        MaxHeap maxHeap;

        int n, value;
        std::cout << "Enter the number of elements in the MaxHeap: ";
        std::cin >> n;

        std::cout << "Enter the elements:\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> value;
            maxHeap.Insert(value);
        }

        std::cout << "MaxHeap elements: ";
        maxHeap.Display();

        return 0;
    }
