#include <iostream>
#include <queue>
#include <vector>
#define S second

using namespace std;

vector<int> vec[100001];
queue<pair<int, int>> Q;
int n, v, e;
int parent[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < (n - 1); i++) // 연결된 정점의 순서가 랜덤이므로 양방향 간선을 만들어준다
    {
        cin >> v >> e;
        vec[v].push_back(e);
        vec[e].push_back(v);
    }
    parent[1] = -1; // 1의 부모는 -1로
    for(auto i = vec[1].begin(); i != vec[1].end(); i++) // 우선 Q에 1과 연결된 모든 정점을 넣어주고
    {
        Q.push({1, *i});
        parent[*i] = 1;
    }
    while(!Q.empty()) // BFS시작
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for(auto i = vec[cur.S].begin(); i != vec[cur.S].end(); i++) // 만약 부모노드가 설정되어있지 않다면
        {
            if(!parent[*i])
            {
                parent[*i] = cur.S; // 연결된 cur의 second값을 부모노드값으로 넣어준다
                Q.push({cur.S, *i});
            }
        }
    }
    for(int i = 2; i <= n; i++) // 2부터 n까지의 값을 출력하면 해결
        cout << parent[i] << "\n";
}
