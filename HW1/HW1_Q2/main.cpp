//---------------------------------------------------------------------
//
// Name:    Burak Karataş
//
// Course:  Computer Engineering, 2nd Year
//
// Student ID: 64200045
//
// Purpose: Checking the result of equation is prime or not. If result is prime
// program will print the number.
//---------------------------------------------------------------------

#include<iostream>
#include <list>
#include <cmath>
using namespace std;

int main(){

    // I created list of prime numbers
    std::list< unsigned long long int> Prime_Numbers;

    for (int i = 0; i<32; i++) {

        // Boolean for checking prime number
        bool IsPrime = true;

        // I defined equation here
        unsigned long long int pn = pow(3, i) - pow(2, i);

        // We are checking here pn = prime or not
        if (pn == 0 || pn == 1) IsPrime = false;

        else {
            for (int j = 2; j <= pn / 2; j++)

                if (pn % j == 0) {
                    IsPrime = false;
                    break;
                };
        }

        if (IsPrime == true)

            // We are adding prime numbers to the list
            Prime_Numbers.push_back(pn);
    }
    // Printing list
    for ( unsigned long long int val : Prime_Numbers)
        cout << val << ",";
    cout << endl;

    return 0;
}











