#include <iostream>

using namespace std;

int n;
long long sum(1);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        if(i % 2)
            sum = ((sum * 2) + 1) % 10007;
        else
            sum = ((sum * 2) - 1) % 10007;
    }
    cout << sum << "\n";
}
