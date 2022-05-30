#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool stable_cmp(pair<int, int> x, pair<int, int> y)
{
    return x.second < y.second;
}

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> vec;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end(), cmp);
    stable_sort(vec.begin(), vec.end(), stable_cmp);
    for(pair<int, int> i : vec)
        cout << i.first << " " << i.second << "\n";
}
