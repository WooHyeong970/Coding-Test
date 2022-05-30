#include <iostream>

using namespace std;

int n, k;
int W[101], V[101];
int bag[101][100001];

int getMax(int x, int y)
{
    if(x >= y) return x;
    else return y;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> W[i] >> V[i];
    for(int i = 1; i <= n; i++) // 1부터 n까지
    {
        for(int j = 1; j <= k; j++) // 그리고 1부터 k까지 이중 for문을 돌리는데
        {
            if(W[i] <= j) // i번째 물건의 무게가 j보다 가벼운 경우에는 i번째 물건을 배낭에 넣을 수 있다는 뜻인데
                // bag[i - 1][j]라는 것은 바로 일전에 가방에 넣어둔 물건의 값어치이고
                // bag[i - 1][j - W[i]] 라는 것은 i번째 물건을 가방에 넣고도 일전에 가방의 남은 무게에 더 넣을 수 있는 물건이 있었는지 확인하는 것으로
                // bag[i - 1][j - W[i]]에 넣을 수 있는 물건이 없었더라면 0에 V[i]를 더했을 것이고, 있다면 그 물건의 값어치와 i번째 물건의 값어치(V[i])를 더하고
                // bag[i - 1][j]와 bag[i - 1][j - W[i]]중 값어치가 큰 값을 리턴한다
                bag[i][j] = getMax(bag[i - 1][j], bag[i - 1][j - W[i]] + V[i]);
            else
                bag[i][j] = bag[i - 1][j]; // 위의 상황을 만족하지 못한다면 일전에 넣어둔 물건의 값어치를 다시 입력한다
        }
    }
    cout << bag[n][k] << "\n";
}
