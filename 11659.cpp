#include <iostream>

using namespace std;

long long N[100001];
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        N[i] = N[i - 1] + a; // i 번째 마다 1부터 i까지의 합을 넣어준다
    }
    for(int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << N[end] - N[start - 1] << "\n"; // 미리 합을 구했으니 end에서 start - 1을 빼주면 해결
    }
}
