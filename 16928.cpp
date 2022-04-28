#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> Q;
int board[101], check[101];
int n, m;

void setBoard(int f, int s) // BFS
{
    board[f] = s;
    for(int i = 1; i <= 6; i++)
    {
        if((f + i) > 100) return; // 100보다 커지면 종료
        if(check[f + i]) Q.push({check[f + i], s + 1}); // 사다리 혹은 뱀에 걸리면 도착지를 push
        else Q.push({f + i, s + 1}); // 그게 아니라면 f + i위치를 push
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, e;
    cin >> n >> m;
    for(int i = 0; i < (n + m); i++)
    {
        cin >> s >> e;
        check[s] = e;
    }
    Q.push({1, 0});
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        // 한 번도 방문하지 않았거나 주사위 횟수가 더 적으면 함수 실행
        if(!board[cur.first] || cur.second < board[cur.first])
            setBoard(cur.first, cur.second);
    }
    cout << board[100] << "\n";
}
