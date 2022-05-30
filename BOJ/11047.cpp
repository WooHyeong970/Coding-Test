#include <iostream>

using namespace std;

int n, k;
int arr[11];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    while(n != 1) // 동전의 경우 그 가치를 기준으로 오름차순 정렬 되어있으니 가장 큰 값부터 시작해서 k를 나눈 몫과 나머지를 구한다
    {
        if(arr[n] <= k)
        {
            cnt += k / arr[n];
            k %= arr[n];
        }
        n--;
    }
    cout << cnt + (k / arr[n]) << "\n";
}
