#include <iostream>

using namespace std;

pair<int, int> p, c, t;
int n;

void fibonacci(int a)
{
    if(a == 0)
        cout << p.first << " " << p.second << "\n"; // 0 혹은 1일 경우에는 각각 p와 c의 first, second를 출력하고 끝낸다
    else if(a == 1)
        cout << c.first << " " << c.second << "\n";
    else
    {
        for(int i = 0; i < (a - 1); i++) // 2이상의 수가 들어오면 t에 p와 c의 first, second를 더하고서 p에 c를, c에 t를 넣어주는 과정을 반복
        {
            t = {p.first + c.first, p.second + c.second};
            p = c;
            c = t;
        }
        cout << c.first << " " << c.second << "\n"; // 최종 c 출력
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        p = {1, 0}; // p와 c를 매 반복마다 {1, 0} , {0, 1}로 초기화한다
        c = {0, 1};
        int m;
        cin >> m;
        fibonacci(m);
    }
}
