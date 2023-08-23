/**
 * main.cpp
 *
 * FERRER, Matt Brycen L.
 * ENGG 24 - F
 * Rook Moves
*/

#include <iostream> 

using namespace std;

/**
 * This is a recursive function that finds move sequences from
 * a given square (x,y). It stores the number of moves (moves) and 
 * the number of move sequences found (n). It also stores the 
 * coordinates in coords[10] (including start (1,1) and end (8,8))
*/
void findMoveSequences(int x, int y, int moves, int& n, 
  int coords[10])
{
  // store coordinates (x,y) of rook's current position
  coords[moves * 2] = x;
  coords[moves * 2 + 1] = y;

  if (moves == 4)  // check if 4 moves
  {
    if (x == 8 && y == 8)  // check if rook is on (8,8)
    {
      // print sequence stored in coords
      cout << ++n << " ";  // increment number of move sequences
      for (int i=0; i<10; i++)
      {
        cout << coords[i] << " ";
      }
      cout << "\n";
    }
  }

  // the rook is not allowed to reach (8,8) in less than 4 moves
  else
  {
    if (!(x == 8 && y == 8))
    {
      // if not 4 moves and rook is not on (8,8)
      for (int i=1; i<9; i++)  // iterate through all x
      {
        if (i != x)  // check that the rook has moved horizontally
        {
          findMoveSequences(i, y, moves + 1, n, coords);
        }
      }

      for (int j=1; j<9; j++)  // iterate through all y
      {
        if (j != y)  // check that the rook has moved vertically
        {
          findMoveSequences(x, j, moves + 1, n, coords);
        }
      }
    }
  }
}

int main()
{
  int n = 0;
  int * coords = new int[10];
  findMoveSequences(1, 1, 0, n, coords);
  
  return 0;
}
