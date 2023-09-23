#include <iostream>

using namespace std;

int main()
{
    int h;
    cout << "Enter shape Height" << endl;
    cin >> h;
    int spaces = 0;
    int stares = (h*2)-1;

    for (int i = 0; i < h; i++) {
        for(int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for(int j = 0; j < stares; j++) {
            cout << "*";
        }
        spaces++;
        stares-=2;
        cout << endl;
    }
    return 0;
}