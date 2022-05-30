#include <iostream>

using namespace std;

int t;
int a, b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        int num(1), result(0);
        cin >> a >> b;
        for(int i = 0; i < b; i++)
        {
            result = (num * a) % 10;
            num = result;
        }
        if(!result)
            cout << "10\n";
        else
            cout << result << "\n";
    }
}
