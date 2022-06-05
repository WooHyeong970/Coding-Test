#include <iostream>
#include <vector>
#define INF 1987654321

using namespace std;

int node[510];
int tc, n, m, w, s, e, t;
bool isVaild;

void reset()
{
    for(int i = 0; i < 510; i++) node[i] = INF;
    node[1] = 0;
    isVaild = false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--)
    {
        vector<pair<pair<int, int>, int>> vec;
        reset();
        cin >> n >> m >> w;
        for(int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            vec.push_back({{s, e}, t});
            vec.push_back({{e, s}, t});
        }
        for(int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            vec.push_back({{s, e}, -t});
        }
        for(int i = 1; i <= n; i++)
        {
            for(auto j : vec)
            {
                int start = j.first.first;
                int end = j.first.second;
                int weight = j.second;
                if(node[start] + weight < node[end])
                {
                    node[end] = node[start] + weight;
                    if(i == n) isVaild = true;
                }
            }
        }
        if(isVaild) cout << "YES\n";
        else cout << "NO\n";
    }
}
