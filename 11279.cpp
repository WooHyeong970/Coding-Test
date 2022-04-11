#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> Q;
int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> k;
        if(k > 0)
            Q.push(k);
        else
        {
            if(Q.empty())
                cout << 0 << "\n";
            else
            {
                cout << Q.top() << "\n";
                Q.pop();
            }
        }
    }
}
