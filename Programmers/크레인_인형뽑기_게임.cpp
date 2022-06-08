#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;

int getDoll(vector<vector<int>> &board, int n) {
    for(int i = 0; i < board.size(); i++) {
        if(board[i][n - 1]) {
            int temp = board[i][n - 1];
            board[i][n - 1] = 0;
            return temp;
        }
    }
    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(int i : moves) {
        int doll = getDoll(board, i);
        if(doll) {
            if(st.empty()) st.push(doll);
            else {
                if(st.top() == doll) {
                    answer += 2;
                    st.pop();
                }
                else st.push(doll);
            }
        }
    }
    return answer;
}
