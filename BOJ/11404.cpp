#include <iostream>
#include <queue>
#include <climits>

using namespace std;

queue<pair<pair<int, int>, int>> Q;
int n, m, s, e, w;
int weight[101][101];
bool line[101][101];

void fill_array()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            weight[i][j] = INT_MAX;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill_array();
    while(m--)
    {
        cin >> s >> e >> w;
        if(weight[s][e] > w)
        {
            weight[s][e] = w;
            line[s][e] = true;
            Q.push({{s, e}, w});
        }
    }
    while(!Q.empty())
    {
        int cur_s = Q.front().first.first;
        int cur_e = Q.front().first.second;
        int cur_w = Q.front().second;
        Q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(cur_s == i) continue;
            if(line[cur_e][i])
            {
                if(weight[cur_s][i] > cur_w + weight[cur_e][i])
                {
                    weight[cur_s][i] = cur_w + weight[cur_e][i];
                    line[cur_s][i] = true;
                    Q.push({{cur_s, i}, weight[cur_s][i]});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(weight[i][j] == INT_MAX) cout << 0 << " ";
            else cout << weight[i][j] << " ";
        }
        cout << "\n";
    }
}
