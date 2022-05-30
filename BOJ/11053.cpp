#include <iostream>

using namespace std;

int n, d(1);
int arr[1000], dist[1000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    dist[0] = 1; // 0번째 길이값을 1로 초기화하고
    for(int i = 1; i < n; i++) // 1번째부터 n-1까지
    {
        int max_dist(0);
        int cur_num = arr[i];
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < cur_num) // i번째보다 값이 작으면서
            {
                if(dist[j] > max_dist) // 길이값이 가장 큰 값을 찾고
                    max_dist = dist[j];
            }
        }
        if(!max_dist) dist[i] = 1; // max_dist가 0이면 어떠한 조건도 해당이 없으므로 길이값을 1로하고
        else dist[i] = max_dist + 1; // 0이 아니라면 max_dist에서 길이가 1 늘었으므로 +1을 해준다
        if(d < dist[i]) d = dist[i]; // d는 0부터 n-1까지의 배열에서 가장 길이가 긴 값을 찾고
    }
    cout << d << "\n"; // d를 출력하면 문제 해결
}
