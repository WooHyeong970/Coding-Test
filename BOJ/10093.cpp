#include <iostream>

using namespace std;

unsigned long long a, b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if(a < b)
    {
        cout << b - (a + 1) << "\n";
        for(auto i = a + 1; i < b; i++)
            cout << i << " ";
    }
    else if(a > b)
    {
        cout << a - (b + 1) << "\n";
        for(auto i = b + 1; i < a; i++)
            cout << i << " ";
    }
    else
        cout << 0 << "\n";
}
