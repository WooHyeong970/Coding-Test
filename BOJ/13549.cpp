#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;

queue<int> Q;
int n, k;
int arr[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill_n(arr, MAX, MAX);
    arr[n] = 0;
    Q.push(n);
    while(!Q.empty())
    {
        int next;
        int cur = Q.front();
        Q.pop();
        if(cur == k) break;
        
        next = cur * 2;
        if(next >= 0 && next < MAX && arr[cur] < arr[next])
        {
            arr[next] = arr[cur];
            Q.push(next);
        }
        
        next = cur - 1;
        if(next >= 0 && next < MAX && arr[cur] + 1 < arr[next])
        {
            arr[next] = arr[cur] + 1;
            Q.push(next);
        }
        
        next = cur + 1;
        if(next >= 0 && next < MAX && arr[cur] + 1 < arr[next])
        {
            arr[next] = arr[cur] + 1;
            Q.push(next);
        }
    }
    cout << arr[k] << "\n";
}
