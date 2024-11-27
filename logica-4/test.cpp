#include <iostream>
#include <sstream>
#include "ElementsSorter.h"

using namespace std;
using namespace RiskyWorks;

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x)                                                              \
  {                                                                             \
    if (!(x))                                                                   \
      std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; \
  }

// Test for function1()
// You would need to write these even when using a framework
void test_elementsSorter(ElementsSorter elementsSorter)
{
  elementsSorter.elements =
      {"G", "B", "10", "D", "A", "X", "M", "14", "P", "L"};

  elementsSorter.sortElements();

  // Should sort correctly
  IS_TRUE(elementsSorter.elements[0] == "10");
  IS_TRUE(elementsSorter.elements[elementsSorter.elements.size() - 1] == "X");
}

int main(void)
{
  ElementsSorter elementsSorter;
  test_elementsSorter(elementsSorter);
}