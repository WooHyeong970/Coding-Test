#include <vector>
#include <algorithm>

using namespace std;

int num_k(vector<int> a, vector<int> c) {
    vector<int> b;
    for(int i = c[0]; i <= c[1]; i++)
        b.push_back(a[i - 1]);
    sort(b.begin(), b.end());
    return b[c[2] - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++)
        answer.push_back(num_k(array, commands[i]));
    return answer;
}
