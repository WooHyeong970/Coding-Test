#include <iostream>
#include <map>
#include <string>

using namespace std;

int t, n;
long long sum(1);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        map<string, int> m;
        cin >> n;
        while(n--)
        {
            string name, wear;
            cin >> name >> wear;
            if(m.find(wear) != m.end())
                m[wear]++;
            else
                m.insert({wear, 1});
        }
        for(auto i = m.begin(); i != m.end(); i++)
            sum *= i->second + 1;
        cout << sum - 1 << "\n";
        sum = 1;
    }
}
