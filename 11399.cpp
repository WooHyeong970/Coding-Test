#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
long long sum(0);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr, arr + (n + 1));
    for(int i = 1; i <= n; i++)
    {
        sum += arr[i - 1] + arr[i];
        arr[i] += arr[i - 1];
    }
    cout << sum << "\n";
}
