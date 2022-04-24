#include <iostream>
#include <string>

using namespace std;

int n, m, cur(0), sum(0);
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < m; i++)
    {
        if(s[i] == 'O')
            continue;
        else
        {
            while(s[i + 1] == 'O' && s[i + 2] == 'I') // I가 나오면 다음에 OI가 나오는지 확인하고
            {
                cur++; // IOI가 한번 나올때마다 cur을 1증가 시키면서
                if(cur == n) // cur이 n과 같아지면
                {
                    cur--; // cur에 1을 빼고
                    sum++; // sum을 1증가시킨다
                }
                i += 2;
            }
            cur = 0; // 만약 while문이 깨지면 cur을 0으로 초기화
        }
    }
    cout << sum << "\n";
}
