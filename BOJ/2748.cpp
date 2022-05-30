#include <iostream>
#define LL long long

using namespace std;

LL fibo[91];
LL cur, pre;
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= 90; i++)
    {
        pre = fibo[i - 2];
        cur = fibo[i - 1];
        fibo[i] = pre + cur;
    }
    cout << fibo[n] << "\n";
}
