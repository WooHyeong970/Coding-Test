#include <iostream>
#include <string>

using namespace std;

string s;
char c[10];
int sum(0), idx(0);
bool isMin;

void reset()
{
    idx = 0;
    for(int i = 0; i < 10; i++)
        c[i] = NULL;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '-' || s[i] == '+')
        {
            if(!isMin)
            {
                sum += stoi(c);
                if(s[i] == '-')
                    isMin = true;
            }
            else
                sum -= stoi(c);
            reset();
        }
        else
            c[idx++] = s[i];
    }
    if(!isMin) sum += stoi(c);
    else sum -= stoi(c);
    cout << sum << "\n";
}
