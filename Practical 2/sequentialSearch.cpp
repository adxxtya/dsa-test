
  #include <iostream>
  using namespace std;

  int main()
  {
      int n;
      cout << "Enter the number of elements in the array: ";
      cin >> n;

      int a[100]; // Assuming a maximum of 100 elements for simplicity
      cout << "Enter the elements of the array:" << endl;
      for (int i = 0; i < n; i++)
      {
          cin >> a[i];
      }

      int no, pos = -1;
      cout << "Enter the element to be searched: ";
      cin >> no;

      for (int i = 0; i < n; i++)
      {
          if (a[i] == no)
          {
              pos = i;
              break;
          }
      }

      if (pos != -1)
      {
          cout << "\n Element is found at index " << pos;
      }
      else
      {
          cout << "\n Element is not found";
      }

      return 0;
  }
