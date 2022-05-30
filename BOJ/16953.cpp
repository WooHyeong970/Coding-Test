#include <iostream>

using namespace std;

int n, m, cnt(0);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(true)
    {
        if(m < n) cnt = -1;
        if(m <= n) break;
        if(m % 10 == 1)
        {
            m /= 10;
            cnt++;
            continue;
        }
        if(m % 2 == 0)
        {
            m /= 2;
            cnt++;
            continue;
        }
        cnt = -1;
        break;
    }
    if(cnt == -1) cout << cnt << "\n";
    else cout << cnt + 1 << "\n";
}
