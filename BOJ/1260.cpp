#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> Q;
stack<int> S;
int n, m, v;
int bfs[1001][1001], dfs[1001][1001];
bool checkB[1001], checkD[1001];

void DFS() // stack으로 가장 나중에 들어온 값을 가장 먼저 탐색
{
    S.push(v);
    while(!S.empty())
    {
        int s = S.top();
        S.pop();
        if(!checkD[s])
        {
            checkD[s] = true;
            cout << s << " ";
            for(int i = n; i > 0; i--)
            {
                if(dfs[s][i] == 1)
                    S.push(i);
            }
        }
    }
    cout << "\n";
}

void BFS() // queue를 이용하여 근접한 노드먼저 탐색
{
    Q.push(v);
    checkB[v] = true;
    while(!Q.empty())
    {
        int q = Q.front();
        Q.pop();
        cout << q << " ";
        for(int i = 1; i <= n; i++)
        {
            if(bfs[q][i] == 1 && !checkB[i])
            {
                Q.push(i);
                checkB[i] = true;
            }
        }
    }
    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    while(m--)
    {
        int s, e;
        cin >> s >> e;
        dfs[s][e] = 1;
        dfs[e][s] = 1;
        bfs[s][e] = 1;
        bfs[e][s] = 1;
    }
    DFS();
    BFS();
}
