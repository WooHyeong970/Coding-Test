#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[51][51];
int check[51][51];
int dx[4] {1, 0, -1, 0};
int dy[4] {0, 1, 0, -1};
int t, m, n, k;
int x, y;

void reset() // 여러 테스트 케이스를 위해 board와 check를 초기화해주는 함수
{
    for(int i = 0; i < 51; i++)
    {
        for(int j = 0; j < 51; j++)
        {
            board[i][j] = 0;
            check[i][j] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        reset(); // 각 테스트 케이스가 시작하면 reset
        queue<pair<int, int>> Q;
        int cnt(0);
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> x >> y;
            board[x][y] = 1;
            Q.push({x, y}); // 배추가 심어져있는 모든 좌표를 Q에 push
        }
        while(!Q.empty()) // 이 반복문에서 모든 배추의 좌표를 검사함
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            if(board[cur.X][cur.Y] == 1 && !check[cur.X][cur.Y]) // board는 1인데 check가 false인 경우 cnt를 1증가시키고 인접한 모든 배추를 찾아냄
            {
                cnt++;
                queue<pair<int, int>> subQ;
                subQ.push({cur.X, cur.Y});
                while(!subQ.empty())
                {
                    pair<int, int> subCur = subQ.front();
                    subQ.pop();
                    for(int i = 0; i <= 3; i++)
                    {
                        int nx = subCur.X + dx[i];
                        int ny = subCur.Y + dy[i];
                        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if(board[nx][ny] == 0) continue;
                        if(check[nx][ny]) continue;
                        check[nx][ny] = true; // 인접한 모든 배추의 check를 true로 만들어서 해당 배추가 큰 틀의 반복문에 안걸리도록 한다
                        subQ.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}
