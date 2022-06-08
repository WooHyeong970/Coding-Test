#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, pair<int, int>>> vec;
pair<int, int> numCoor, l_coor({3, 0}), r_coor({3, 2});

void setVec() {
    int idx(1);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++)
            vec.push_back({ i + j + idx, { i, j }});
        idx += 2;
    }
    vec[10].first = 0;
}

pair<int, int> getCoor(int n) {
    for(auto i : vec)
        if(i.first == n) numCoor = i.second;
    return numCoor;
}

int getLen(pair<int, int> start, pair<int, int> target) {
    return abs(start.first - target.first) + abs(start.second - target.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    setVec();
    for(int i : numbers) {
        if(i == 1 || i == 4 || i == 7)
            answer.push_back('L');
        else if(i == 3 || i == 6 || i == 9)
            answer.push_back('R');
        else
        {
            int l_len = getLen(l_coor, getCoor(i));
            int r_len = getLen(r_coor, getCoor(i));
            if(l_len == r_len)
            {
                if(hand == "left") answer.push_back('L');
                else answer.push_back('R');
            }
            else
                answer.push_back(l_len < r_len ? 'L' : 'R');
        }
        if(answer.back() == 'L') l_coor = getCoor(i);
        else r_coor = getCoor(i);
    }
    return answer;
}
