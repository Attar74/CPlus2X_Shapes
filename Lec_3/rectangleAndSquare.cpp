#include <iostream>

using namespace std;

int main()
{
    char isSquare;
    cout << "is that a square, if Yes please Enter 'Y' if not press ant key for entering rectangle sides \n";
    cin >> isSquare;
    int h, w;
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
        for(int j = 0; j < w; j++) {
            if((i==0 || i==(h-1)) || (j==0 || j==(w-1))) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}