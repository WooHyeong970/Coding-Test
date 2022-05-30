#include <iostream>

using namespace std;

int n, m(-1);
int board[501][501], result[501][501]; // board는 원형의 피라미드값을 넣을 배열, result는 내려오는 값들의 합을 저장할 배열

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cin >> board[i][j];
    }
    result[0][0] = board[0][0]; // result[0][0]은 board[0][0]으로 초기화
    for(int i = 0; i < (n - 1); i++) // DP시작
    {
        for(int j = 0; j <= i; j++)
        {
            if(result[i][j] + board[i + 1][j] > result[i + 1][j])
                result[i + 1][j] = result[i][j] + board[i + 1][j];
            if(result[i][j] + board[i + 1][j + 1] > result[i + 1][j + 1])
                result[i + 1][j + 1] = result[i][j] + board[i + 1][j + 1];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(m < result[n - 1][i])
            m = result[n - 1][i];
    }
    cout << m << "\n"; // 최댓값 출력
}
