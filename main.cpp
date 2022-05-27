#include <iostream>
#include "header/fileHandler.h"
#include "header/checkHandler.h"
#include "header/outHandler.h"

#define SONGO 9

using namespace std;

/*
  TASK

DONE: Buat fungsi save ke file .txt
DONE: Buat fungsi load dari file .txt
DONE: Buat Struct player
DONE: Perbaiki fungsi play
DONE: Cek vertikal
DONE: Cek horizontal
DONE: Cek regional/box
DONE: Buat fungsi isCase
DONE: Buat fungsi isWin
DONE: Buat fungsi isLose
DONE: Warna pada SOAL(Default)
*/

/*
  GAME FLOW

1.  Main Menu, input username, jika nama sudah ada, beri pilihan buat akun baru
    dengan nama lain, atau main sebagai user itu.
2.  Jika didalam user itu sudah ada permainan sebelumnya, berikan 2 pilihan,
    newGame, atau loadGame, dan jikalau user memilih loadGame, maka panggil
    fungsi load untuk mengambil file save .txt dari user tersebut.
    **file save tiap tiap user terpisah
3.  Jika newGame, panggil fungsi generateBoard untuk menginisiasi soal Sudoku yang
    baru, dengan mengacak template soal-soal yang sudah ada.
*/

void menu();

struct player
{
  string username;
  int health = 5;
  string sudokuCase;
  int sudoku[SONGO][SONGO];
};

void play(player player)
{
  while (true)
  {
    system("cls");
    int sudokuCase[SONGO][SONGO];
    getCase(sudokuCase, player.sudokuCase);
    int sudokuAns[SONGO][SONGO];
    getCase(sudokuAns, player.sudokuCase);

    if (getSudokuAns(sudokuAns, 0, 0))
    {
      printSudoku(player.sudoku, sudokuCase, sudokuAns, player.health);
      if (isWin(player.sudoku))
        break;
      if (isLose(player.health))
        break;

      cout << "[X Y] (1 >= X, Y <= 9) || [0 to exit]\n";
      int row, col;

      cin >> col;
      if (col == 0)
      {
        saveCase(player.sudoku, player.sudokuCase, player.username);
        break;
      }
      cin >> row;

      if (isCase(sudokuCase, row - 1, col - 1))
        continue;

      cout << "[answer] (1 >= answer <= 9)\n";
      int answer;
      cin >> answer;
      if (isValidNumber(answer))
      {
        if (isValidAnswer(player.sudoku, row - 1, col - 1, answer))
        {
          if (!isCorrect(sudokuAns, row - 1, col - 1, answer))
            player.health--;

          player.sudoku[row - 1][col - 1] = answer;
        }
        else
        {
          player.health--;
        }
      }
    }
  }

  if (isWin(player.sudoku))
    cout << "You Win!\n";
  else if (isLose(player.health))
    cout << "Game Over\n";
  else
    menu();
}

void newGame()
{
  player newPlayer;

  string username;
  cout << "[username]\t: ";
  cin >> username;
  newPlayer.username = username;

  string sudokuCase = randomCase();
  newPlayer.sudokuCase = sudokuCase;

  getCase(newPlayer.sudoku, sudokuCase);
  play(newPlayer);
}

void loadGame()
{
  player loadPlayer;

  string username;
  cout << "[username]\t: ";
  cin >> username;

  loadPlayer.sudokuCase = loadCase(loadPlayer.sudoku, username);
  if (loadPlayer.sudokuCase == "")
  {
    menu();
  }
  else
  {
    loadPlayer.username = username;
    play(loadPlayer);
  }
}

void menu()
{
  system("CLS");
  cout << "Sudoku\n\n";
  cout << "1. New Game\n";
  cout << "2. Load Game\n";
  cout << "0. Exit\n";

  int in;
  cout << "[Input]\t: ";
  cin >> in;
  switch (in)
  {
  case 1:
  {
    newGame();
    break;
  }

  case 2:
  {
    loadGame();
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

int main()
{
  menu();

  return 0;
};