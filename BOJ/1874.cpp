#include <iostream>
#include <stack>
#include <vector>
#define N 100000

using namespace std;

int arr[N];
int n;
int idx(1);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;
    vector<char> vec;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    st.push(0);
    for(int i = 0; i < n; i++)
    {
        if(st.top() < arr[i])
        {
            while(true)
            {
                st.push(idx);
                idx++;
                vec.push_back('+');
                if(st.top() == arr[i])
                    break;
                else if(st.top() > arr[i])
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
        else
        {
            while(true)
            {
                if(st.top() == arr[i])
                    break;
                else if(st.top() < arr[i])
                {
                    cout << "NO\n";
                    return 0;
                }
                st.pop();
                vec.push_back('-');
            }
        }
        st.pop();
        vec.push_back('-');
    }
    for(char c : vec)
        cout << c << "\n";
}
