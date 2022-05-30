#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[10001];
int n, s, e, w, r(0);

int recursion(int k)
{
    vector<int>::iterator iter = vec[k].begin() + 3;
    if(iter == vec[k].end()) return vec[k][0];
    for(auto i = iter;i != vec[k].end(); i++)
    {
        int j = recursion(*i);
        if(vec[k][1] > vec[k][2])
        {
            if(j > vec[k][2]) vec[k][2] = j;
        }
        else
        {
            if(j > vec[k][1]) vec[k][1] = j;
        }
    }
    int dia = vec[k][1] + vec[k][2];
    if(r < dia) r = dia;
    int m = vec[k][1] > vec[k][2] ? vec[k][1] : vec[k][2];
    return vec[k][0] + m;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vec[1].push_back(0);
    vec[1].push_back(0);
    vec[1].push_back(0);
    for(int i = 1; i < n; i++)
    {
        cin >> s >> e >> w;
        vec[s].push_back(e);
        vec[e].push_back(w);
        vec[e].push_back(0);
        vec[e].push_back(0);
    }
    recursion(1);
    cout << r << "\n";
}
