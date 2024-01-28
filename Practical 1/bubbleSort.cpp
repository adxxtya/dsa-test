  #include <iostream>

  using namespace std;

  int main() {

    int arraySize;

    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int *myArray = new int[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> myArray[i];
    }

    for (int i = 0; i < arraySize; i++) {
      for (int j = 0; j < arraySize - 1; j++) {
        if (myArray[j] > myArray[j + 1]) {
          int temp = myArray[j];
          myArray[j] = myArray[j + 1];
          myArray[j + 1] = temp;
        }
      }
    }

      cout << endl
          << "Elements in Sorted Order:" << endl;
    for (int i = 0; i < arraySize; i++) {

      cout << myArray[i] << " ";
    }

    return 0;
  }
