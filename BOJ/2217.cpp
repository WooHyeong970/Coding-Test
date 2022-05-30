#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr + (n + 1)); // 입력 받은 로프를 오름차순으로 정렬하고
    m = arr[n]; // 가장 튼튼한 로프부터 최대 중량 값을 구하는데
    for(int i = 1; i < n; i++) // 현재 max값보다 한 단계 약한 로프를 더하여 총량을 구한 값이 높다면 값을 교체해준다
    {
        if(m < arr[n - i] * (i + 1))
            m = arr[n - i] * (i + 1);
    }
    cout << m << "\n";
}
