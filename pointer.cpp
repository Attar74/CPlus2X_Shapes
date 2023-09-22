#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int size;
    cin >> size;
    int* arr = new int [size];

    for(int j = 0; j < size; j++) {
        cin >> arr[j];
    }
    
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
        cout << " * " << endl;
        cout << &arr[i] << endl;
    }

    delete []arr;
    return 0;
}