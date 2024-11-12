#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace RiskyWorks
{
  /*
   * Structure to hold the response of the calculator
   */
  enum EShape
  {
    SQUARE,
    RECTANGLE,
    TRIANGLE
  };

  inline const char *ToString(EShape v)
  {
    switch (v)
    {
    case SQUARE:
      return "Square";
    case RECTANGLE:
      return "Rectangle";
    case TRIANGLE:
      return "Triangle";
    default:
      return "[Unknown shape]";
    }
  }

  struct CalculatorResponse
  {
    double perimeter;
    EShape shape;

    void print()
    {
      ostringstream stringStream;
      stringStream << ToString(shape) << " perimeter: " << perimeter;
      cout << stringStream.str() << endl;
    }
  };

  /*
   * Structure to calculate the perimeter of a shape
   */
  struct GeometryCalculator
  {
    // Function to get a valid positive input from the user
    double getPositiveInput(const string &prompt)
    {
      double value;
      while (true)
      {
        cout << prompt;
        cin >> value;

        // Check if the input is valid and positive
        if (cin.fail() || value <= 0)
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input. Please enter a positive float/number.\n";
        }
        else
        {
          break;
        }
      }
      return value;
    }

    // Method to request the square side and calculate the perimeter
    CalculatorResponse calculateSquarePerimeter()
    {
      double side = getPositiveInput("Enter the length of the square's side: ");
      double perimeter = squarePerimeterFormula(side);

      return CalculatorResponse{perimeter, EShape::SQUARE};
    }

    double squarePerimeterFormula(double side)
    {
      return 4 * side;
    }

    // Method to request the rectangle sides and calculate the perimeter
    CalculatorResponse calculateRectanglePerimeter()
    {
      double length = getPositiveInput("Enter the length of the rectangle: ");
      double width = getPositiveInput("Enter the width of the rectangle: ");

      double perimeter = rectanglePerimeterFormula(length, width);

      return CalculatorResponse{perimeter, EShape::RECTANGLE};
    }

    double rectanglePerimeterFormula(double length, double width)
    {
      return 2 * (length + width);
    }

    // Method to request the sides of the triangle and calculate the perimeter
    CalculatorResponse calculateTrianglePerimeter()
    {
      double side1 = getPositiveInput("Enter the first side of the triangle: ");
      double side2 = getPositiveInput("Enter the second side of the triangle: ");
      double side3 = getPositiveInput("Enter the third side of the triangle: ");
      double perimeter = trianglePerimeterFormula(side1, side2, side3);
      return CalculatorResponse{perimeter, EShape::TRIANGLE};
    }

    double trianglePerimeterFormula(double side1, double side2, double side3)
    {
      return side1 + side2 + side3;
    }

    // Main method to run the algorithm
    void execute()
    {
      cout << "Select a shape to calculate the perimeter:\n";
      cout << "1. Square\n";
      cout << "2. Rectangle\n";
      cout << "3. Triangle\n";

      int choice;

      cin >> choice;

      CalculatorResponse calculatorResponse;
      bool shouldPrint = false;

      switch (choice)
      {
      case 1:
        calculatorResponse = calculateSquarePerimeter();
        shouldPrint = true;
        break;
      case 2:
        calculatorResponse = calculateRectanglePerimeter();
        shouldPrint = true;
        break;
      case 3:
        calculatorResponse = calculateTrianglePerimeter();
        shouldPrint = true;
        break;
      default:
        cout << "Invalid choice!" << endl;
        shouldPrint = false;
      }

      if (shouldPrint)
      {
        calculatorResponse.print();
      }
    }
  };
}