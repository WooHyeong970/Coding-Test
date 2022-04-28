#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m, t;
bool check[10001];

void reset()
{
    for(int i = 0; i <= 10000; i++) check[i] = false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        queue<pair<string, int>> Q;
        Q.push({"", n});
        check[n] = true;
        while(!Q.empty())
        {
            int D, S, L, R;
            int x = Q.front().second;
            string s = Q.front().first;
            Q.pop();
            if(x == m)
            {
                cout << s << "\n";
                break;
            }
            D = (x * 2) % 10000;
            if(!check[D])
            {
                check[D] = true;
                Q.push({s + "D", D});
            }
            S = x - 1 < 0 ? 9999 : x - 1;
            if(!check[S])
            {
                check[S] = true;
                Q.push({s + "S", S});
            }
            L = (x % 1000) * 10 + (x / 1000);
            if(!check[L])
            {
                check[L] = true;
                Q.push({s + "L", L});
            }
            R = (x / 10) + (1000 * (x % 10));
            if(!check[R])
            {
                check[R] = true;
                Q.push({s + "R", R});
            }
        }
        reset();
    }
}
