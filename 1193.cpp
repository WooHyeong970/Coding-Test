#include <iostream>

using namespace std;

int main(void)
{
	int x; // 입력값
	int num = 1, den = 1; // 분자, 분모 값
	int sum = 1;
	int line = 2;
	cin >> x;
	if (x == 1) // 입력값이 1이면 1/1 출력
		cout << num << "/" << den << endl;
	else
	{
		while ((x - sum) > line) // 가장 큰 line을 추려내고
			sum += line++;
		x -= sum; // 나머지 값을 구한 뒤
		if (line % 2 == 0) // 짝수면 분모가 큰 값으로 들어간다
		{
			den = line;
			cout << num + (x - 1) << "/" << den - (x - 1) << endl;
		}
		else // 홀수면 분자가 큰 값으로 들어간다
		{
			num = line;
			cout << num - (x - 1) << "/" << den + (x - 1) << endl;
		}
	}
	return 0;
}