#include <iostream>
#include <queue>

using namespace std;

int t;
int nume_array[30], deno_array[30];
queue<int> nume_Q, deno_Q;

// 큐를 비우는 함수
void empty()
{
    while(!nume_Q.empty())
        nume_Q.pop();
    while(!deno_Q.empty())
        deno_Q.pop();
}

// 팩토리얼 숫자들로 배열을 초기화하는 함수
void setArray(int s, int b)
{
    for(int i = 0; i < s; i++)
    {
        nume_array[i] = b + i + 1;
        deno_array[i] = i + 1;
    }
}

// 소인수분해 값을 큐에 push할 함수
void setQ(queue<int>* Q, int arr[], int s)
{
    for(int i = 0; i < s; i++)
    {
        while(true)
        {
            if(arr[i] == 1)
                break;
            for(int j = 2; j <= arr[i]; j++)
            {
                if(arr[i] % j == 0)
                {
                    Q->push(j);
                    arr[i] = arr[i] / j;
                    break;
                }
            }
        }
    }
}

// 분모,분자 공통인수 지우기
void eraseNumber()
{
    while(!deno_Q.empty())
    {
        if(deno_Q.front() == nume_Q.front())
        {
            deno_Q.pop();
            nume_Q.pop();
        }
        nume_Q.push(nume_Q.front());
        nume_Q.pop();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        long long sum(1);
        int n, r, s, b;
        cin >> n >> r;
        if(n == r)
        {
            cout << 1 << "\n";
            continue;
        }
        if(n == 1 || (r - n) == 1)
        {
            cout << r << "\n";
            continue;
        }
        s = (r - n) > n ? n : (r - n);
        b = (r - n) < n ? n : (r - n);
        setArray(s, b);
        setQ(&nume_Q, nume_array, s);
        setQ(&deno_Q, deno_array, s);
        eraseNumber();
        while(!nume_Q.empty())
        {
            sum *= nume_Q.front();
            nume_Q.pop();
        }
        cout << sum << "\n";
        empty();
    }
}
