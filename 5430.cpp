#include <iostream>
#include <deque>
#include <string>

using namespace std;

int t, n;
string s;
char c;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        string temp1, temp2;
        deque<string> dq;
        bool start = true, isValid = false;
        cin >> s;
        cin >> n;
        while(cin >> c)
        {
            if(c == '[')
            {
                dq.push_back("[");
                continue;
            }
            else if(c == ',')
            {
                dq.push_back(temp2);
                dq.push_back(",");
                temp2 = "";
                continue;
            }
            else if(c == ']')
            {
                if(temp2 != "") dq.push_back(temp2);
                dq.push_back("]");
                break;
            }
            temp1 = c;
            temp2 += temp1;
        }
        for(char i : s)
        {
            if(isValid) break;
            if(i == 'R')
                start = !start;
            else
            {
                if(start)
                {
                    for(int i = 0; i < 2; i++)
                        dq.pop_front();
                    if(dq.empty()) isValid = true;
                    else if(dq.front() == "]") dq.push_front("[");
                    else
                    {
                        dq.pop_front();
                        dq.push_front("[");
                    }
                }
                else
                {
                    for(int i = 0; i < 2; i++)
                        dq.pop_back();
                    if(dq.empty()) isValid = true;
                    else if(dq.back() == "[") dq.push_back("]");
                    else
                    {
                        dq.pop_back();
                        dq.push_back("]");
                    }
                }
            }
        }
        if(!isValid)
        {
            if(start)
            {
                while(!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();
                }
            }
            else
            {
                dq.pop_back();
                dq.pop_front();
                cout << "[";
                while(!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                cout << "]";
            }
        }
        else
            cout << "error";
        cout << "\n";
    }
}
