#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char checkArray[13] { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '_', '.'};
bool checkFind[1000];

bool findChar(char c)
{
    for(char i : checkArray)
    {
        if(i == c)
            return true;
    }
    return false;
}

string stepSeven(string id)
{
    string new_id = id;
    for(int i = 0; i < 3 - id.length(); i++)
        new_id.push_back(id.back());
    return new_id;
}

string stepSix(string id)
{
    string new_id;
    for(int i = 0; i < 15; i++)
        new_id.push_back(id[i]);
    if(new_id.back() == '.') new_id.pop_back();
    return new_id;
}

string stepFive(string id)
{
    if(id.length() == 0)
        id = "aaa";
    if(id.length() > 15) return stepSix(id);
    else if(id.length() < 3) return stepSeven(id);
    else return id;
}

string stepFour(string id)
{
    if(id.length() > 0)
        if(id[0] == '.') id.erase(0, 1);
    if(id.length() > 0)
        if(id.back() == '.') id.pop_back();
    return stepFive(id);
}

string stepThree(string id)
{
    bool isComma = false;
    memset(checkFind, 0, sizeof(checkFind));
    for(int i = 0; i < id.length(); i++)
    {
        if(id[i] != '.')
        {
            if(isComma)
                isComma = false;
        }
        else
        {
            if(isComma)
                checkFind[i] = true;
            else
                isComma = true;
        }
    }
    string new_id;
    for(int i = 0; i < id.length(); i++)
    {
        if(!checkFind[i])
            new_id.push_back(id[i]);
    }
    return stepFour(new_id);
}

string stepTwo(string id)
{
    for(int i = 0; i < id.length(); i++)
    {
        if(findChar(id[i]) || (id[i] > 96 && id[i] < 123))
            checkFind[i] = true;
    }
        
    string new_id;
    for(int i = 0; i < id.length(); i++)
    {
        if(checkFind[i])
            new_id.push_back(id[i]);
    }
    return stepThree(new_id);
}

string stepOne(string id)
{
    for(int i = 0; i < id.length(); i++)
    {
        if(id[i] > 64 && id[i] < 91)
            id[i] = id[i] + 32;
    }
    return stepTwo(id);
}

string solution(string new_id) {
    string answer = stepOne(new_id);
    return answer;
}
