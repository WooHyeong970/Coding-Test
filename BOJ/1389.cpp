#include <iostream>
#include <queue>

using namespace std;

queue<int> Q;
int n, m, s(1000000), result;
int board[101][101];
int arr[101];

void reset()
{
    for(int i = 0; i <= 100; i++) arr[i] = 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        board[u][v] = 1;
        board[v][u] = 1;
    }
    for(int i = 1; i <= n; i++) // 1번부터 n번의 사람까지 모든 인원을 검사하는데
    {
        int sum(0);
        Q.push(i);
        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for(int j = 1; j <= n; j++)
            {
                if(board[cur][j]) // 현재 검사하는 사람과 친구인 사람이면서
                {
                    if(!arr[j]) // 한번도 검사하지 않은 사람이면
                    {
                        arr[j] = arr[cur] + 1; // 그 사람의 친구의 단계 횟수에 1을 더해 넣는다
                        Q.push(j);
                    }
                }
            }
        }
        for(int k : arr)
            sum += k;
        if(sum < s)
        {
            s = sum;
            result = i;
        }
        reset();
    }
    cout << result << "\n";
}
