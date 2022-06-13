#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
stack<char> st;

void empty(char c)
{
    while(true)
    {
        if(st.top() == c || st.top() == 'e') break;
        if(st.top() == '(')
        {
            st.pop();
            continue;
        }
        cout << st.top();
        st.pop();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    st.push('e');
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            cout << s[i];
        else if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == '*' || s[i] == '/')
        {
            if(st.top() == '*' || st.top() == '/')
            {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-')
        {
            empty('(');
            st.push(s[i]);
        }
        else
        {
            empty('(');
            st.pop();
        }
    }
    empty('e');
    cout << "\n";
}
