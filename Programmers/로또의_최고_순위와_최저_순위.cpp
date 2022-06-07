#include <iostream>
#include <vector>

using namespace std;

bool findNumber(int n, vector<int> win_num)
{
    for(int i : win_num)
    {
        if(i == n)
            return true;
    }
    return false;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max(7), min(7);
    for(int i : lottos)
    {
        if(!i)
            max--;
        else
        {
            if(findNumber(i, win_nums))
            {
                max--;
                min--;
            }
        }
    }
    if(max > 6) answer.push_back(6);
    else answer.push_back(max);
    if(min > 6) answer.push_back(6);
    else answer.push_back(min);
    return answer;
}
