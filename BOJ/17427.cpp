#include <iostream>

using namespace std;

int n;
long long sum(0);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        sum += (n / i) * i;
    cout << sum << "\n";
}
