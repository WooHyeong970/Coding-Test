#include <iostream>

using namespace std;

int n, sum(0);
int coin[6] {500, 100, 50, 10, 5, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n = 1000 - n;
    for(int i = 0; i < 6; i++)
    {
        sum += n / coin[i];
        n = n % coin[i];
        if(n == 0)
            break;
    }
    cout << sum << "\n";
}
