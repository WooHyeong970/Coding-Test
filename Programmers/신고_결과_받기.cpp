#include <iostream>
#include <vector>

using namespace std;

int reportCount[1000], mailNumber[1000];
bool isFullFrequency[1000];
bool check[1000][1000];

pair<string, string> seperate(string s)
{
    string p, n;
    bool flag = false;
    for(int i = 0; i < s.length(); i++)
    {
        if(!flag)
        {
            if(s[i] == ' ')
            {
                flag = true;
                continue;
            }
            p.push_back(s[i]);
        }
        else
            n.push_back(s[i]);
    }
    return make_pair(p, n);
}

int getIndex(string s, vector<string> id)
{
    int index(0);
    for(int i = 0; i < id.size(); i++)
    {
        if(s == id[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

vector<int> solution(vector<string> id, vector<string> report, int k)
{
    vector<pair<int, int>> fromTo;
    for(string s : report)
    {
        pair<string, string> p = seperate(s);
        int user_index = getIndex(p.first, id);
        int report_index = getIndex(p.second, id);
        if(!check[user_index][report_index])
        {
            check[user_index][report_index] = true;
            fromTo.push_back(make_pair(user_index, report_index));
            reportCount[report_index]++;
            if(reportCount[report_index] >= k)
                isFullFrequency[report_index] = true;
        }
    }
    for(pair<int, int> i : fromTo)
    {
        if(isFullFrequency[i.second])
            mailNumber[i.first]++;
    }
    vector<int> vec(mailNumber, mailNumber + id.size());
    return vec;
}
