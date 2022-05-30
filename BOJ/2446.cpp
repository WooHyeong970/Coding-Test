#include <iostream>

using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = n; i > 0; i--)
    {
        for(int j = 0; j < n - i; j++) cout << " ";
        for(int k = 0; k < (i * 2) - 1; k++) cout << "*";
        cout << "\n";
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n - (i + 1); j++) cout << " ";
        for(int k = 0; k < (i * 2) + 1; k++) cout << "*";
        cout << "\n";
    }
}
