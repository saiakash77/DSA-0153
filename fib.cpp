#include <iostream>

using namespace std;

int main() {
    int N;

    cout << "Enter the value of N: ";
    cin >> N;


    if (N < 0) {
        cout << "N should be a non-negative integer." << endl;
    } else if (N == 0) {
        cout << "Fibonacci number F(0) is 0." << endl;
    } else if (N == 1) {
        cout << "Fibonacci number F(1) is 1." << endl;
    } else {
        int prev1 = 0, prev2 = 1, current;

        for (int i = 2; i <= N; ++i) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        cout << "Fibonacci number F(" << N << ") is " << current << "." << endl;
    }

    return 0;
}
 
