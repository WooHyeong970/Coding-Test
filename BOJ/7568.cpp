#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> vec;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int weight, height;
        cin >> weight >> height;
        vec.push_back({weight, height});
    }
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
        int rank(1);
        for(auto j = vec.begin(); j != vec.end(); j++)
        {
            if(i->first < j->first && i->second < j->second)
                rank++;
        }
        cout << rank << "\n";
    }
}
