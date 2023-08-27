#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int h;
    cin >> h;
    int spaces = 0;
    int stares = h-1;

    for (int i = 0; i < h; i++) {
        for(int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for(int j = 0; j < stares; j++) {
            cout << "*";
        }
        spaces++;
        stares--;
        cout << endl;
    }
    
    return 0;
}