// #include <iostream>
// #include <queue>
// using namespace std;

// int main()
// {
//     int numQueues;
//     cout << "Enter the number of queues: ";
//     cin >> numQueues;

//     vector<queue<int>> queues(numQueues);

//     for (int i = 0; i < numQueues; ++i) {
//         int size;
//         cout << "Enter the size of Queue " << i + 1 << ": ";
//         cin >> size;

//         cout << "Enter elements for Queue " << i + 1 << ":\n";
//         for (int j = 0; j < size; ++j) {
//             int element;
//             cout << "Element " << j + 1 << ": ";
//             cin >> element;
//             queues[i].push(element);
//         }
//     }

//     while (true) {
//         cout << "\nOperations:\n";
//         cout << "1. Enqueue\n";
//         cout << "2. Dequeue\n";
//         cout << "3. Display\n";
//         cout << "4. Exit\n";

//         int choice;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         int queueIndex;
//         switch (choice) {
//             case 1:
//                 cout << "Enter the queue index to enqueue: ";
//                 cin >> queueIndex;
//                 if (queueIndex >= 0 && queueIndex < numQueues) {
//                     int element;
//                     cout << "Enter the element to enqueue: ";
//                     cin >> element;
//                     queues[queueIndex].push(element);
//                     cout << "Enqueued " << element << " into Queue " << queueIndex + 1 << "\n";
//                 } else {
//                     cout << "Invalid queue index\n";
//                 }
//                 break;

//             case 2:
//                 cout << "Enter the queue index to dequeue: ";
//                 cin >> queueIndex;
//                 if (queueIndex >= 0 && queueIndex < numQueues) {
//                     if (!queues[queueIndex].empty()) {
//                         int frontElement = queues[queueIndex].front();
//                         queues[queueIndex].pop();
//                         cout << "Dequeued " << frontElement << " from Queue " << queueIndex + 1 << "\n";
//                     } else {
//                         cout << "Queue " << queueIndex + 1 << " is empty\n";
//                     }
//                 } else {
//                     cout << "Invalid queue index\n";
//                 }
//                 break;

//             case 3:
//                 cout << "Displaying all queues:\n";
//                 for (int i = 0; i < numQueues; ++i) {
//                     cout << "Queue " << i + 1 << ": ";
//                     queue<int> tempQueue = queues[i];
//                     while (!tempQueue.empty()) {
//                         cout << tempQueue.front() << " ";
//                         tempQueue.pop();
//                     }
//                     cout << "\n";
//                 }
//                 break;

//             case 4:
//                 cout << "Exiting program\n";
//                 return 0;

//             default:
//                 cout << "Invalid choice\n";
//         }
//     }

//     return 0;
// }


#include <iostream>

const int MAX_SIZE = 100;

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
        std::cout << "Enqueued: " << value << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        std::cout << "Dequeued: " << arr[front] << std::endl;

        if (front == rear) {
            front = rear = -1; // Reset to empty queue
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        int i = front;
        std::cout << "Queue elements: ";
        while (true) {
            std::cout << arr[i] << " ";

            if (i == rear) break;

            i = (i + 1) % MAX_SIZE;
        }

        std::cout << std::endl;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.enqueue(4);
    myQueue.display();

    return 0;
}
