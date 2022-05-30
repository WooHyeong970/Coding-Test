#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int color[1002][3];
int score[1002][3];

enum Color
{
    RED,
    GREEN,
    BLUE,
};

int getMin(int m) // 한 라인에서 R G B의 score중 가장 작은 값을 반환하는 함수
{
    int minNum = min(score[m][0], score[m][1]);
    return min(minNum, score[m][2]);
}

void setMin(int m, Color C) // 인자로 들어온 Color의 score에 m-1 라인에서 가장 작은 score과 m라인의 가장 작은 값을 더해서 넣어준다
{
    vector<int> vec;
    for(int i = 0; i < 3; i++)
    {
        if(i == C)
            continue;
        vec.push_back(score[m - 1][i]);
    }
    score[m][C] = color[m][C] + min(vec[0], vec[1]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int c;
            cin >> c;
            color[i][j] = c;
        }
    }
    score[1][0] = color[1][0];
    score[1][1] = color[1][1];
    score[1][2] = color[1][2];
    if(n == 1) // n이 1인 경우에는 직접 출력
    {
        cout << getMin(1);
        return 0;
    }
    for(int i = 2; i <= n; i++) // n이 2부터는 각 라인마다 올 수있는 가장 작은 score를 넣어주고
    {
        setMin(i, RED);
        setMin(i, GREEN);
        setMin(i, BLUE);
    }
    cout << getMin(n) << "\n"; // n번째 라인에서 가장 작은 score를 출력
}
