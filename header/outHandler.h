#include <iostream>
#define SONGO 9
#define NC "\e[0m"
#define CYN "\e[0;36m"
#define GRN "\e[0;32m"

using namespace std;

void printSudoku(int (&sudoku)[SONGO][SONGO], int (&sudokuCase)[SONGO][SONGO], int (&sudokuAns)[SONGO][SONGO], int health)
{
  int y = 1;
  for (int row = 0; row < SONGO; row++)
  {
    if (row == 0)
    {
      for (int x = 0; x < SONGO; x++)
      {
        if (x == 0)
          cout << "   X ";

        if (x == 3 || x == 6)
          cout << " ";

        cout << " " << x + 1 << " ";

        if (x == 8)
          cout << "    HP: " << health;
      }

      cout << "\nY  \n\n";
    }

    for (int col = 0; col < SONGO; col++)
    {
      if (col == 0)
      {
        cout << y << "    ";
        y++;
      }
      if (col == 3 || col == 6)
        cout << "|";

      if (!isCase(sudokuCase, row, col))
      {
        if (isCorrect(sudokuAns, row, col, sudoku[row][col]))
          cout << " " GRN << sudoku[row][col] << NC " ";
        else
          cout << " " CYN << sudoku[row][col] << NC " ";
      }
      else
        cout << " " << sudoku[row][col] << " ";
    }
    if (row == 2 || row == 5)
    {
      cout << "\n      ";
      for (int i = 0; i < SONGO; i++)
        cout << "---";
    }
    cout << "\n";
  }
  cout << "\n";
}