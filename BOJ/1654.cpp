#include <iostream>
#include <algorithm>
#define LL long long

using namespace std;

int k, n;
LL arr[10001];
LL low(1), high(0), mid;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i = 0; i < k; i++)
    {
        LL a;
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr + k);
    high = arr[k - 1];
    while(low <= high)
    {
        int sum = 0;
        mid = (low + high) / 2;
        for(int i = 0; i < k; i++)
            sum += arr[i] / mid;
        if(sum < n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << high << "\n";
}
