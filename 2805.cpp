#include <iostream>
#include <map>
#define LL long long

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<LL, LL> M;
    int n;
    LL m, head(0), tail(-1), mid(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        LL a;
        cin >> a;
        if(a > tail)
            tail = a;
        if(M.find(a) != M.end())
            M[a] = M[a] + 1;
        else
            M[a] = 1;
    }
    while(head <= tail)
    {
        mid = (head + tail) / 2;
        LL sum(0);
        for(auto i = M.begin(); i != M.end(); i++)
        {
            if((i->first - mid) > 0)
            {
                for(int j = 0; j < i->second; j++)
                    sum += i->first - mid;
            }
        }
        if(sum < m)
            tail = mid - 1;
        else
            head = mid + 1;
    }
    cout << tail << "\n";
}
