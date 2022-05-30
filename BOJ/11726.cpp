#include <iostream>

using namespace std;

unsigned long arr[1001];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        if(arr[i] >= 10007)
            arr[i] = arr[i] % 10007;
    }
    cout << arr[n] << "\n";
}
