#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp // priority_queue를 pair의 first기준 오름차순으로 정렬하기 위한 struct
{
    bool operator()(pair<int, int> x, pair<int, int> y)
    {
        return x.first > y.first;
    }
};

vector<pair<int, int>> vec[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q; // queue의 first에는 가중치를, second에는 도착점을 입력한다
bool check[20001];
int score[20001];
int V, E, K;

void Dijkstra(int start)
{
    Q.push({0, start});
    score[start] = 0;
    while(!Q.empty())
    {
        int W, S;
        W = Q.top().first;
        S = Q.top().second;
        Q.pop();
        if(!check[S]) // 만약 도착점이 한번도 방문하지 않은 곳이라면
        {
            check[S] = true; // 두 번째의 방문은 허락하지 않도록 true로 만들어주고
            score[S] = W; // 도착점에 가중치 W를 넣어준다음
            for(auto i = vec[S].begin(); i != vec[S].end(); i++)
                Q.push({i->first + W, i->second}); // 도착점과 연결되어있는 모든 노드에 도착점의 가중치 W와 연결된 노드의 간선의 가중치를 더해서 queue에 푸쉬한다
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    cin >> K;
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({w, v});
    }
    Dijkstra(K);
    for(int i = 1; i <= V; i++)
    {
        if(i == K) cout << 0 << "\n"; // K값은 무조건 0을 출력
        else
        {
            if(!score[i]) cout << "INF\n"; // score가 0에서 변동이 없는 경우 방문할 수 있는 길이 없으므로 INF를 출력하고
            else cout << score[i] << "\n"; // 아닌 경우 해당 노드의 가중치 출력
        }
    }
}
