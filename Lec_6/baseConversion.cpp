#include <iostream>
using namespace std;
int decimalTobinary(int num) {
    int res = 0;
    int mul = 1;
    while(num != 0) {
        int mod = num % 2;
        num /=2;
        res += mul * mod;
        mul *= 10;
    }
    return res;
}

int binaryToDecimal(int num) {
    int res = 0;
    int mul = 1;
    while(num != 0) {
        int mod = num % 10;
        num /=10;
        res += mul * mod;
        mul *= 2;
    }
    return res;
}

int decimalToOctal(int num) {
    int res = 0;
    int mul = 1;
    while(num != 0) {
        int mod = num % 8;
        num /=8;
        res += mul * mod;
        mul *= 10;
    }
    return res;
}

int octalToDecimal(int num) {
    int res = 0;
    int mul = 1;
    while(num != 0) {
        int mod = num % 10;
        num /=10;
        res += mul * mod;
        mul *= 8;
    }
    return res;
}
int main () {
    int num = 0;
    int operationNumber = 0;
    char isContinue = 'Y';
    while (isContinue == 'Y') {
        do {
            cout << "Enter the number u want to converse \n";
            cin >> num;
            cout << "Enter number of the operation you want to do 1 to 4 \n";
            cout << "1- Decimal to binary \n";
            cout << "2- Binary to decimal \n";
            cout << "3- Decimal to octal \n";
            cout << "4- Octal to decimal \n";
            cin >> operationNumber;
        } while (operationNumber > 4 || operationNumber < 1);

        switch (operationNumber) {
            case 1:
                cout << decimalTobinary(num);
                break;
            case 2:
                cout << binaryToDecimal(num);
                break;
            case 3:
                cout << decimalToOctal(num);
                break;
            case 4:
                cout << octalToDecimal(num);
                break;
            default:
                break;
        }

        cout << "\n Press Y to continue \n";
        cin >> isContinue;
    }
    return 0;
}