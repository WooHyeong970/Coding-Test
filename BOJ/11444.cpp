#include <iostream>
#define LL unsigned long long

using namespace std;

typedef struct Matrix_2x2
{
    LL f[2][2];
} Matrix2x2;

LL n;
int m(1000000007);
Matrix2x2 result;

Matrix2x2 multiply(Matrix2x2 a, Matrix2x2 b)
{
    Matrix2x2 c;
    c.f[0][0] = (a.f[0][0] * b.f[0][0] + a.f[0][1] * b.f[1][0]) % m;
    c.f[0][1] = (a.f[0][0] * b.f[0][1] + a.f[0][1] * b.f[1][1]) % m;
    c.f[1][0] = (a.f[1][0] * b.f[0][0] + a.f[1][1] * b.f[1][0]) % m;
    c.f[1][1] = (a.f[1][0] * b.f[0][1] + a.f[1][1] * b.f[1][1]) % m;
    return c;
}

Matrix2x2 fibo(Matrix2x2 a, LL n)
{
    if(n > 1)
    {
        a = fibo(a, n / 2);
        a = multiply(a, a);
        if(n & 1)
        {
            Matrix2x2 f1 = { 1, 1, 1, 0};
            a = multiply(a, f1);
        }
    }
    return a;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    result = { 1, 1, 1, 0};
    result = fibo(result, n);
    cout << result.f[0][1] << "\n";
}
