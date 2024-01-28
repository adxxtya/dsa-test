
  #include <iostream>

  class MyStack {
  private:
      char* arr;
      int capacity;
      int top;

  public:
      MyStack(int size) {
          capacity = size;
          arr = new char[size];
          top = -1;
      }

      ~MyStack() {
          delete[] arr;
      }

      void push(char c) {
          if (top == capacity - 1) {
              std::cout << "Stack overflow\n";
              return;
          }
          arr[++top] = c;
      }

      char pop() {
          if (isEmpty()) {
              std::cout << "Stack underflow\n";
              return '\0';
          }
          return arr[top--];
      }

      char peek() {
          if (isEmpty()) {
              std::cout << "Stack is empty\n";
              return '\0';
          }
          return arr[top];
      }

      bool isEmpty() {
          return top == -1;
      }
  };

  bool isBalanced(std::string expression) {
      MyStack stack(expression.length());

      for (char& c : expression) {
          if (c == '(' || c == '[' || c == '{') {
              stack.push(c);
          } else if (c == ')' || c == ']' || c == '}') {
              if (stack.isEmpty()) {
                  return false;
              }

              char top = stack.pop();

              if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                  return false;
              }
          }
      }

      return stack.isEmpty();
  }

  int main() {
      std::string expression;
      std::cout << "Enter an expression: ";
      std::getline(std::cin, expression);

      if (isBalanced(expression)) {
          std::cout << "Balanced\n";
      } else {
          std::cout << "Unbalanced\n";
      }

      return 0;
  }
