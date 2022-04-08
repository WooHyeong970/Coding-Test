#include <iostream>
#include <string>

using namespace std;

string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int idx(0);
    cin >> s;
    for(char c : s)
    {
        if(idx > 9)
        {
            idx = 0;
            cout << "\n";
        }
        cout << c;
        idx++;
    }
}
