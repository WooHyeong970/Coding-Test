#include <iostream>

using namespace std;

int n, r, c, m;
int N;

int func(int x, int y, int z)
{
    int num(0);
    if(z == 0)
        return 1;
    if(x > ((z / 2) - 1))
    {
        if(y > ((z / 2) - 1)) // 4사
        {
            num += (z / 2) * (z / 2) * 3;
            return num + func(x - (z / 2), y - (z / 2), (z / 2));
        }
        else // 3사
        {
            num += (z / 2) * (z / 2) * 2;
            return num + func(x - (z / 2), y, (z / 2));
        }
    }
    else if(y > ((z / 2) - 1)) // 2사
    {
        num += (z / 2) * (z / 2) * 1;
        return num + func(x, y - (z / 2), (z / 2));
    }
    else // 1사
    {
        return func(x, y, (z / 2));
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> c;
    m = (r >= c) ? r : c;
    for(int i = 1; (i - 1) < m; i *= 2)
        N = i * 2;
    cout << func(r, c, N) - 1 << "\n";
}
