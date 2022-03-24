#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

bool stable_cmp(pair<int, int> x, pair<int, int> y)
{
    return x.second > y.second;
}

int n, sum(0), low(4001), high(-4001);
int arr[500000];
vector<pair<int, int>> vec;
map<int, int> M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a; // 산술평균을 위한 합
        arr[i] = a; // 중앙값을 위한 배열
        if(M.find(a) != M.end()) // 최빈값을 구하기 위해 map으로 입력받은 수를 오름차순으로 자동 정렬하고 각 수의 빈도를 value에 저장한다
            M[a] = M[a] + 1;
        else
            M.insert({a, 1});
        if(a > high) // 범위를 위한 max값 구하기
            high = a;
        if(a < low) // 범위를 위한 min값 구하기
            low = a;
    }
    // 1. 산술평균
    cout << int(floor(double(sum) / double(n) + 0.5)) << "\n";
    // 2. 중앙값
    sort(arr, arr + n);
    cout << arr[n / 2] << "\n";
    // 3. 최빈값
    for(auto i : M) // first는 오름차순으로, second는 내림차순으로 정렬하기 위해 map을 vector로 변환한다
        vec.push_back({i.first, i.second});
    stable_sort(vec.begin(), vec.end(), stable_cmp);
    vector<pair<int, int>>::iterator iter = vec.begin();
    vector<pair<int, int>>::iterator cmp_iter = vec.begin();
    cmp_iter++;
    if(iter->second == cmp_iter->second)
        cout << cmp_iter->first << "\n"; // 만약 첫 번째 원소의 second와 두 번째 원소의 second가 같으면 두 번째로 작은 원소를 출력해야 하므로 cmp_iter->first 출력
    else
        cout << iter->first << "\n"; // 첫 번째 원소와 두 번째 원소의 second가 다르면 중복되는 최빈값이 없으므로 첫 번째 원소의 first를 출력
    // 4. 범위
    cout << high - low << "\n";
}
