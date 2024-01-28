
  #include <iostream>

  using namespace std;

  void selectionSort(int myArray[], int arraySize) {

    for (int i = 0; i < (arraySize - 1); i++) {
      int min_pos = i;

      for (int j = i + 1; j < arraySize; j++) {
        if (myArray[min_pos] > myArray[j]) {
          min_pos = j;
        }
      }

      if (min_pos != i) {
        int temp = myArray[i];
        myArray[i] = myArray[min_pos];
        myArray[min_pos] = temp;
      }
    }
  }

  int main() {

    int arraySize;

    cout << "Enter the size of the Array: ";
    cin >> arraySize;

    int *myArray = new int[arraySize];

    cout << endl
        << "Enter the Elements: " << endl;

    for (int i = 0; i < arraySize; i++) {
      cout << "Element " << i + 1 << ": ";
      cin >> myArray[i];
    }

    selectionSort(myArray, arraySize);

    cout << "Sorted Array: ";
    for (int i = 0; i < arraySize; i++) {
      cout << myArray[i] << " ";
    }

    return 0;
  }