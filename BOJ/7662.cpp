#include <iostream>
#include <map>

using namespace std;

map<int, int> m;
int t, n, k;
char c;

void push(int num) // m에 num값을 넣되 num이 key값으로 있으면 second를 1증가 시킨다
{
    auto a = m.find(num);
    if(a != m.end())
        a->second++;
    else
        m.insert({num, 1});
}

void removeMax() // m의 마지막 값이 max값이므로 마지막 값을 지운다
{
    map<int, int>::iterator iter = m.end();
    iter--;
    if(iter->second == 1)
        m.erase(iter);
    else
        iter->second--;
}

void removeMin() // m의 첫 번째 값을 지운다
{
    map<int, int>::iterator iter = m.begin();
    if(iter->second == 1)
        m.erase(iter);
    else
        iter->second--;
}

int getMax()
{
    map<int, int>::iterator iter = m.end();
    iter--;
    return iter->first;
}

int getMin()
{
    map<int, int>::iterator iter = m.begin();
    return iter->first;
}

void reset()
{
    map<int, int>::iterator iter;
    while(!m.empty())
    {
        iter = m.begin();
        m.erase(iter);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        while(n--)
        {
            cin >> c >> k;
            if(c == 'I') // 입력받은 문자가 I면 push하고
                push(k);
            else
            {
                if(m.empty()) continue; // D인데 m이 비어있다면 continue
                else
                {
                    if(k == 1) // 비어있지 않다면 k값에 따라 max혹은 min값을 지운다
                        removeMax();
                    else
                        removeMin();
                }
            }
        }
        if(m.empty()) // 최종적으로 m이 비어있다면 EMPTY를 출력하고
            cout << "EMPTY\n";
        else // 아닌경우 max와 min을 출력한다
            cout << getMax() << " " << getMin() << "\n";
        reset(); // 다음의 테스트 케이스를 위해 m을 비운다
    }
}
