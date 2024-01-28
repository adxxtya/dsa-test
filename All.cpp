// All Stack Implementations
// #include <iostream>
// using namespace std;
// int top = -1;

// class Stack
// {
//   int arr[1000];
//   int max;

//   public:
//     Stack(int a): max(a) {}

//     void push(int elm) {
//       if (top == (max - 1)) {
//         cout << "\nStack is full\n";
//       } else {
//         top++;
//         arr[top] = elm;
//       }
//     }

//     void pop() {
//       if (top == -1) {
//         cout << "\nStack is empty\n";
//       } else {
//         top--;
//       }
//     }

//     void peek() {
//       if (top == -1) {
//         cout << "\nNo elements in stack\n";
//       } else {
//         cout << arr[top];
//       }
//     }

//     void display() {
//       if (top == -1) {
//         cout << "\nNo elements in stack to display\n";
//       } else {
//         for (int i = 0; i <= top; i++)
//         {
//         cout << arr[i] << " --> ";
//         }
        
//       }
//     }
// };

// int main() {

//   int max, ch;

//   cout << "Enter the size of the Stack";
//   cin >> max;

//   Stack s(max);

//   while(1) {
//     cout << "\n1: Push an Element to Stack";
//     cout << "\n2: Peek an Element from Stack";
//     cout << "\n3: Pop an Element from Stack";
//     cout << "\n4: Display all Elements of Stack";
//     cout << "\n\nWhat to do next?: ";
//     cin >> ch;

//     switch (ch)
//     {
//       case 1:
//         cout << "Enter the element to be inserted: ";
//         int temp;
//         cin >> temp;
//         s.push(temp);
//         break;

//       case 2:
//         s.peek();
//         break;

//       case 3:
//         s.pop();
//         break;

//       case 4:
//         s.display();
//         break;
//       }
//   }

//       return 0;
// }



// Binary Search Tree
// #include <iostream>
// using namespace std;

// class Node {
//   public:
//     int key;
//     Node *left;
//     Node *right;

//   Node(int value): key(value), left(nullptr), right(nullptr) {}
// };

// class BST {
//   public:
//   Node *root;

//   BST(): root(nullptr) {}

//   Node *insert(Node *root,int key) {

//     if (root == nullptr) {
//       return new Node(key);
//     }

//     if (root -> key < key) {
//       root->right = insert(root->right, key);
//     }

//     if (root -> key > key) {
//       root->left = insert(root->left, key);
//     }

//     return root;
//   }

//   void findMax(Node *root) {
//     if (root == nullptr) {
//       cout << "Tree is empty";
//     }

//     Node *current = root;
//     while (current -> right != nullptr) {
//       current = current->right;
//     }

//     cout << "Largest node is: " << current -> key << endl;
//   }

//   void findMin(Node *root) {
//     if (root == nullptr) {
//       cout << "Tree is empty";
//     }

//     Node *current = root;
//     while (current -> left != nullptr) {
//       current = current->left;
//     }

//     cout << "Smallest node is: " << current -> key << endl;
//   }

//   void display(Node *root) {
//     if (root != nullptr) {
//       display(root->left);
//       cout << root->key << " ";
//       display(root->right);
//     }
//   }

//   // Node *deleteNode() {
    
//   // }
// };

// int main() {

//   BST bst;
//   int size, value;

//   cout << "Enter the elements in the tree: ";
//   cin >> size;

//   cout << "Enter the elements to be inserted in the tree:";
//   for (int i = 0; i < size; i++)
//   {
//     cin >> value;
//     bst.root = bst.insert(bst.root, value);
//   }

//   bst.findMax(bst.root);
//   bst.findMin(bst.root);
//   bst.display(bst.root);

//   return 0;
// }


// Selection Sort Algorithm
// #include <iostream>
// using namespace std;


// void selectionSort(int myArray[], int arraySize) {

//   for (int i = 0; i < arraySize; i++)
//   {
//     int min_pos = i;

//     for (int j = i + 1; j < arraySize; j++)
//     {
//       if(myArray[j] < myArray[min_pos]) {
//         min_pos = j;
//       }
//     }
    
//     if (i != min_pos) {
//       int temp = myArray[min_pos];
//       myArray[min_pos] = myArray[i];
//       myArray[i] = temp;
//     }
//   }
// }


// int main() {
//   int arraySize;

//   cout << "Enter the size of the array: ";
//   cin >> arraySize;

//   int *myArray = new int[arraySize];

//   cout << "Enter the elements one by one:\n";
//   for (int i = 0; i < arraySize; i++)
//   {
//     cout << "Element " << i + 1 << ": ";
//     cin >> myArray[i];
//   }

//   selectionSort(myArray, arraySize);

//   cout << "Sorted Array: ";
//   for (int i = 0; i < arraySize; i++)
//   {
//     cout << myArray[i] << " ";
//   }

//   return 0;
// }



// Ordinary Queue Implementation
// #include <iostream>
// using namespace std;

// const int MAX_SIZE = 1000;

// class Queue {
//   public:
//   int front, rear;
//   int myArray[MAX_SIZE];

//   Queue() : front(-1), rear(-1) {}

//   bool isFull() {
//     return rear == MAX_SIZE - 1;
//   }

//   bool isEmpty() {
//     return front == -1 && rear == -1;
//   }

//   void enqueue(int value) {
//     if (isFull()) {
//       cout << "Queue is full";
//     }

//     if (isEmpty()) {
//       front = 0;
//     }

//     rear++;
//     myArray[rear] = value;
//   }

//   void dequeue() {
//     if (isEmpty()) {
//       cout << "Queue is already empty";
//     } 

//     if (front == rear) {
//       front = rear = -1;
//     } else {
//       front++;
//     }
//   }

//   void display() {
//     if (isEmpty()) {
//       cout << "Queue is empty";
//     } 

//     for (int i = front; i <= rear; i++) {
//       cout << myArray[i] << " ";
//     }
//   }
// };

// int main() {
//   Queue queue;
//   int arraySize, temp, ch;

//   cout << "Enter the size of the array: ";
//   cin >> arraySize;



//   cout << "Enter the elements one by one:\n";
//   for (int i = 0; i < arraySize; i++)
//   {
//     cout << "Element " << i + 1 << ": ";
//     cin >> temp;
//     queue.enqueue(temp);
//   }

//   queue.display();
// }


// Postfix Evaluation using Stack
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int postfixEval(string str) {

  stack<int> stack;

  for (int i = 0; i < str.length(); i++)

    if (str[i] >= '0' && str[i] <= '9') {
      stack.push(str[i] - '0');
    } else {
      int op2 = stack.top();
      stack.pop();
      int op1 = stack.top();
      stack.pop();
      switch (str[i])
      {
      case '+':
        stack.push(op1 + op2);
        break;
      case '-':
        stack.push(op1 - op2);
        break;
      case '*':
        stack.push(op1 * op2);
        break;
      case '/':
        stack.push(op1 / op2);
        break;
      }
    }

    return stack.top();
}

int main() {

  cout << postfixEval("46+2/5*7+") << endl;

  return 0;
}