#include <iostream>
#include "ElementsSorter.h"
#include "NavalBattle.h" 

using namespace std;
using namespace RiskyWorks;

int main()
{
  cout << "Welcome to elements sorter" << endl;
  cout << "Please type 10 elements, and they will be sorted later:" << endl;
  ElementsSorter elementsSorter;
  elementsSorter.readElements();
  elementsSorter.sortElements();
  elementsSorter.printElements();

  cout << "Welcome to NavalBattle" << endl;
  NavalBattle navalBattle;

  cout << "Initializing battlefield..." << endl;
  navalBattle.initializeGrid();
  navalBattle.placeShips();
  navalBattle.initializeStatistics();
  navalBattle.run();
}