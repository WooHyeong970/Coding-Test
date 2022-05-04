#include <iostream>

using namespace std;

double pi = 3.141592;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double d1, d2;
    cin >> d1 >> d2;
    cout.setf(ios::fixed);
    cout.precision(6);
    cout << (2 * pi * d2) + (2 * d1) << "\n";
}
