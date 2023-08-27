#include <iostream>
#include <vector>
#include <string>

using namespace std;

int aShape(int h) {
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

int hShape(int h) {
  int stares = 1;

  for (int i = 0; i < h; i++) {
    for(int j = 0; j < h; j++) {
        if(i == h/2) {
            cout << "* ";
        }
        else if((j==0 || j==(h-1))) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << endl;
    }
  return 0;
}

int mShape(int h) {
  int spaces = h-1;
  int stares = 1;

  for (int i = 0; i < h; i++) {
    for(int j = 0; j < spaces; j++) {
      cout << " ";
    }
    for(int j = 0; j < stares; j++) {
      if(i == 0 || j == 0 || j == stares - 1) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    for(int j = 0; j < spaces; j++) {
      cout << "  ";
    }
    for(int j = 0; j < stares; j++) {
      if(i == 0 || j == 0 || j == stares - 1) {
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

int oShape(int h) {
  int stares = 1;

  for (int i = 0; i < h; i++) {
    for(int j = 0; j < h; j++) {
        if(
            (i==0&&j!=0&&j!=h-1) ||
            ((j==0&&i!=h-1&&i!=0) || 
            (j==(h-1)&&(i != h-1)&&i!=0) || 
            (i==(h-1)&&j!=0&&j!=h-1) 
            )) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << endl;
    }

  return 0;
}

int uShape(int h) {

  int stares = 1;

  for (int i = 0; i < h; i++) {
    for(int j = 0; j < h; j++) {
        if(((j==0&&i!=h-1) || (j==(h-1)&&(i != h-1)) || (i==(h-1)&&j!=0&&j!=h-1) )) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << endl;
  }
  return 0;
}

int dShape (int h) {
  for (int i = 0; i < h; i++) {
    for(int j = 0; j < h; j++) {
        if(((i==0&&j!=h-1) || (i==(h-1)&&j!=h-1)) || (j==0 || (j==(h-1)&&i!=0&&i!=h-1))) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << endl;
  }
  return 0;
}


int main()
{
  char letter;
  cout << "Enter on of next letters 'A - M - H - O - U - D' \n";
  cin >> letter;
  int h = 11;

  switch (letter)
  {
  case 'M':
  case 'm':
    mShape(h);
    break;
  case 'A':
  case 'a':
    aShape(h);
    break;
  case 'H':
  case 'h':
    hShape(h);
    break;
  case 'O':
  case 'o':
    oShape(h);
    break;
  case 'U':
  case 'u':
    uShape(h);
    break;
  case 'D':
  case 'd':
    dShape(h);
    break;
  default:
    cout << "It's not in our list, We R working on this letter \n";
    break;
  }

  return 0;
}