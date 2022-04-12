#include <iostream>
#include <queue>

using namespace std;

queue<int> Q;
int n, m, u, v, cnt(0);
int board[1001][1001];
bool check[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        check[i] = true;
    while(m--)
    {
        cin >> u >> v;
        board[u][v] = 1;
        board[v][u] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(check[i])
        {
            check[i] = false;
            Q.push(i);
            while(!Q.empty())
            {
                int c = Q.front();
                for(int j = 1; j <= n; j++)
                {
                    if(board[c][j] == 1 && check[j])
                    {
                        Q.push(j);
                        check[j] = false;
                    }
                }
                Q.pop();
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
}
