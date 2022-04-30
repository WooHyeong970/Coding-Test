#include <iostream>
#include <string>

using namespace std;

int check[10];
int sum(-1);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        check[s[i] - '0']++;
    }
    if((check[6] + check[9]) % 2 == 0)
        check[6] = (check[6] + check[9]) / 2;
    else
        check[6] = (check[6] + check[9]) / 2 + 1;
    check[9] = check[6];
    for(int j = 0; j < 10; j++)
    {
        if(sum < check[j])
            sum = check[j];
    }
    cout << sum << "\n";
}
