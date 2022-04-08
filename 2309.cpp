#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int sum(0);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 9; i++)
        cin >> arr[i];
    sort(arr, arr + 9);
    for(int i = 0; i < 9; i++)
        sum += arr[i];
    sum -= 100;
    for(int i = 0; i < 9; i++)
    {
        for(int j = (i + 1); j < 9; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                for(int l = 0; l < 9; l++)
                {
                    if(l == i || l == j)
                        continue;
                    cout << arr[l] << "\n";
                }
                return 0;
            }
        }
    }
}
