#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string movie = "666";
    int n, m(666);
    cin >> n;
    while(true)
    {
        string m_str = to_string(m);
        if(m_str.find(movie) != string::npos)
        {
            n--;
            if(n == 0)
                break;
        }
        m++;
    }
    cout << m << "\n";
}
