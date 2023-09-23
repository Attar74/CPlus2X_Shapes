#include <iostream>

using namespace std;

int main()
{
  int h;
  cout << "Enter letter Height" << endl;
  cin >> h;
  int spaces = h-1;
  int stares = 1;

  for (int i = 0; i < h; i++) {
    for(int j = 0; j < spaces; j++) {
      cout << " ";
    }
    for(int j = 0; j < stares; j++) {
      if(i == h/2 && j <= h/2) {
        cout << "* ";
      } else if(i == 0 || j == 0 || (j == stares - 1 && i != h/2)) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    spaces--;
    stares+=2;
    cout << endl;
  }
  return 0;
}