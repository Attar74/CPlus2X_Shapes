#include <iostream>
#include <fstream>
using namespace std;



int main() {
    ofstream out("out.txt");
    ifstream in("input.txt");
    int x, y;
    while (!in.eof()) {
        in >> x >> y;
        out << "x + y = " << x + y << endl;
    }
    in.close();
    out.close();
    return 0;
}