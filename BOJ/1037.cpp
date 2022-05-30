#include <iostream>

using namespace std;

int n, max_a(-1), min_a(1000001);
int arr[51];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(max_a < arr[i])
            max_a = arr[i];
        if(min_a > arr[i])
            min_a = arr[i];
    }
    cout << max_a * min_a << "\n";
}
