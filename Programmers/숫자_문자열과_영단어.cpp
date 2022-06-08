#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    string new_s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9') new_s.push_back(s[i]);
        else
        {
            if(s[i] == 'o')
            {
                new_s.push_back('1');
                i += 2;
            }
            else if(s[i] == 't')
            {
                if(s[i + 1] == 'w')
                {
                    new_s.push_back('2');
                    i += 2;
                }
                else
                {
                    new_s.push_back('3');
                    i += 4;
                }
            }
            else if(s[i] == 'f')
            {
                if(s[i + 1] == 'o')
                {
                    new_s.push_back('4');
                    i += 3;
                }
                else
                {
                    new_s.push_back('5');
                    i += 3;
                }
            }
            else if(s[i] == 's')
            {
                if(s[i + 1] == 'i')
                {
                    new_s.push_back('6');
                    i += 2;
                }
                else
                {
                    new_s.push_back('7');
                    i += 4;
                }
            }
            else if(s[i] == 'e')
            {
                new_s.push_back('8');
                i += 4;
            }
            else if(s[i] == 'n')
            {
                new_s.push_back('9');
                i += 3;
            }
            else if(s[i] == 'z')
            {
                new_s.push_back('0');
                i += 3;
            }
        }
    }
    return stoi(new_s);
}
