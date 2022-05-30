#include <iostream>
#include <string>
#define LL long long

using namespace std;

void TentoTwo(LL n)
{
    if(n < 2)
        cout << n;
    else
    {
        TentoTwo(n / 2);
        cout << n % 2;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string b1, b2, b3;
    LL b1_n(0), b2_n(0);
    LL b1_p(0), b2_p(0);
    LL s(0);
    cin >> b1 >> b2;
    for(int i = (int(b1.length()) - 1); i >= 0; i--)
    {
        if(b1[i] == '1')
            b1_n += 1 << b1_p;
        b1_p++;
    }
        
    for(int j = (int(b2.length()) - 1); j >= 0; j--)
    {
        if(b2[j] == '1')
            b2_n += 1 << b2_p;
        b2_p++;
    }
    s = b1_n * b2_n;
    TentoTwo(s);
    cout << "\n";
}
