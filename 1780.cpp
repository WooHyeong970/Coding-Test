#include <iostream>
#include <queue>

using namespace std;

queue<pair<pair<int, int>, int>> Q;
int n, sumMin(0), sumZ(0), sumOne(0);
int board[3000][3000];

void isFill(int x, int y, int size)
{
    int start = board[x][y];
    for(int i = x; i <= x + size - 1; i++)
    {
        for(int j = y; j <= y + size - 1; j++)
        {
            if(start != board[i][j])
            {
                Q.push({{x, y}, size / 3});
                Q.push({{x, y + (size / 3)}, size / 3});
                Q.push({{x, y + (size / 3) * 2}, size / 3});
                Q.push({{x + (size / 3), y}, size / 3});
                Q.push({{x + (size / 3), y + (size / 3)}, size / 3});
                Q.push({{x + (size / 3), y + (size / 3) * 2}, size / 3});
                Q.push({{x+ (size / 3) * 2, y}, size / 3});
                Q.push({{x+ (size / 3) * 2, y + (size / 3)}, size / 3});
                Q.push({{x+ (size / 3) * 2, y + (size / 3) * 2}, size / 3});
                return;
            }
        }
    }
    switch (start) {
        case -1:
            sumMin++;
            break;
        case 0:
            sumZ++;
            break;
        case 1:
            sumOne++;
            break;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    }
    Q.push({{1, 1}, n});
    while(!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int s = Q.front().second;
        Q.pop();
        isFill(x, y, s);
    }
    cout << "\n";
    cout << sumMin << "\n" << sumZ << "\n" << sumOne << "\n";
}
