#include <iostream>
#include <stdexcept>
using namespace std;


float divide(float x, float y) {
    if(y==0) {
        throw std::invalid_argument("Can't Divided by zero!");
    }
    return x / y;
}
int main() {
    float x, y;
    cin >> x >> y;

    try {
        cout << "Result: " << divide(x, y) << endl;
    } catch (std::invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}