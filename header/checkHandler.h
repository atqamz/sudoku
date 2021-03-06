#include <iostream>
#define SONGO 9

using namespace std;

bool isCase(int (&sudokuCase)[SONGO][SONGO], int row, int col)
{
  if (sudokuCase[row][col] == 0)
    return false;

  return true;
}

bool isValidNumber(int number)
{
  if (number >= 1 && number <= 9)
    return true;
  else
    return false;
}

bool isInRow(int (&sudoku)[SONGO][SONGO], int row, int number)
{
  for (int col = 0; col < SONGO; col++)
    if (sudoku[row][col] == number)
      return true;
  return false;
}

bool isInCol(int (&sudoku)[SONGO][SONGO], int col, int number)
{
  for (int row = 0; row < SONGO; row++)
    if (sudoku[row][col] == number)
      return true;
  return false;
}

bool isInBox(int (&sudoku)[SONGO][SONGO], int boxStartRow, int boxStartCol, int number)
{
  for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
      if (sudoku[row + boxStartRow][col + boxStartCol] == number)
        return true;
  return false;
}

bool isCorrect(int (&sudokuAns)[SONGO][SONGO], int row, int col, int number)
{
  if (sudokuAns[row][col] == number)
    return true;

  return false;
}

bool isValidAnswer(int (&sudoku)[SONGO][SONGO], int row, int col, int number)
{
  return !isInRow(sudoku, row, number) && !isInCol(sudoku, col, number) && !isInBox(sudoku, row - row % 3, col - col % 3, number);
}

bool isWin(int (&sudoku)[SONGO][SONGO])
{
  for (int i = 0; i < SONGO; i++)
  {
    for (int j = 0; j < SONGO; j++)
    {
      if (sudoku[i][j] == 0)
        return false;
    }
  }
  return true;
}

bool isLose(int health)
{
  if (health == 0)
    return true;
  else
    return false;
}

bool getSudokuAns(int (&sudokuCase)[SONGO][SONGO], int row, int col)
{
  if (row == SONGO - 1 && col == SONGO)
    return true;
  if (col == SONGO)
  {
    row++;
    col = 0;
  }
  if (sudokuCase[row][col] > 0)
    return getSudokuAns(sudokuCase, row, col + 1);

  for (int num = 1; num <= SONGO; num++)
  {
    if (isValidAnswer(sudokuCase, row, col, num))
    {
      sudokuCase[row][col] = num;

      if (getSudokuAns(sudokuCase, row, col + 1))
        return true;
    }

    sudokuCase[row][col] = 0;
  }
  return false;
}