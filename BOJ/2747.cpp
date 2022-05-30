#include <iostream>

using namespace std;

int n;
int arr[50];

void fibo(int m)
{
    int p, c;
    p = arr[0];
    c = arr[1];
    for(int i = 2; i <= m; i++)
    {
        arr[i] = p + c;
        p = c;
        c = arr[i];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[0] = 0;
    arr[1] = 1;
    fibo(n);
    cout << arr[n] << "\n";
}
