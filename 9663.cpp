#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int board[15][15];
int n, cnt(0);

void checkDown(int x, int y, int b[15][15])
{
    for(int i = x + 1; i < n; i++)
        b[i][y] = 1;
}

void checkLeftDown(int x, int y, int b[15][15])
{
    int idx(1);
    for(int i = x + 1; i < n; i++)
    {
        if(y - idx < 0) return;
        b[i][y - idx] = 1;
        idx++;
    }
}

void checkRightDown(int x, int y, int b[15][15])
{
    int idx(1);
    for(int i = x + 1; i < n; i++)
    {
        if(y + idx >= n) return;
        b[i][y + idx] = 1;
        idx++;
    }
}

void checkBoard(int x, int b[15][15])
{
    if(x == n)
    {
        cnt++;
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(!b[x][i])
        {
            b[x][i] = 1;
            if(x == (n - 1))
            {
                checkBoard(x + 1, b);
                continue;
            }
            
            int next_b[15][15];
            memset(next_b, 0, sizeof(next_b));
            copy(&b[0][0], &b[0][0] + 225, &next_b[0][0]);
            
            checkDown(x, i, next_b);
            checkLeftDown(x, i, next_b);
            checkRightDown(x, i, next_b);
            
            checkBoard(x + 1, next_b);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    checkBoard(0, board);
    cout << cnt << "\n";
}
