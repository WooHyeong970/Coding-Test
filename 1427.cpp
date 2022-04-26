#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int arr[20];

bool cmp(int x, int y){
    return x > y;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++)
        arr[i] = s[i] - '0';
    sort(arr, arr + s.length(), cmp);
    for(int i = 0; i < s.length(); i++)
        cout << arr[i];
    cout << "\n";
}
