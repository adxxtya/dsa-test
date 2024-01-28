
  #include <iostream>

  using namespace std;

  void merge(int myArray[], int start, int mid, int end) {

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++) {
      a[i] = myArray[start + i];
    }

    for (int i = 0; i < n2; i++) {
      b[i] = myArray[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
      if (a[i] < b[j]) {
        myArray[k] = a[i];
        i++;
        k++;
      }
      else
      {
        myArray[k] = b[j];
        j++;
        k++;
      }
    }

    while (i < n1) {
      myArray[k] = a[i];
      i++;
      k++;
    }
      
    while (j < n2) {
      myArray[k] = b[j];
      j++;
      k++;
    }

  }

  void mergeSort(int myArray[], int start, int end) {
    if (start < end) {
      int mid = (start + end) / 2;

      mergeSort(myArray, start, mid);
      mergeSort(myArray, mid + 1, end);

      merge(myArray, start, mid, end);
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

    mergeSort(myArray, 0, arraySize - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < arraySize; i++)
    {
      cout << myArray[i] << " ";
    }

      return 0;
  }