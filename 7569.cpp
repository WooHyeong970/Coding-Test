#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, pair<int, int>>> Q;
int board[100][100][100];
int n, m, h, cnt(0), day(0);
int dx[4] {1, 0, -1, 0};
int dy[4] {0, 1, 0, -1};
int dz[2] {1, -1};

void checkTomato() // 모든 상자의 구역을 살펴보고
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if(!board[i][j][k]) // 0이 하나라도 있으면 -1을
                {
                    cout << -1 << "\n";
                    return;
                }
            }
        }
    }
    cout << day << "\n"; // 0이 없다면 day를 출력
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                int t;
                cin >> t;
                board[i][j][k] = t;
                if(t == 1)
                {
                    Q.push({i, {j, k}});
                    cnt++;
                }
            }
        }
    }
    while(true)
    {
        int temp(0);
        for(int i = 0; i < cnt; i++)
        {
            pair<int, pair<int, int>> cur = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++) // x, y 축으로 덜익은 토마토가 있는지 확인
            {
                int nx = cur.second.first + dx[i];
                int ny = cur.second.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(board[cur.first][nx][ny] != 0) continue;
                Q.push({cur.first, {nx, ny}});
                board[cur.first][nx][ny] = 1;
                temp++;
            }
            for(int i = 0; i < 2; i++) // z 축으로 덜익은 토마토가 있는지 확인
            {
                int nz = cur.first + dz[i];
                if(nz < 0 || nz >= h) continue;
                if(board[nz][cur.second.first][cur.second.second] != 0) continue;
                Q.push({nz, {cur.second.first, cur.second.second}});
                board[nz][cur.second.first][cur.second.second] = 1;
                temp++;
            }
        }
        cnt = temp;
        if(!cnt) // 만약 cnt가 0이라서 더이상 확인할 구역이 없다면 checkTomato 실행!!
        {
            checkTomato();
            break;
        }
        day++;
    }
}
