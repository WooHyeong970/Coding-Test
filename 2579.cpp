#include <iostream>

using namespace std;

int step[301];
int score[301];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        step[i] = a;
        score[i] = a;
    }
    score[2] += score[1]; // 두 번째 score는 score1을 더한 값으로 초기화 한다
    if(n == 1) // 우선 1 혹은 2를 입력했을 경우 score1과 score2를 출력해주도록 하고
    {
        cout << score[1] << "\n";
        return 0;
    }
    else if(n == 2)
    {
        cout << score[2] << "\n";
        return 0;
    }
    for(int i = 3; i <= n; i++)
    {
        if(score[i - 3] + step[i - 1] > score[i - 2]) // i-2의 score보다 i-3의 score와 i-1의 step을 더한 값이 크다면 해당 값에 step i를 더해서 score i에 넣어준다
            score[i] = score[i - 3] + step[i - 1] + step[i];
        else
            score[i] = score[i - 2] + step[i]; // 더 작은 경우에는 score i-2에 step i를 더한 값을 넣어주고
    }
    cout << score[n] << "\n"; // score n을 출력
}
