
  #include <iostream>
  #include <vector>

  class HashTable {
  private:
      std::vector<int> table;
      int size;
      int numElements;
      int divisor; 
      int multiplier; 

  public:
      HashTable(int tableSize) : size(tableSize), numElements(0), divisor(0), multiplier(0) {
          table.resize(size, -1);
      }

      int DivisionHash(int key) {
          return key % divisor;
      }

      int MultiplicationHash(int key) {
          double A = 0.618033; 
          return int(size * (key * A - int(key * A)));
      }

      void InsertLinearProbe(int key) {
          int index;

          index = MultiplicationHash(key);

          while (table[index] != -1) {
              index = (index + 1) % size;
          }

          table[index] = key;
          numElements++;
      }

      void Display() {
          for (int i = 0; i < size; ++i) {
              std::cout << "Slot " << i << ": ";
              if (table[i] != -1) {
                  std::cout << table[i];
              }
              std::cout << std::endl;
          }
      }
  };

  int main() {
      int tableSize, numElements, element;
      
      std::cout << "Enter the size of the hash table: ";
      std::cin >> tableSize;

      HashTable hashTable(tableSize);

      std::cout << "Enter the number of elements: ";
      std::cin >> numElements;

      std::cout << "Enter the elements:\n";
      for (int i = 0; i < numElements; ++i) {
          std::cin >> element;
          hashTable.InsertLinearProbe(element);
      }

      std::cout << "Hash Table with Linear Probe:\n";
      hashTable.Display();

      return 0;
  }
