#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    char isSquare;
    cout << "is that a square, if Yes please Enter 'Y' if not press ant key for entering rectangle sides \n";
    cin >> isSquare;
    int h, w;
    int spaces = 0;
    if(isSquare == 'y' || isSquare == 'Y') {
        cout << "Enter Square Side \n";
        cin >> h;
        w = h;
    } else {
        cout << "Enter Height \n";
        cin >> h;
        cout << "Enter Width \n";
        cin >> w;
    }

    for (int i = 0; i < h; i++) {
        for(int j = 0; j < spaces; j++) {
            if(i==0 || i==(h-1)){
                break;
            } else { 
                cout << " ";
            }
        }
        for(int j = 0; j < w; j++) {
            if(
                (i==0 || i==(h-1)) || 
                (j==0 || j==(w-1)) || 
                (i==j) || 
                (i == w-(j+1)) ||
                (h/2 == i)
            ) {
                cout << " *";
            } else if (w/2 == j) {
                (w%2!=0) ?
                cout << " *" : 
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}