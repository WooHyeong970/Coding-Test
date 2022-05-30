#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n + 1); // 길이 n의 벡터를 선언하고

    vec[1] = 0; // index 1은 0으로 초기화
    for(int i = 2; i <= n; i++)
    {
        vec[i] = vec[i - 1] + 1; // i는 2부터 시작해서 먼저는 vec[i]에 vec[i - 1]의 값을 넣어주고
        if(i % 3 == 0) // 3으로 나눠 떨어지거나 2로 나눠 떨어지는 경우
            vec[i] = min(vec[i], vec[i / 3] + 1); // vec[i]에 넣을 값을 vec[i]와 vec[i / 3] + 1과 vec[i / 2] + 1의 값을 모두 비교하여 가장 작은 값을 넣는다
        if(i % 2 == 0) // 여기서 else if로 해버리면 3으로 나누어 떨어지는 경우 이쪽을 거치지 않으니 꼭 if로 하자
            vec[i] = min(vec[i], vec[i / 2] + 1);
    }
    cout << vec[n] << "\n";
}
