#include <iostream>

using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n)
    {
        int idx(1);
        int m(1);
        while(true)
        {
            if(m % n == 0)
            {
                cout << idx << "\n";
                break;
            }
            idx++;
            m %= n;
            m = (m * 10) + 1;
        }
    }
}
