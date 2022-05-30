#include <iostream>
#include <string>

using namespace std;

string s1, s2;
int lcs[1001][1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for(int i = 1; i <= s2.length(); i++)
    {
        for(int j = 1; j <= s1.length(); j++)
        {
            if(s2[i - 1] == s1[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
        }
    }
    cout << lcs[s2.length()][s1.length()] << "\n";
}
