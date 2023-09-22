#include <iostream>

using namespace std;

int main()
{
    /*************** RECTANGLE *********************/
    float w = 0;
    float h = 0;
    cout << "Enter Rectangle Width: ";
    cin >> w;
    cout << "Enter Rectangle Height: ";
    cin >> h;
    cout << "Area is: " << w * h << endl;
    cout << "Perimeter is: " << (w + h) * 2 << endl;

    /*************** SQUARE *********************/
    float s = 0;
    cout << "Enter Square side: ";
    cin >> s;
    cout << "Area is: " << s * s << endl;
    cout << "Perimeter is: " << s * 4 << endl;

    /*************** CIRCLE *********************/
    float r = 0;
    cout << "Enter circle radius: ";
    cin >> r;
    cout << "Area is: " << 3.14 * (r * r) << endl; // we can use power (pow) method in cmath library -> #include <cmath>
    cout << "Perimeter is: " << 2 * 3.14 * r << endl;

    /*************** Rhombus *********************/
    float r1 = 0;
    float r2 = 0;
    float sr = 0;
    cout << "Enter Rhombus radius 1: ";
    cin >> r1;
    cout << "Enter Rhombus radius 2: ";
    cin >> r2;
    cout << "Area is: " << (0.5) * r1 * r2 << endl;
    cout << "Enter Rhombus Side :";
    cin >> sr;
    cout << "Perimeter is: " << sr * 4 << endl;

    return 0;
}