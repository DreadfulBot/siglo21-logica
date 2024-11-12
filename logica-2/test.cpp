#include <iostream>
#include <sstream>
#include "GeometryCalculator.h"

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
void test_calculatePerimeterFormulas(GeometryCalculator calculator)
{
  IS_TRUE(16 == calculator.squarePerimeterFormula(4));
  IS_TRUE(20 == calculator.squarePerimeterFormula(5));

  IS_TRUE(12 == calculator.trianglePerimeterFormula(4, 4, 4));
  IS_TRUE(7 == calculator.trianglePerimeterFormula(2, 3, 2));

  IS_TRUE(30 == calculator.rectanglePerimeterFormula(10, 5));
  IS_TRUE(62 == calculator.rectanglePerimeterFormula(20, 11));
}

int main(void)
{
  GeometryCalculator calculator;
  test_calculatePerimeterFormulas(calculator);
}