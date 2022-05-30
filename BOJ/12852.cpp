#include <iostream>

using namespace std;

pair<int, int> arr[1000001];
int n;

enum Number
{
    ONE, // 빼기
    TWO, // 나누기 2
    THREE, // 나누기 3
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++) // 각 원소의 first에는 최소 연산 count를, second에는 나누기 3, 나누기 2, 빼기 1 중에 어느 연산을 했는지에 대한 정보가 들어간다
    {
        arr[i].first = arr[i - 1].first + 1;
        arr[i].second = ONE;
        if(i % 2 == 0 && (arr[i / 2].first + 1) < arr[i].first)
        {
            arr[i].first = arr[i / 2].first + 1;
            arr[i].second = TWO;
        }
        if(i % 3 == 0 && (arr[i / 3].first + 1) < arr[i].first)
        {
            arr[i].first = arr[i / 3].first + 1;
            arr[i].second = THREE;
        }
    }
    cout << arr[n].first << "\n"; // 먼저 최소 연산 횟수를 출력하고
    while(n != 1)
    {
        cout << n << " "; // 각 원소의 second에 들어있는 값에 따라서 n을 줄여나간다
        switch (arr[n].second)
        {
            case ONE:
                n--;
                break;
            case TWO:
                n /= 2;
                break;
            case THREE:
                n /= 3;
                break;
        }
    }
    cout << 1 << "\n"; // 마지막 1을 출력하면 문제 해결
}
