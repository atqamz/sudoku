#include <fstream>
#include <ctime>
#define SONGO 9

using namespace std;

string randomCase()
{
  srand(time(0));
  string num = to_string((rand() % 8) + 1);
  return "case" + num;
}

void getCase(int (&sudoku)[SONGO][SONGO], string fileName)
{
  ifstream readFile("./case/" + fileName + ".txt");

  for (int i = 0; i < SONGO; i++)
  {
    readFile >> sudoku[i][0] >> sudoku[i][1] >> sudoku[i][2] >> sudoku[i][3] >> sudoku[i][4] >> sudoku[i][5] >> sudoku[i][6] >> sudoku[i][7] >> sudoku[i][8];
  }
  readFile.close();
}

void saveCase(int (&sudoku)[SONGO][SONGO], string choosenCase, string fileName)
{
  ofstream writeFile("./save/" + fileName + ".txt");

  writeFile << choosenCase << "\n";

  for (int i = 0; i < SONGO; i++)
  {
    string line = "";
    for (int j = 0; j < SONGO; j++)
    {
      line += to_string(sudoku[i][j]);
      if (j != SONGO - 1)
        line += " ";
    }

    if (writeFile.is_open())
    {
      writeFile << line << "\n";
      line = "";
    }
  }

  writeFile.close();
}

string loadCase(int (&sudoku)[SONGO][SONGO], string fileName)
{
  ifstream readFile("./save/" + fileName + ".txt");

  string sudokuCase;
  if (readFile.is_open())
  {
    readFile >> sudokuCase;

    for (int i = 0; i < SONGO; i++)
    {
      readFile >> sudoku[i][0] >> sudoku[i][1] >> sudoku[i][2] >> sudoku[i][3] >> sudoku[i][4] >> sudoku[i][5] >> sudoku[i][6] >> sudoku[i][7] >> sudoku[i][8];
    }
    readFile.close();
    return sudokuCase;
  }
  return "";
}