#include <iostream>

using namespace std;

int main()
{
    /*************** Installments *********************/
    int number_of_years = 0;
    int first_payment = 0;
    int total_payments = 0;
    int rest_payments = 0;
    cout << "Enter total_payment" << endl;
    cin >> total_payments;
    cout << "Enter first_payment" << endl;
    cin >> first_payment;
    cout << "Enter number of installment years" << endl;
    cin >> number_of_years;
    rest_payments = total_payments - first_payment;

    cout <<"You gonna pay "<< (rest_payments / number_of_years) << " EGP per year" << endl;





    return 0;
}