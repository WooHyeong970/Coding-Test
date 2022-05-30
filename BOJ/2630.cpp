#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

queue<pair<pair<int, int>, int>> Q; // Q에는 색종이의 시작 좌표와 색종이의 크기를 입력받음
int paper[129][129];
int b(0), w(0), n;

bool checkCoord(pair<int, int> c, int m) // 인자로 받은 좌표에서 m만큼의 크기를 가진 색종이가 온전한지 판단하는 함수
{
    int color = paper[c.X][c.Y];
    for(int i = c.X; i < (c.X + m); i++)
    {
        for(int j = c.Y; j < (c.Y + m); j++)
        {
            if(color != paper[i][j])
                return false;
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> paper[i][j];
    }
    Q.push({{1, 1}, n});
    while(!Q.empty())
    {
        pair<int, int> coor = Q.front().X;
        int num = Q.front().Y;
        Q.pop();
        if(checkCoord(coor, num)) // 해당 좌표에서 num크기만한 색종이가 온전하다면
        {
            if(paper[coor.X][coor.Y] == 1) b++; // 해당하는 색깔의 색종이를 1 증가시키고
            else w++;
        }
        else
        {
            int h = num / 2; // 아니라면 해당 색종이를 4등분하여 Q에 push한다
            Q.push({{coor.X, coor.Y}, h});
            Q.push({{coor.X + h, coor.Y}, h});
            Q.push({{coor.X, coor.Y + h}, h});
            Q.push({{coor.X + h, coor.Y + h}, h});
        }
    }
    cout << w << "\n" << b << "\n";
}
