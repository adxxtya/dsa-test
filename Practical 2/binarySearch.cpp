
  #include <iostream>
  using namespace std;

  int binarySearch(int arr[], int p, int r, int num)
  {
      if (p <= r)
      {
          int mid = (p + r) / 2;
          if (arr[mid] == num)
              return mid;
          if (arr[mid] > num)
              return binarySearch(arr, p, mid - 1, num);
          if (arr[mid] < num)
              return binarySearch(arr, mid + 1, r, num);
      }
      return -1;
  }

  int main(void)
  {
      int n;
      cout << "Enter the number of elements in the array: ";
      cin >> n;

      int arr[100]; // Assuming a maximum of 100 elements for simplicity
      cout << "Enter the sorted elements of the array:" << endl;
      for (int i = 0; i < n; i++)
      {
          cin >> arr[i];
      }

      int num;
      cout << "Enter the number to search: \n";
      cin >> num;

      // Sorting the array (if not already sorted)
      // You can use your sorting algorithm of choice here

      int index = binarySearch(arr, 0, n - 1, num);

      if (index == -1)
      {
          cout << num << " is not present in the array";
      }
      else
      {
          cout << "Number is present at index " << index << " in the array";
      }

      return 0;
  }
