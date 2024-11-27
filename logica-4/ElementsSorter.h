#include <iostream>
#include <vector>
using namespace std;

namespace RiskyWorks
{
  struct ElementsSorter
  {
    vector<string> elements = vector<string>(10);

    void sortElements()
    {
      // quicksort is used here, from standard lib
      sort(begin(elements), end(elements));
    }

    void readElements()
    {
      for (int i = 0; i < 10; i++)
      {
        cout << "Enter element " << i << ": ";
        cin >> elements[i];
      }

      cout << "Elements read!" << endl;
    }

    void printElements()
    {
      cout << "Minimum element: " << elements.front() << endl;
      cout << "Max element: " << elements.back() << endl;
    }
  };
}