#include <iostream>
#include <string>

using namespace std;

string s;
int board[65][65];
int n;

void func(int x, int y, int n)
{
    if(n == 1)
    {
        cout << board[x][y];
        return;
    }
    int start = board[x][y];
    bool isVaild = false;
    for(int i = x; i < x + n; i++)
    {
        for(int j = y; j < y + n; j++)
        {
            if(start != board[i][j])
                isVaild = true;
        }
    }
    if(!isVaild)
    {
        cout << start;
        return;
    }
    else
    {
        cout << '(';
        func(x, y, n / 2);
        func(x, y + (n / 2), n / 2);
        func(x + (n / 2), y, n / 2);
        func(x + (n / 2), y + (n / 2), n / 2);
        cout << ')';
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 1; j <= n; j++)
            board[i][j] = s[j - 1] - '0';
    }
    func(1, 1, n);
}
