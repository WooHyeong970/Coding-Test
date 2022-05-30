#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

pair<string, string> memo[100000];
int n, m;

bool cmp(pair<string, string> x, pair<string, string> y)
{
    if(x.first.compare(y.first) < 0)
        return true;
    else
        return false;
}

void BinarySearch(string ad)
{
    int head(0), tail(n), mid(0);
    while(head <= tail)
    {
        mid = (head + tail) / 2;
        if(memo[mid].first.compare(ad) > 0)
            tail = mid - 1;
        else if(memo[mid].first.compare(ad) < 0)
            head = mid + 1;
        else
        {
            printf("%s\n", memo[mid].second.c_str());
            return;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        char m_address[20], m_pass[20];
        scanf("%s %s", m_address, m_pass); // 입력 및 출력의 속도를 위해 scanf와 printf를 사용한다
        memo[i].first = m_address; // pair의 first에 주소를
        memo[i].second = m_pass; // pair의 second에 비밀번호를 입력하고
    }
    sort(memo, memo + n, cmp); // 이진탐색을 위해 사전순으로 정렬한 뒤
    for(int i = 0; i < m; i++)
    {
        char address[20];
        scanf("%s", address);
        BinarySearch(address); // 이진 탐색 시작
    }
}
