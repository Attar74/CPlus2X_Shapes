#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    float f = 15.5;
    char c = 'x';

    int* iptr = &i;
    float* fptr = &f;
    char* cptr = &c;

    cout << "i: " << i << " - &i: " << &i << " iptr: " << iptr << " *iptr: " << *iptr << endl;
    cout << "f: " << f << " - &f: " << &f << " fptr: " << fptr << " *fptr: " << *fptr << endl;
    cout << "c: " << c << " - &c: " << &c << " cptr: " << cptr << " *cptr: " << *cptr << endl;

    int arr[5];
    arr[0] = 1;
    arr[1] = 2;
    cout << arr << endl;
    cout << &arr[1] << endl;

    int students;
    int subjects;
    cin >> students;
    cin >> subjects;
    int** grades = new int* [students];

    for( int h = 0; h < students; h++) {
        grades[h] = new int[subjects];
    }

    for( int k = 0; k < students; k++) {
        for( int j = 0; i < subjects; j++) {
            cin >> grades[k][j];
        }
    }

    for( int h = 0; h < students; h++) {
        delete[] grades[h];
    }

    delete[] grades;

    return 0;
}