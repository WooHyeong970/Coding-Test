#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define X first
#define Y second

using namespace std;

priority_queue<pair<int, int>> Q;
vector<pair<int, int>> vec[1001];
int n, m, v, e, w;
int start, goal;
int d[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill_n(d + 1, n, INT_MAX);
    while(m--)
    {
        cin >> v >> e >> w;
        vec[v].push_back(make_pair(e, w));
    }
    cin >> start >> goal;
    d[start] = 0;
    Q.push(make_pair(start, 0));
    while(!Q.empty())
    {
        pair<int, int> cur = Q.top();
        Q.pop();
        if(d[cur.X] < cur.Y) continue;
        for(auto i = vec[cur.X].begin(); i != vec[cur.X].end(); i++)
        {
            int next = i->X;
            int nextD = cur.Y + i->Y;
            if(nextD < d[next])
            {
                d[next] = nextD;
                Q.push(make_pair(next, nextD));
            }
        }
    }
    cout << d[goal] << "\n";
}
