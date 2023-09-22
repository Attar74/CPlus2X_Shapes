#include <iostream>

using namespace std;

int main()
{
    /*************** AVERAGE / MEAN *********************/
    int sub1, sub2, sub3, sum = 0;
    cout << "Enter subject one grades: " << endl;
    cin >> sub1;
    cout << "Enter subject one grades: " << endl;
    cin >> sub2;
    cout << "Enter subject one grades: " << endl;
    cin >> sub3;
    sum = (sub1 + sub2+ sub3) / 3;

    cout << "Average: " << sum << endl;

    cout << "Mean: " << sum / 3 << endl;

    return 0;
}