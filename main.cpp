#include <iostream>
#include <fstream>

#define N 9

using namespace std;

// TODO: Buat fungsi save ke file .txt
// TODO: Buat fungsi load dari file .txt
// TODO: Perbaiki fungsi play, pisah ke fungsi generateBoard
// DONE: Cek vertikal
// DONE: Cek horizontal
// DONE: Cek regional/box
// TODO: Buat fungsi isWin
// TODO: Pisah fungsi Print dan Input ke masing-masing fungsi
// TODO: Buat logika Health dan validasi dengan fungsi gameOver
// TODO: Buat Struct player
// TODO: Warna pada SOAL(Default), JAWABAN JIKA BENAR(Green), JAWABAN JIKA SALAH(Red)

/*
FLOW
1.  Main Menu, input username, jika nama sudah ada, beri pilihan buat akun baru dengan nama lain, atau
    main sebagai user itu.
2.  Jika didalam user itu sudah ada permainan sebelumnya, berikan 2 pilihan, newGame, atau loadGame,
    dan jikalau user memilih loadGame, maka panggil fungsi load untuk mengambil file save .txt dari
    user tersebut. **file save tiap tiap user terpisah
3.  Jika newGame, panggil fungsi generateBoard untuk menginisiasi soal Sudoku yang baru, dengan mengacak
    template soal-soal yang sudah ada.
4.  User dapat memainkan permainan dengan 3 nyawa, jika nyawa habis, gameOver, lalu system pause dan
    kembali ke Main Menu.
*/

int sudoku[N][N];
bool isPlay = false;

void menu();
void play();
void printSudoku(int sudoku[N][N]);
bool isValidNumber(int number);

bool isInRow(int row, int number);
bool isInCol(int col, int number);
bool isInBox(int boxStartRow, int boxStartCol, int number);
bool isEmpty(int row, int col);
bool isValidAnswer(int row, int col, int number);

void menu()
{
  if (!isPlay)
  {
    cout << "Sudoku\n\n";
    cout << "1. Play\n";
    cout << "0. Exit\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      isPlay = true;
      play();
      break;
    }

    case 0:
    {
      exit(0);
      break;
    }

    default:
      break;
    }
  }
  else
  {
    play();
  }
}

void play()
{
  while (true)
  {
    system("cls");
    printSudoku(sudoku);
    cout << "\nInput your choice: [X Y] (1 >= X, Y <= 9)\n";
    int row, col;
    cin >> col >> row;
    if (!isEmpty(row, col))
    {
      continue;
    }

    cout << "Input your number: [number] (1 >= number <= 9)\n";
    int number;
    cin >> number;
    if (isValidNumber(number))
    {
      if (isValidAnswer(row - 1, col - 1, number))
      {
        sudoku[row - 1][col - 1] = number;
      }
    }
  }
}

void printSudoku(int sudoku[N][N])
{
  int y = 1;
  for (int row = 0; row < N; row++)
  {
    if (row == 0)
    {
      for (int x = 0; x < N; x++)
      {
        if (x == 0)
          cout << "   X ";

        if (x == 3 || x == 6)
          cout << " ";

        cout << " " << x + 1 << " ";
      }

      cout << "\nY  \n\n";
    }

    for (int col = 0; col < N; col++)
    {
      if (col == 0)
      {
        cout << y << "    ";
        y++;
      }
      if (col == 3 || col == 6)
        cout << "|";
      cout << " " << sudoku[row][col] << " ";
    }
    if (row == 2 || row == 5)
    {
      cout << "\n      ";
      for (int i = 0; i < N; i++)
        cout << "---";
    }
    cout << "\n";
  }
}

bool isValidNumber(int number)
{
  if (number >= 1 && number <= 9)
    return true;
  else
    return false;
}

bool isInRow(int row, int number)
{
  for (int col = 0; col < N; col++)
    if (sudoku[row][col] == number)
      return true;
  return false;
}

bool isInCol(int col, int number)
{
  for (int row = 0; row < N; row++)
    if (sudoku[row][col] == number)
      return true;
  return false;
}

bool isInBox(int boxStartRow, int boxStartCol, int number)
{
  for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
      if (sudoku[row + boxStartRow][col + boxStartCol] == number)
        return true;
  return false;
}

bool isEmpty(int row, int col)
{
  if (sudoku[row][col] == 0)
    return true;
  else
    return false;
}

bool isValidAnswer(int row, int col, int number)
{
  return !isInRow(row, number) && !isInCol(col, number) && !isInBox(row - row % 3, col - col % 3, number);
}

int main()
{
  system("CLS");
  menu();

  return 0;
};