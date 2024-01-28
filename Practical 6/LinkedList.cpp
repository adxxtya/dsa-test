#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void InsertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void InsertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void DeleteAtBeginning() {
        if (head != nullptr) {
            Node* temp = head;
            head = temp->next;
            delete temp;
        }
    }

    void DeleteAtEnd() {
        if (head != nullptr) {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            if (prev != nullptr) {
                prev->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int length;
    cout << "Enter the length of the linked list: ";
    cin >> length;

    SinglyLinkedList sll;

    cout << "Enter the elements of the linked list:" << endl;
    for (int i = 0; i < length; ++i) {
        int element;
        cin >> element;
        sll.InsertAtEnd(element);
    }

    sll.Display();

    int choice;
    do {
        cout << "\nChoose an operation:\n1. Insert at Beginning\n2. Insert at End\n3. Delete at Beginning\n4. Delete at End\n5. Display\n6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                int element;
                cout << "Enter the element to insert at the beginning: ";
                cin >> element;
                sll.InsertAtBeginning(element);
                break;
            case 2:
                cout << "Enter the element to insert at the end: ";
                cin >> element;
                sll.InsertAtEnd(element);
                break;
            case 3:
                sll.DeleteAtBeginning();
                break;
            case 4:
                sll.DeleteAtEnd();
                break;
            case 5:
                sll.Display();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please choose a valid operation.\n";
        }
    } while (choice != 6);

    return 0;
}
