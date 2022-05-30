#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string DMS[500000]; // 듣도 못한 명단 배열
string BMS[500000]; // 듣도 보도 못한 명단 배열
int n, m;
int idx(0);

bool cmp(string s1, string s2)
{
    if(s1.compare(s2) < 0)
        return true;
    else
        return false;
}

bool BinarySearch(string name)
{
    int head(0), tail(n), mid(0);
    while(head <= tail)
    {
        mid = (head + tail) / 2;
        if(DMS[mid].compare(name) > 0)
            tail = mid - 1;
        else if(DMS[mid].compare(name) < 0)
            head = mid + 1;
        else
            return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) // 먼저 듣도 못한 사람들의 명단을 입력받는다
    {
        string d_name;
        cin >> d_name;
        DMS[i] = d_name;
    }
    sort(DMS, DMS + n, cmp); // 보도 못한 사람들의 명단을 입력받았을 때 이진 탐색을 사용하기 위해 이름을 사전순으로 정렬한다
    while(m--)
    {
        string b_name;
        cin >> b_name;
        if(BinarySearch(b_name)) // 보도 못한 사람들의 명단을 입력받고 해당 사람이 듣도 못한 명단에 있을 경우 듣도 보도 못한 명단에 추가한다
            BMS[idx++] = b_name;
    }
    if(idx == 0) // 듣보잡이 한명도 없을 경우 그냥 0을 출력
        cout << 0 << "\n";
    else
    {
        sort(BMS, BMS + idx, cmp); // 사전순 출력을 위해 정렬을 하고
        cout << idx << "\n"; // 명단의 인원수와
        for(int i = 0; i < idx; i++) // 명단을 사전순으로 출력
            cout << BMS[i] << "\n";
    }
}
