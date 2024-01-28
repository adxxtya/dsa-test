
  #include <iostream>
  #include <cstdlib>

  int top = -1;

  class Stack {
      int arr[1000];
      int max;

  public:
      Stack(int a) {
          max = a;
      }

      void Push(int x) {
          if (top == (max - 1)) {
              std::cout << "\nStack is full\n";
          } else {
              top++;
              arr[top] = x;
          }
      }

      void Pop() {
          if (top == -1) {
              std::cout << "\nStack is Empty\n";
          } else {
              top--;
          }
      }

      void Display() {
          if (top == -1) {
              std::cout << "\nStack is Empty\n";
          } else {
              for (int i = 0; i <= top; i++) {
                  std::cout << arr[i] << " --> ";
              }
          }
      }
  };

  int main() {
      int max, ch, no;
      std::cout << "\nEnter Size of An Array: ";
      std::cin >> max;
      Stack s(max);
      while (1) {
          std::cout << "\n1 For Push\n2 For Pop\n3 For Display\n\n";
          std::cout << "What to do next? ";
          std::cin >> ch;
          switch (ch) {
          case 1:
              std::cout << "\nEnter Element To Insert ";
              std::cin >> no;
              s.Push(no);
              break;
          case 2:
              s.Pop();
              s.Display();
              break;
          case 3:
              s.Display();
              break;
          }
      }
      return 0;
  }
