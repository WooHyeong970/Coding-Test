#include <iostream>

using namespace std;

int s, k, h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> k >> h;
    if(s + k + h >= 100)
        cout << "OK\n";
    else
    {
        if(s > k)
        {
            if(k > h) // h
                cout << "Hanyang\n";
            else // k
                cout << "Korea\n";
        }
        else
        {
            if(s > h) // h
                cout << "Hanyang\n";
            else // s
                cout << "Soongsil\n";
        }
    }
}
