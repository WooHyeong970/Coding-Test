#include <iostream>
#include <algorithm>
#define X first
#define Y second
#define LL long long

using namespace std;

int n, idx(0);
LL p;
pair<LL, LL> arr[1000001];

bool firstCmp(pair<LL, LL> x, pair<LL, LL> y)
{
    return x.X < y.X;
}

bool secondCmp(pair<LL, LL> x, pair<LL, LL> y)
{
    return x.Y < y.Y;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].X;
        arr[i].Y = i;
    }
    sort(arr, arr + n, firstCmp); // first를 기준으로 오름차순 정렬 후
    p = arr[0].X;
    arr[0].X = idx;
    for(int i = 1; i < n; i++) // 앞 뒤 값을 비교하여 0부터 시작해서 채워나감
    {
        if(arr[i].X == p) // i번째 값과 p값이 같으면 p에 arr[i]를 넣고 arr[i]의 first에 idx를 넣는다
        {
            p = arr[i].X;
            arr[i].X = idx;
        }
        else // 두 값이 다를 경우 위와 동일하지만 idx를 1증가시켜서 넣는다
        {
            p = arr[i].X;
            arr[i].X = ++idx;
        }
    }
    sort(arr, arr + n, secondCmp); // 다시 second값을 기준으로 오름차순 정렬한 뒤
    for(int i = 0; i < n; i++) // first값을 출력해주면 해결
        cout << arr[i].X << " ";
}
