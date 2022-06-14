#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct node_info
{
    int start;
    int end;
    int weight;
}INFO;

int arr[100001][3];
int n, s, e, w, m(-1);
bool check[100001];
vector<pair<int, int>> vec[100001];
stack<INFO> st;

void push(int e, bool b)
{
    for(int i = 0; i < vec[e].size(); i++)
    {
        if(check[vec[e][i].first] == b)
        {
            INFO info { e, vec[e][i].first, vec[e][i].second };
            st.push(info);
        }
    }
}

void func()
{
    for(int i = 0; i < vec[1].size(); i++)
    {
        INFO info { 1, vec[1][i].first, vec[1][i].second };
        st.push(info);
        vec[1][i].second = true;
    }
    check[1] = true;
    while(!st.empty())
    {
        int start = st.top().start;
        int end = st.top().end;
        int weight = st.top().weight;
        if(check[end]) weight += arr[start][2];
        st.pop();
        
        if(!arr[end][0]) arr[end][0] = weight;
        else if(!arr[end][1]) arr[end][1] = weight;
        else
        {
            if(weight > arr[end][0])
            {
                if(arr[end][0] > arr[end][1]) arr[end][1] = weight;
                else arr[end][0] = weight;
            }
            else if(weight > arr[end][1])
                arr[end][1] = weight;
        }
        if(check[end] && weight > arr[end][2]) arr[end][2] = weight;
        if(arr[end][0] + arr[end][1] > m) m = arr[end][0] + arr[end][1];
        if(check[end]) continue;
        push(end, 1);
        push(end, 0);
        check[end] = true;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> s;
        while(true)
        {
            cin >> e;
            if(e == -1) break;
            cin >> w;
            vec[s].push_back(make_pair(e, w));
        }
    }
    func();
    cout << m << "\n";
}
