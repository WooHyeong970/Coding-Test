#include <iostream>
#include <algorithm>

using namespace std;

int n, sum(0);
int A[50], B[50];

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        B[i] = b;
    }
    sort(A, A + n); // A는 오름차순으로
    sort(B, B + n, cmp); // B는 내림차순으로 정렬하고
    for(int i = 0; i < n; i++)
        sum += A[i] * B[i]; // 각 배열의 같은 index의 원소를 곱해서 더한다
    cout << sum << "\n";
}
