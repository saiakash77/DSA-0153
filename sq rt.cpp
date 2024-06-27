#include <iostream>
#include <cmath>

using namespace std;


void findSquareRoot(double number) {
    if (number < 0) {
        cout << "Square root of a negative number is not defined in real numbers." << endl;
    } else {
        double sqrtResult = sqrt(number);
        cout << "The square root of " << number << " is " << sqrtResult << endl;
    }
}


inline void increment(int &number) {
    number++;
}


inline void decrement(int &number) {
    number--;
}

int main() {
   
    double num;
    cout << "Enter a number to find its square root: ";
    cin >> num;
    findSquareRoot(num);

   
    int value;
    cout << "Enter an integer value: ";
    cin >> value;
    increment(value);
    cout << "After incrementing, the value is: " << value << endl;

    decrement(value);
    cout << "After decrementing, the value is: " << value << endl;

    return 0;
}

