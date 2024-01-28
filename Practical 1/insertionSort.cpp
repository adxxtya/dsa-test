
#include <iostream>

using namespace std;

int main() {

  int arraySize, i, j, key;

  cout << "Enter the number of Elements in the Array: ";
  cin >> arraySize;

  int *myArray = new int[arraySize];

  cout << endl
       << "Enter the Elements to be used in the Array" << endl;
  for (int i = 0; i < arraySize; i++) {
    cout << "Element " << i + 1 << ": ";
    cin >> myArray[i];
  }

  for (i = 1; i < arraySize; i++) {
    key = myArray[i];
    j = i - 1;

    while (j >= 0 && myArray[j] > key) {
      myArray[j + 1] = myArray[j];
      j = j - 1;
    }
    myArray[j + 1] = key;
  }

  cout << endl
       << "Sorted Array: ";
  for (i = 0; i < arraySize; i++) {
    cout << myArray[i] << " ";
  }

  return 0;
}