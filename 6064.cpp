#include <iostream>

using namespace std;

int t;
int n, m, x, y;

int getGCD(int a, int b) // 최대공약수 구하기
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int getLCM(int a, int b) // 최소공배수 구하기
{
    return a * b / getGCD(a, b);
}

void getYear(int n, int m, int x, int y)
{
    int year, max;
    bool isValid = false;
    max = getLCM(n, m);
    year = x;
    while(year <= max) // 두 수의 최소공배수가 마지막 년도가 되므로 최소공배수를 넘지않는 선에서
    {
        // year에 x를 넣고 year를 m으로 나눈 나머지가 y와 같으면 해당 year가 찾고자하는 연도가 되므로
        // x부터 시작해서 year를 m으로 나눈 나머지가 y와 같지 않다면 year에 n을 더해주며 값을 올리고
        // 만약 m과 y가 같은 경우에는 year를 m으로 나눈 나머지가 0일 때에 찾고자하는 연도가 되도록 조건을 걸어준다
        // year가 조건을 만족할 경우 isValid에 true를 넣고 반복문 종료
        if(year % m == y || (m == y && year % m == 0))
        {
            cout << year << "\n";
            isValid = true;
            break;
        }
        else year += n;
    }
    if(!isValid) cout << -1 << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        if(n >= m) getYear(n, m, x, y);
        else getYear(m, n, y, x);
    }
}
