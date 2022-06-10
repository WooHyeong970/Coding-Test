#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int answer(0);

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void Combination(vector<int> num, vector<int> comb, int r, int index, int depth) {
    if(r == 0) {
        int sum(0);
        for(int i : comb) sum += i;
        if(isPrime(sum)) answer++;
        return;
    }
    if(depth == num.size()) return;
    comb[index] = num[depth];
    Combination(num, comb, r - 1, index + 1, depth + 1);
    Combination(num, comb, r, index, depth + 1);
}

int solution(vector<int> nums) {
    int r(3);
    vector<int> comb(3);
    Combination(nums, comb, r, 0, 0);
    return answer;
}
