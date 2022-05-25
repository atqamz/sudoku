#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream inFile("filename.txt");
  int i = 0;

  string date, time, datetime;

  time_t t1;
  float temprature;


  while (inFile >> date >> time >> datetime >> t1 >> temprature)
  {
    cout << " " << date << " " << t1 << " " << temprature << endl;
  }
  inFile.close();
  return 0;
}