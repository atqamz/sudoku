#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#define N 9

using namespace std;

int sudoku[N][N];

string randomCase()
{
  srand(time(0));
  string num = to_string((rand() % 8) + 1);
  return "case" + num;
}

void getCase(string fileName = randomCase())
{
  ifstream inFile("../case/" + fileName + ".txt");

  for (int i = 0; i < N; i++)
  {
    inFile >> sudoku[i][0] >> sudoku[i][1] >> sudoku[i][2] >> sudoku[i][3] >> sudoku[i][4] >> sudoku[i][5] >> sudoku[i][6] >> sudoku[i][7] >> sudoku[i][8];
  }
  inFile.close();

  // tampilkan kasus
  // for (int i = 0; i < N; i++)
  // {
  //   for (int j = 0; j < N; j++)
  //   {
  //     cout << sudoku[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
}

int main()
{
  getCase();
}
