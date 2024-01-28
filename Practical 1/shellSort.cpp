
  #include  <iostream> 
  using namespace std; 
    
  int shellSort(int arr[], int n)  { 
      for (int gap = n/2; gap > 0; gap /= 2) { 
          for (int i = gap; i < n; i += 1) { 
              int temp = arr[i];      
              for (int j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                  arr[j] = arr[j - gap]; 
                }
              arr[j] = temp; 
          } 
      } 
      return 0; 
  } 
    
  int main() { 
    
    int arraySize;

    cout << "Enter the number of Elements in the Array: ";
    cin >> arraySize;

    int *myArray = new int[arraySize];

    cout << endl
        << "Enter the Elements to be used in the Array" << endl;
    for (int i = 0; i < arraySize; i++) {
      cout << "Element " << i + 1 << ": ";
      cin >> myArray[i];
    }
    
      shellSort(myArray, arraySize); 
    
      cout << "\nArray after sorting: \n"; 
      for (int i = 0; i < arraySize; i++) {
      cout << myArray[i] << " ";
    }
    
      return 0; 
  } 