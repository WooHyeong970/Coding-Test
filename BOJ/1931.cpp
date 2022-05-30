#include <iostream>
#include <algorithm>
#define LL long long

using namespace std;

int n, cnt(1);
LL m;
pair<LL, LL> meeting[100001];

bool firstCmp(pair<LL, LL> x, pair<LL, LL> y)
{
    return x.first < y.first;
}

bool secondCmp(pair<LL, LL> x, pair<LL, LL> y)
{
    return x.second < y.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        meeting[i].first = a;
        meeting[i].second = b;
    }
    sort(meeting, meeting + (n + 1), firstCmp); // first값을 기준으로 먼저 오름차순 정렬을 하고
    stable_sort(meeting, meeting + n, secondCmp); // first의 순서를 헤치지 않은 상태로 second의 값을 오름차순 정렬한다
    m = meeting[1].second;
    for(int i = 2; i <= n; i++) // 어떤 회의가 끝나면 다음 회의는 가장 일찍 끝나면서 가장 먼저 시작하는 회의를 선택한다
    {
        if(meeting[i].first >= m)
        {
            cnt++;
            m = meeting[i].second;
        }
    }
    cout << cnt << "\n";
}
