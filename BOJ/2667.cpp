#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

queue<pair<int, int>> Q;
vector<int> vec;
int board[30][30];
bool check[30][30];
int n, sum(0);
int dx[4] {0, 1, 0, -1};
int dy[4] {1, 0, -1, 0};
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < n; j++)
            board[i][j] = s[j] - '0';
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 1 && !check[i][j]) // 방문한 주소가 집이 있고 한번도 방문하지 않은 곳이면 주변을 탐색!
            {
                int s(0);
                sum++; // 총 단지수에 1을 더해주고
                Q.push({i, j});
                check[i][j] = true; // 현재 주소는 방문했음을 남기고
                while(!Q.empty()) // BFS시작
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    s++;
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(check[nx][ny] || !board[nx][ny]) continue;
                        Q.push({nx, ny});
                        check[nx][ny] = true;
                    }
                }
                vec.push_back(s); // BFS가 끝났다면 해당 단지의 가구수를 vec에 push한다
            }
        }
    }
    sort(vec.begin(), vec.end()); // 모든 가구수를 오름차순으로 정렬하고 출력하면 문제 해결
    cout << sum << "\n";
    for(auto i : vec)
        cout << i << "\n";
}
