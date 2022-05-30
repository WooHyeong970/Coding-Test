#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i * 2; j++)
        {
            if(j == i)
            {
                for(int k = 0; k < (n - i) * 2; k++)
                    cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }
    for(int i = (n - 1); i > 0; i--)
    {
        for(int j = 0; j < i * 2; j++)
        {
            if(j == i)
            {
                for(int k = 0; k < (n - i) * 2; k++)
                    cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }
}
