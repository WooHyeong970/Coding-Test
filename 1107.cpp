#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n, m, cnt(0), t(100), ib, is;
string s;
bool button[10];

bool isButton(string number) // 고장난 버튼을 눌렀는지 확인하고 눌렀으면 true를 안눌렀으면 false를 반환
{
    bool check = false;
    for(int i = 0; i < number.length(); i++)
    {
        if(button[number[i] - '0'])
        {
            check = true;
            break;
        }
    }
    return check;
}

int getB() // 리모컨의 고장난 버튼을 누르지 않았으면서 n보다 큰 수중 가장 작은수 구하기
{
    int num = n;
    while(true)
    {
        string u = to_string(num);
        if(!isButton(u)) return int(u.length() + abs(n - num));
        num++;
    }
}

int getS() // 리모컨의 고장난 버튼을 누르지 않았으면서 n보다 작은 수중 가장 큰수 구하기
{
    int num = n;
    while(true)
    {
        string u = to_string(num);
        if(!isButton(u)) return int(u.length() + abs(n - num));
        num--;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        button[k] = true;
    }
    if(n == 100) cout << 0 << "\n"; // n이 100일때는 0을 출력
    else
    {
        if(m == 10) // m이 10일 때에는 모든 버튼이 고장났으므로 이동횟수를 출력
            cout << abs(n - t) << "\n";
        else if(m == 9 && !button[0]) // m이 9이고 0버튼만 누를 수 있다면
        {
            if(n < 50) // n이 50보다 작을때에는 0으로 먼저 이동하고 그 후에 이동횟수를 구하면 되고
                cout << n + 1 << "\n";
            else
                cout << abs(n - t) << "\n"; // 그게 아니라면 n-t
        }
        else
        {
            int x = getB() < getS() ? getB() : getS(); // getB와 getS와 n-t 중에서 가장 작은 수를 출력
            if(x > abs(n - t)) cout << abs(n - t) << "\n";
            else cout << x << "\n";
        }
    }
}
