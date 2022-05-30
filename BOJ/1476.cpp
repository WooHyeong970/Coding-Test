#include <iostream>

using namespace std;

int t_e, t_s, t_m;
int e(0), s(0), m(0);
long long year(0);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t_e >> t_s >> t_m;
    while(true)
    {
        e++;
        if(e > 15)
            e = 1;
        s++;
        if(s > 28)
            s = 1;
        m++;
        if(m > 19)
            m = 1;
        year++;
        if(t_e == e && t_s == s && t_m == m)
            break;
    }
    cout << year << "\n";
}
