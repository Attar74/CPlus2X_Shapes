#include <iostream>

using namespace std;

int main()
{
    int h;
    cout << "Enter shape Height" << endl;
    cin >> h;
    int spaces = h-1;
    int stares = h-1;

    for (int i = 0; i < h; i++) {
        for(int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for(int j = 0; j < stares; j++) {
            cout << "*";
        }
        stares--;
        cout << endl;
    }
    
    return 0;
}