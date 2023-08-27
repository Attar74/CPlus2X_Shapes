#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int h;
    cin >> h;

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