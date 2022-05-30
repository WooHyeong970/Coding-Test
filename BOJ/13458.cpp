#include <iostream>
#include <vector>

using namespace std;

int n, a, b;
long long sum(0);
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    cin >> a >> b;
    for(int i : vec)
    {
        sum++;
        i -= a;
        if(i <= 0)
            continue;
        else
        {
            if(i % b == 0)
                sum += i / b;
            else
                sum += i / b + 1;
        }
    }
    cout << sum << "\n";
}
