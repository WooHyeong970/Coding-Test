#include <iostream>

using namespace std;

int arr1[301][301], arr2[301][301];
int n, m, k, p;
int i, j, x, y;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    p = arr1[0][0];
    for(int a = 1; a <= n; a++)
    {
        for(int b = 1; b <= m; b++)
        {
            cin >> arr1[a][b];
            arr2[a][b] = arr1[a][b] + p;
            p = arr2[a][b];
        }
    }
    cin >> k;
    while(k--)
    {
        int sum(0);
        cin >> i >> j >> x >> y;
        for(int v = i; v <= x; v++)
            sum += arr2[v][y] - arr2[v][j] + arr1[v][j];
        cout << sum << "\n";
    }
}
