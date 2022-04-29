#include <iostream>

using namespace std;

int t, a, b;

int getGCD(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int getLCM(int a, int b)
{
    return a * b / getGCD(a, b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << getLCM(a, b) << "\n";
    }
}
