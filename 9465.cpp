#include <iostream>
#define X first
#define Y second

using namespace std;

int t, n;
int board[2][100000], sum[2][100000];

void reset()
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
            sum[i][j] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        reset();
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> board[i][j];
        }
        sum[0][0] = board[0][0]; // 초기값 설정
        sum[0][1] = board[1][0] + board[0][1];
        sum[1][0] = board[1][0];
        sum[1][1] = board[0][0] + board[1][1];
        for(int i = 2; i < n; i++)
        {
            int u_max, d_max;
            u_max = sum[0][i - 2] > sum[0][i - 1] ? sum[0][i - 2] : sum[0][i - 1];
            d_max = sum[1][i - 2] > sum[1][i - 1] ? sum[1][i - 2] : sum[1][i - 1];
            sum[0][i] = d_max + board[0][i];
            sum[1][i] = u_max + board[1][i];
        }
        if(sum[0][n - 1] > sum[1][n - 1]) cout << sum[0][n - 1] << "\n";
        else cout << sum[1][n - 1] << "\n";
    }
}
