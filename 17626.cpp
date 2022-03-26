#include <iostream>
#include <cmath>

using namespace std;

int arr[223];
int n;

bool inArr(int a) // sqrt(a)와 int(sqrt(a))가 같으면 223 이하의 어떤 자연수의 제곱근이라 판단
{
    return sqrt(a) == int(sqrt(a));
}

// minimum 3 개 및 4 개
void stepByThree(int a)
{
    for(int i = 0; i < 223; i++)
    {
        int x = a - arr[i];
        for(int j = 0; j < 223; j++)
        {
            int y = x - arr[j];
            if(y < 0)
                break;
            if(inArr(y))
            {
                cout << 3 << "\n";
                return;
            }
        }
    }
    cout << 4 << "\n"; // minimum이 3개에서도 걸리지 않으면 4를 출력
}

// minimum 2 개
void stepByTwo(int a)
{
    for(int i = 0; i < 223; i++)
    {
        int x = a - arr[i];
        if(inArr(x))
        {
            cout << 2 << "\n";
            return;
        }
    }
    stepByThree(a);
}

// minimum 1 개
void stepByOne(int a)
{
    if(inArr(a))
        cout << 1 << "\n";
    else
        stepByTwo(a);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 223; i++)
        arr[i] = (i + 1) * (i + 1);
    cin >> n;
    stepByOne(n);
}
