#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    int n, sum(0);
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        if(a != 0)
            s.push(a);
        else
        {
            if(s.empty())
                continue;
            else
                s.pop();
        }
    }
    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum << "\n";
}
