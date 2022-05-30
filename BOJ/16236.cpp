#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> Q;
int board[20][20], dist_board[20][20];
bool check_dist[20][20];
bool isValid = false;
int n, shark_size(2), cur_feed(0), t(0);
int dx[4] {1, 0, -1, 0};
int dy[4] {0, 1, 0, -1};
pair<int, int> curPos;

void setDistBoard()
{
    Q.push(curPos); // 현재 아기상어의 위치를 Q에 넣어주고
    check_dist[curPos.first][curPos.second] = true; // 현재위치를 true로
    dist_board[curPos.first][curPos.second] = 0; // 현재거리를 0으로 초기화
    while(!Q.empty()) // bfs시작
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(check_dist[nx][ny]) continue;
            if(board[nx][ny] > shark_size) // 물고기가 아기상어보다 크기가 크다면
                dist_board[nx][ny] = -1; // -1을 넣고 건너뛰고
            else
            {
                dist_board[nx][ny] = dist_board[cur.first][cur.second] + 1; // 아기상어보다 작거나 같으면 이동 가능하므로 이전 거리에 +1을 해주고
                Q.push({nx, ny}); // Q에 push
            }
            check_dist[nx][ny] = true; // 한 번 이동한 구역이므로 true를 넣어준다
        }
    }
}

void setBoard() // check_dist와 dist_board를 통해 아기상어의 위치를 이동시키는 함수
{
    pair<int, int> nextPos = curPos;
    int shortDist(1000);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist_board[i][j] < 1) continue; // 거리가 0 혹은 -1이면 continue
            if(board[i][j] > 0 && board[i][j] < shark_size) // 물고기가 존재하면서 아기상어보다 작을때
            {
                if(dist_board[i][j] < shortDist) // 그리고 아기상어를 기준으로 물고기까지의 거리가 작은경우에 갱신
                {
                    shortDist = dist_board[i][j];
                    nextPos = {i, j};
                }
            }
        }
    }
    if(curPos == nextPos) // 만약 아기상어의 좌표와 다음의 좌표가 같으면 반복문 탈출
        isValid = true;
    else
    {
        t += dist_board[nextPos.first][nextPos.second]; // 두 좌표가 다르다면 t에 물고기까지의 거리를 추가로 더해주고
        board[curPos.first][curPos.second] = 0; // curPos는 아기상어가 이동했으므로 0으로
        board[nextPos.first][nextPos.second] = 9; // nextPos에 9를 넣어준다
        curPos = nextPos; // curPos에 nextPos를 넣어주고
        cur_feed++; // 물고기를 잡아먹었으니 cur_feed를 1 증가시키는데
        if(cur_feed == shark_size) // cur_feed가 아기상어의 크기와 같아진다면
        {
            cur_feed = 0;
            shark_size++; // 아기상어의 크기를 1 증가시킨다
        }
    }
}

void setCheckDist() // check_dist 재활용을 위한 초기화
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            check_dist[i][j] = false;
    }
}

void setPos(int x, int y) // 현재 좌표 갱신
{
    curPos = {x, y};
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 9)
                setPos(i, j);
        }
    }
    while(!isValid)
    {
        setDistBoard(); // 먼저 아기상어가 이동할 수 있는 구역과 이동에 필요한 시간을 체크하고
        setBoard(); // 잡아먹을 수 있는 가장 가까운 좌표로 아기상어를 이동시키고
        setCheckDist(); // 재활용을 위한 board초기화
    }
    cout << t << "\n";
}
