#include <iostream>
#include <algorithm>

using namespace std;

int board[500][500];
int n, m, height(0);
int B;
int sum(0);

bool isWork(int h)
{
    int block = B;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            block += board[i][j] - h;
    }
    return block >= 0;
}

int getWorktime(int h)
{
    int time(0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] > h) // 땅 파기
                time += (board[i][j] - h) * 2;
            else if(board[i][j] < h) // 매꾸기
                time += h - board[i][j];
        }
    }
    return time;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> B;
    // board 입력 및 sum 구하기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            board[i][j] = a;
            sum += a;
        }
    }
    // 위에서 구한 sum으로 평균 높이 구하기
    height = sum / (n * m);
    while(true)
    {
        // 해당 높이에서 땅 고르기가 가능한지 판단하기
        if(isWork(height))
        {
            // 다음 높이에서 땅 고르기가 불가능하거나 다음 높이가 현재 높이보다 시간이 많이 걸리면 현재 높이에서 시간을 출력하고 break
            if(!isWork(height+1) || getWorktime(height) < getWorktime(height+1))
            {
                cout << getWorktime(height) << " " << height << "\n";
                break;
            }
            // 그게 아니라면 높이에 1을 더하고 반복문 진행
            height++;
        }
        else // 해당 높이에서 땅 고르기가 불가능하면 높이 낮추기
            height--;
    }
}
