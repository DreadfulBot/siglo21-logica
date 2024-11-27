#include <iostream>
#include <vector>
using namespace std;

const int GRID_SIZE = 10; // Size of the grid
const int NUM_SHIPS = 6;  // Number of ships
const int MAX_SHIP_SIZE = 5;

namespace RiskyWorks
{
  // Enumeration for ship direction
  enum class Direction
  {
    Horizontal,
    Vertical
  };

  // Structure to represent a Ship
  struct Ship
  {
    int startRow; // Starting row of the ship
    int startCol; // Starting column of the ship
    int size;     // Size of the ship
    int hits;
    Direction dir; // Direction (Horizontal or Vertical)

    // Constructor
    Ship(int row, int col, int s, Direction d)
        : startRow(row), startCol(col), size(s), dir(d) {}

    void hit()
    {
      ++this->hits;
    }

    bool isSunk()
    {
      if (this->hits == this->size)
      {
        cout << "Ship sunk!" << endl;
        return true;
      }
      else
      {
        cout << "Ship hit!" << "Has more " << this->size - this->hits << " lives" << endl;
        return false;
      }
    }

    // Method to check if a cell is part of this ship
    bool isHit(int row, int col) const
    {
      bool hit = false;

      if (dir == Direction::Horizontal)
      {
        hit = row == startRow && col >= startCol && col < startCol + size;
      }
      else
      { // Vertical
        hit = col == startCol && row >= startRow && row < startRow + size;
      }

      return hit;
    }
  };

  struct NavalBattle
  {
    vector<vector<char>> grid = vector<vector<char>>(GRID_SIZE);
    vector<Ship> ships;
    int totalHitsNeeded = 0;
    int hits = 0;

    void run()
    {
      cout << "Guess the locations of the hidden ships on a " << GRID_SIZE << "x" << GRID_SIZE << " grid" << endl;
      cout << "You have " << NUM_SHIPS << " ships to sink and " << totalHitsNeeded << " total hits" << endl;

      while (hits < totalHitsNeeded)
      {
        displayGrid();

        int row, col;
        cout << "\nEnter your guess (row column) divided by space(ex: 1 1): ";
        cin >> row >> col;

        // Validate input
        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
        {
          cout << "Invalid input. Try again.\n";
          continue;
        }
        else
        {
          cout << "You guessed: " << row << " " << col << endl;
        }

        // Check for a hit
        bool hit = false;
        // for (const Ship &ship : ships)
        for (int i = 0; i < ships.size(); i++)
        {
          Ship &ship = ships[i];

          if (ship.isHit(row, col))
          {
            hit = true;

            if (hit)
            {
              if (grid[row][col] == 'S')
              {
                cout << "Hit!\n";
                ship.hit();

                if (ship.isSunk())
                {
                  cout << "More ships: " << ships.size() - i << endl;
                }

                grid[row][col] = 'X'; // Mark as hit
                ++hits;
              }
              else
              {
                cout << "You already hit this spot.\n";
              }
            }
            break;
          }
        }

        if (!hit)
        {
          if (grid[row][col] == '~')
          {
            cout << "Miss.\n";
            grid[row][col] = 'O'; // Mark as miss
          }
          else
          {
            cout << "You already guessed this spot.\n";
          }
        }
      }

      cout << "\nCongratulations! You sunk all the ships!\n";
      displayGrid(true); // Reveal the grid at the end
    }

    void displayGrid(bool reveal = false)
    {
      cout << "  ";
      for (int col = 0; col < GRID_SIZE; ++col)
      {
        cout << col << " ";
      }
      cout << "\n";

      for (int row = 0; row < GRID_SIZE; ++row)
      {
        cout << row << " ";
        for (int col = 0; col < GRID_SIZE; ++col)
        {
          if (!reveal && grid[row][col] == 'S')
          {
            cout << "~ ";
          }
          else
          {
            cout << grid[row][col] << " ";
          }
        }
        cout << "\n";
      }
    }

    void initializeStatistics()
    {
      for (const Ship &ship : ships)
      {
        totalHitsNeeded += ship.size;
      }
    }

    // Function to initialize the grid with water ('~')
    void initializeGrid()
    {
      grid.assign(GRID_SIZE, vector<char>(GRID_SIZE, '~'));
    }

    // Function to place ships randomly on the grid
    void placeShips()
    {
      srand(time(0));
      int shipCount = 0;

      while (shipCount < NUM_SHIPS)
      {                                        // Place 3 ships
        int size = rand() % MAX_SHIP_SIZE + 1; // Ship size: 2 to 4

        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        Direction dir = (rand() % 2 == 0) ? Direction::Horizontal : Direction::Vertical;

        // Check if the ship fits in the grid and doesn't overlap
        bool fits = true;
        if (dir == Direction::Horizontal && col + size > GRID_SIZE)
        {
          fits = false;
        }
        else if (dir == Direction::Vertical && row + size > GRID_SIZE)
        {
          fits = false;
        }
        else
        {
          for (int i = 0; i < size; ++i)
          {
            if (dir == Direction::Horizontal && grid[row][col + i] != '~')
            {
              fits = false;
              break;
            }
            if (dir == Direction::Vertical && grid[row + i][col] != '~')
            {
              fits = false;
              break;
            }
          }
        }

        if (fits)
        {
          // Place the ship
          for (int i = 0; i < size; ++i)
          {
            if (dir == Direction::Horizontal)
            {
              grid[row][col + i] = 'S';
            }
            else
            {
              grid[row + i][col] = 'S';
            }
          }
          ships.emplace_back(row, col, size, dir);
          ++shipCount;
        }
      }
      cout << ships.size() << " ships placed!" << endl;
    }
  };
}