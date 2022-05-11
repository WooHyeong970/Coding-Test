#include <iostream>

using namespace std;

int n, m, max_score(-1);
int board[500][500];

void typeOne()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= (m - 4); j++)
        {
            int sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
            if(sum > max_score) max_score = sum;
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= (n - 4); j++)
        {
            int sum = board[j][i] + board[j + 1][i] + board[j + 2][i] + board[j + 3][i];
            if(sum > max_score) max_score = sum;
        }
    }
}

void typeTwo()
{
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = 0; j < (m - 1); j++)
        {
            int sum = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
            if(sum > max_score) max_score = sum;
        }
    }
}

void typeThree()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= (m - 3); j++)
        {
            int sum = board[i][j] + board[i][j + 1] + board[i][j + 2];
            if((i - 1) >= 0)
            {
                for(int k = 0; k < 3; k++)
                {
                    if((sum + board[i - 1][j + k]) > max_score)
                        max_score = sum + board[i - 1][j + k];
                }
            }
            if((i + 1) < n)
            {
                for(int k = 0; k < 3; k++)
                {
                    if((sum + board[i + 1][j + k]) > max_score)
                        max_score = sum + board[i + 1][j + k];
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= (n - 3); j++)
        {
            int sum = board[j][i] + board[j + 1][i] + board[j + 2][i];
            if((i - 1) >= 0)
            {
                for(int k = 0; k < 3; k++)
                {
                    if((sum + board[j + k][i - 1]) > max_score)
                        max_score = sum + board[j + k][i - 1];
                }
            }
            if((i + 1) < m)
            {
                for(int k = 0; k < 3; k++)
                {
                    if((sum + board[j + k][i + 1]) > max_score)
                        max_score = sum + board[j + k][i + 1];
                }
            }
        }
    }
}

void typeFour()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= (m - 2); j++)
        {
            int sum = board[i][j] + board[i][j + 1];
            if((i - 1) >= 0 && (i + 1) < n)
            {
                int sum1 = sum + board[i - 1][j] + board[i + 1][j + 1];
                int sum2 = sum + board[i - 1][j + 1] + board[i + 1][j];
                if(sum1 > max_score) max_score = sum1;
                if(sum2 > max_score) max_score = sum2;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= (n - 2); j++)
        {
            int sum = board[j][i] + board[j + 1][i];
            if((i - 1) >= 0 && (i + 1) < m)
            {
                int sum1 = sum + board[j][i - 1] + board[j + 1][i + 1];
                int sum2 = sum + board[j][i + 1] + board[j + 1][i - 1];
                if(sum1 > max_score) max_score = sum1;
                if(sum2 > max_score) max_score = sum2;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    typeOne();
    typeTwo();
    typeThree();
    typeFour();
    cout << max_score << "\n";
}
