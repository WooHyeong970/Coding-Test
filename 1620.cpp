#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2)
{
    if(p1.first.compare(p2.first) < 0)
        return true;
    else
        return false;
}

int n, m;
string poketmon[100000]; // 인덱스로 포켓몬의 이름을 찾기위한 배열
pair<string, int> poketmon_sorted[100000]; // 정렬 후 포켓몬의 이름으로 이분탐색을 진행하고 해당 포켓몬의 number를 출력하기 위한 배열

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        poketmon[i] = name;
        poketmon_sorted[i].first = name; // first에는 이름을, second에는 포켓몬 number를 넣어주고
        poketmon_sorted[i].second = i;
    }
    sort(poketmon_sorted, poketmon_sorted + n, cmp); // 포켓몬의 이름을 기준으로 정렬한다
    for(int i = 0; i < m; i++)
    {
        string question;
        cin >> question;
        if(static_cast<int>(question[0]) > 0 && static_cast<int>(question[0] - 48) < 10) // 입력된 question이 숫자면 이쪽으로
        {
            int number;
            number = stoi(question);
            cout << poketmon[number - 1] << "\n"; // 입력된 number에 해당하는 포켓몬의 이름 출력
        }
        else // 입력된 question이 문장이면 이쪽으로
        {
            int head(0), tail(n), mid;
            while(head <= tail) // 포켓몬이 이름이 오름차순으로 정렬되어 있으니 이진탐색을 통해 해당 포켓몬을 찾고 원소의 second값을 출력
            {
                mid = (head + tail) / 2;
                if(poketmon_sorted[mid].first.compare(question) > 0)
                    tail = mid - 1;
                else if(poketmon_sorted[mid].first.compare(question) < 0)
                    head = mid + 1;
                else
                {
                    cout << poketmon_sorted[mid].second + 1 << "\n";
                    break;
                }
            }
        }
    }
}
