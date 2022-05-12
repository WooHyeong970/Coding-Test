#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    if(n == m) cout << 1 << "\n";
    else cout << 0 << "\n";
}
