#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> m;
        if(m == 0)
        {
            if(Q.empty()) cout << 0 << "\n"; // m이 0이고 Q가 비어있으면 0을 출력
            else
            {
                cout << Q.top().second << "\n"; // Q가 비어있지 않다면 Q.top().second를 출력하고 pop
                Q.pop();
            }
        }
        else Q.push({abs(m), m}); // m이 0이 아니라면 first에는 m의 절댓값을, second에는 m으로 pair를 구성하여 Q에 push
    }
}
