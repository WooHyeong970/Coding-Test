#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, pair<int, int>>> st;
int n, cnt(0);
int board[17][17];

void Input()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    }
}

void check(int x, int y, bool c[3], int idx)
{
    if(x <= n && y <= n && !board[x][y])
        c[idx] = true;
}

void dfs()
{
    st.push(make_pair(-1, make_pair(1, 2)));
    while(!st.empty())
    {
        bool checkArea[3] { false, false, false };
        int curState = st.top().first;
        int x = st.top().second.first;
        int y = st.top().second.second;
        st.pop();
        if(x == n && y == n) cnt++;
        else
        {
            check(x, y + 1, checkArea, 0);
            check(x + 1, y, checkArea, 1);
            check(x + 1, y + 1, checkArea, 2);
            if(checkArea[0] && checkArea[1] && checkArea[2]) st.push(make_pair(0, make_pair(x + 1, y + 1)));
            if(checkArea[0] && (curState == -1 || curState == 0)) st.push(make_pair(-1, make_pair(x, y + 1)));
            if(checkArea[1] && (curState == 1 || curState == 0)) st.push(make_pair(1, make_pair(x + 1, y)));
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Input();
    dfs();
    cout << cnt << "\n";
}
