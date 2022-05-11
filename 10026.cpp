#include <iostream>
#include <queue>

using namespace std;

char board_std[101][101], board_bln[101][101];
bool check_std[101][101], check_bln[101][101];
int dx[4] {1, 0, -1, 0};
int dy[4] {0, 1, 0, -1};
int n;

void getArea(char board[101][101], bool check[101][101])
{
    queue<pair<int, int>> Q;
    int area(0);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!check[i][j])
            {
                Q.push({i, j});
                while(!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
                        if(check[nx][ny]) continue;
                        if(board[cur.first][cur.second] != board[nx][ny]) continue;
                        Q.push({nx, ny});
                        check[nx][ny] = true;
                    }
                }
                area++;
            }
        }
    }
    cout << area << " ";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            board_std[i][j] = c;
            if(c == 'G') board_bln[i][j] = 'R';
            else board_bln[i][j] = c;
        }
    }
    getArea(board_std, check_std);
    getArea(board_bln, check_bln);
}
