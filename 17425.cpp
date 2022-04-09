#include <iostream>
#define M 1000000
using namespace std;

int n, t;
long long sum[1000001];

void getNum()
{
    for(int i = 1; i <= M; i++) // 1000000번의 반복문을 돌리면서 i번째 숫자를 i의 배수에 해당하는 index에 i값을 더하도록 하고
    {
        for(int j = i; j <= M; j += i)
            sum[j] += i;
    }
    for(int i = 2; i <= M; i++) // i는 2부터 sum[i]의 값에 sum[i - 1]의 값을 더한다
        sum[i] += sum[i - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    getNum();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << sum[n] << "\n"; // 그리고 입력받은 n번째 원소를 출력하면 문제 해결
    }
}
