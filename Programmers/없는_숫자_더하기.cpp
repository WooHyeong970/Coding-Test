#include <string>
#include <vector>

using namespace std;

bool check[10];

int solution(vector<int> numbers) {
    int answer(0);
    for(int i : numbers) check[i] = true;
    for(int i = 0; i < 10; i++) if(!check[i]) answer += i;
    return answer;
}
