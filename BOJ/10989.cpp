#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int , int> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(m.find(a) != m.end())
            m[a] = m[a] + 1;
        else
            m.insert({a, 1});
    }
    for(auto i = m.begin(); i != m.end(); i++)
    {
        for(int j = 0; j < i->second; j++)
            cout << i->first << "\n";
    }
}
