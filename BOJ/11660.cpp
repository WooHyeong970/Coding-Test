#include <iostream>

using namespace std;

int board[1025][1025], result[1025][1025];
int n, m;
int x1, y1, x2, y2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            result[i][j] = board[i][j] + result[i][j - 1];
        }
    }
    while(m--)
    {
        int sum(0);
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++)
            sum += result[i][y2] - result[i][y1 - 1];
        cout << sum << "\n";
    }
}
