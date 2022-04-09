#include <iostream>

using namespace std;

long long N[101];
int n, t;

void getNum()
{
    N[1] = 1;
    N[2] = 1;
    N[3] = 1;
    N[4] = 2;
    N[5] = 2;
    for(int i = 6; i <= 100; i++)
        N[i] = N[i - 1] + N[i - 5]; // 해당 규칙
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    getNum();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << N[n] << "\n";
    }
}
