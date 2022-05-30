#include <iostream>

using namespace std;

int t;

int make123(int n)
{
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else if(n == 3)
        return 4;
    return make123(n - 1) + make123(n - 2) + make123(n - 3);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << make123(n) << "\n";
    }
}
