#include <iostream>
using namespace std;

int Add(int num1, int num2) {
    return num1 + num2;
}

int Sub(int num1, int num2) {
    return num1 - num2;
}

int Mul(int num1, int num2) {
    return num1 * num2;
}

int Div(int num1, int num2) {
    if(num2 == 0){
        cout << "Can't divide by zero \n";
        return 0;
    }
    return num1 / num2;
}

int handleOperation(int num1, int num2, char operation) {
    switch(operation) {
        case '+':
            return Add(num1, num2);
            break;
        case '-':
            return Sub(num1, num2);
            break;
        case '*':
            return Mul(num1, num2);
            break;
        case '/':
            return Div(num1, num2);
            break;
        default:
            cout << "Invalid Char \n";
            return 0;
    }
}

int main () {
    int num1, num2;
    char operationSign;
    int result = 0;
    cout << "Enter first number \n";
    cin >> num1;

    char applyAnotherOperation = 'Y';
    do {
        cout << "Enter the number u want to make the operation to \n";
        cin >> num2;
        cout << "Pick up operation sign '+, -, *, /' \n";
        cin >> operationSign;

        result = handleOperation(num1, num2, operationSign);
        cout << "Result is = " << result << endl;
        num1 = result;
        cout << "Press Y to apply another operation ont the last result or Any other key to cancel \n";
        cin >> applyAnotherOperation;

    } while(applyAnotherOperation == 'Y');

    return 0;
}