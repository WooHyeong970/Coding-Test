#include <iostream>

using namespace std;

int main(void)
{
	int x; // �Է°�
	int num = 1, den = 1; // ����, �и� ��
	int sum = 1;
	int line = 2;
	cin >> x;
	if (x == 1) // �Է°��� 1�̸� 1/1 ���
		cout << num << "/" << den << endl;
	else
	{
		while ((x - sum) > line) // ���� ū line�� �߷�����
			sum += line++;
		x -= sum; // ������ ���� ���� ��
		if (line % 2 == 0) // ¦���� �и� ū ������ ����
		{
			den = line;
			cout << num + (x - 1) << "/" << den - (x - 1) << endl;
		}
		else // Ȧ���� ���ڰ� ū ������ ����
		{
			num = line;
			cout << num - (x - 1) << "/" << den + (x - 1) << endl;
		}
	}
	return 0;
}