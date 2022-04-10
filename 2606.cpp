#include <iostream>
#include <vector>
#define X first
#define Y second

using namespace std;

bool check[101];
vector<pair<int, int>> vec;
int c, n;
int sum(0);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }
    check[1] = true; // 1을 true로 초기값을 잡고
    while(true)
    {
        bool isVaild = false; // isVaild는 vec을 begin부터 end까지 살펴보는데 변화가 있는지 없는지를 판별할 bool 변수
        for(auto i = vec.begin(); i != vec.end(); i++)
        {
            if((check[i->X] && !check[i->Y]) || (!check[i->X] && check[i->Y])) // 만약 X, Y중 한 곳만 바이러스가 감염되어있다면
            {
                isVaild = true; // 둘다 감염을 시키고 isVaild는 true로 만들어서 한번이라도 변화가 있었음을 명시해줌
                check[i->X] = true;
                check[i->Y] = true;
            }
        }
        if(!isVaild) // 변화가 한 번도 없다면 반복문 탈출
            break;
    }
    for(bool b : check)
    {
        if(b)
            sum++;
    }
    cout << sum - 1 << "\n"; // 1번 컴퓨터의 경우 개수에 포함되지 않으니 1을 빼주고 결과값 출력
}
