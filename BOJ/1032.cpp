#include <iostream>
#include <string>

using namespace std;

int n;
string s[50];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < s[0].length(); i++)
    {
        bool isValid = false;
        for(int j = 0; j < n; j++)
        {
            if(s[0][i] != s[j][i])
            {
                isValid = true;
                break;
            }
        }
        if(!isValid) cout << s[0][i];
        else cout << "?";
    }
    cout << "\n";
}
