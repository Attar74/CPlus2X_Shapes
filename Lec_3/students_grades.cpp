#include <iostream>

using namespace std;

int main()
{
    /*************** Students Grade *********************/
    int grade;
    cout << "Enter Student Grade" << endl;
    cin >> grade;

    if(grade > 100 || grade < 0) {
        cout << "Invalid grade please try again...";
    }
    else if (grade > 85) {
        cout << "Excellent";
    }
    else if (grade > 75) {
        cout << "Very Good";
    }
    else if (grade > 65) {
        cout << "Good";
    }
    else if (grade > 55) {
        cout << "Fair";
    }
    else if (grade > 45) {
        cout << "Weak";
    }
    else {
        cout << "Very Weak";
    }

    return 0;
}