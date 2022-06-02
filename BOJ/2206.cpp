#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define INF 1000001
#define X first
#define Y second

using namespace std;

struct node
{
    pair<int, int> coor;
    bool isBroken;
    int score;
};

queue<node> Q;
string s;
int n, m;
int board[1001][1001], scores[1001][1001];
bool check[1001][1001];
int dx[4] { 1, 0, -1, 0 };
int dy[4] { 0, 1, 0, -1 };

void push(int x, int y, bool c, int s)
{
    node n {{x, y}, c, s};
    Q.push(n);
}

void fill_scores()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scores[i][j] = INF;
    }
}

void BFS()
{
    fill_scores();
    scores[1][1] = 1;
    check[1][1] = true;
    push(1, 1, false, 1);
    while(!Q.empty())
    {
        pair<int, int> cur_coor = Q.front().coor;
        bool cur_broken = Q.front().isBroken;
        int cur_score = Q.front().score;
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur_coor.X + dx[i];
            int ny = cur_coor.Y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(cur_broken)
            {
                if(board[nx][ny] == 1) continue;
                if(scores[nx][ny] <= (cur_score + 1)) continue;
                push(nx, ny, cur_broken, cur_score + 1);
                scores[nx][ny] = cur_score + 1;
            }
            else
            {
                if(check[nx][ny]) continue;
                if(board[nx][ny] == 1)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        int jx = nx + dx[j];
                        int jy = ny + dy[j];
                        if(jx < 1 || jy < 1 || jx > n || jy > m) continue;
                        if(board[jx][jy] == 0 && !check[jx][jy])
                        {
                            push(nx, ny, true, cur_score + 1);
                            break;
                        }
                    }
                }
                else
                {
                    push(nx, ny, cur_broken, cur_score + 1);
                    if(scores[nx][ny] > (cur_score + 1)) scores[nx][ny] = cur_score + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 1; j <= m; j++)
            board[i][j] = s[j - 1] - '0';
    }
    BFS();
    if(scores[n][m] == INF) cout << -1 << "\n";
    else cout << scores[n][m] << "\n";
}
