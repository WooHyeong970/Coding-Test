#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.second > y.second;
}

bool stable_cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first > y.first;
}

int t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        queue<pair<int, int>> Q;
        pair<int, int> r[101];
        int arr[101];
        bool flag = false;
        int count(0);
        pair<int, int> p;
        int n, m;
        cin >> n >> m;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            Q.push({a, arr[a]});
            r[j] = {a, arr[a]};
            arr[a] += 1;
        }
        p = r[m];
        sort(r, r + n, cmp);
        stable_sort(r, r + n, stable_cmp);
        for(int j = 0; j < n; j++)
        {
            while(true)
            {
                if(r[j].first == Q.front().first)
                {
                    if(p == Q.front())
                    {
                        flag = true;
                        break;
                    }
                    count++;
                    Q.pop();
                    break;
                }
                Q.push(Q.front());
                Q.pop();
            }
            if(flag)
            {
                cout << count + 1 << "\n";
                break;
            }
        }
    }
}
