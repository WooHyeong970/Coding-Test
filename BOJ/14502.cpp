#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> twoVec, zeroVec;
int n, m, safeArea(0), zeroCnt(0);
int board[8][8];
bool check[8][8];
int dx[4] { 1, 0, -1, 0 };
int dy[4] { 0, 1, 0, -1 };

void Input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 2)
                twoVec.push_back(make_pair(i, j));
            else if(!board[i][j])
            {
                zeroCnt++;
                zeroVec.push_back(make_pair(i, j));
            }
        }
    }
    zeroCnt -= 3;
}

void bfs()
{
    int num(0);
    memset(check, 0, sizeof(check));
    for(int i = 0; i < int(twoVec.size()); i++)
    {
        
        queue<pair<int, int>> Q;
        Q.push(make_pair(twoVec[i].first, twoVec[i].second));
        while(!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(check[nx][ny]) continue;
                if(board[nx][ny] != 0) continue;
                num++;
                check[nx][ny] = true;
                Q.push(make_pair(nx, ny));
            }
        }
    }
    if(safeArea < zeroCnt - num)
        safeArea = zeroCnt - num;
}

void backTack(int k, int t)
{
    if(k == 3) bfs();
    else
    {
        for(int i = t; i < zeroVec.size(); i++)
        {
            int x = zeroVec[i].first;
            int y = zeroVec[i].second;
            board[x][y] = 1;
            backTack(k + 1, i + 1);
            board[x][y] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Input();
    backTack(0, 0);
    cout << safeArea << "\n";
}
