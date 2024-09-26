#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Ǯ��.
// �̷� ������ ���ö����� �� �����ϴ°����� ��� Ǯ����� �ϴ°��� �𸣰ڴ�.
// Ȯ�� ��Ŭ���� ȣ���� �̷��� ���а� ���� ��� �ƴϸ� �󸶳� �ȴٰ� �̷��� ����.
// ���̰� ����. ������ �𸣰ڴ�. �˷��� ������ �ʾ�����. ���߿� �ڵ��׽�Ʈ���� �̷� ���� ������
// ������ �ʾ����� �ϴ� �ٷ����̴�.

// �׷��� ���߿� �ѹ� �Ⱦ�� ����.

long long gcd(long long n, long long a)
{
	if (a == 0) return n;
	return gcd(a, n % a);
}

long long extended_euclid(long long n, long long a)
{
	vector<long long> Si = { 1, 0 };
	vector<long long> Ti = { 0, 1 };
	vector<long long> Ri = { n, a };
	long long Qi = n / a;
	long long r1, r2, temp;
	while (1)
	{
		r2 = Ri[Ri.size() - 2];
		r1 = Ri[Ri.size() - 1];

		temp = r2 % r1;
		Ri.push_back(temp);
		if (temp == 0) return Ti[Ti.size() - 1];
		Qi = r2 / r1;
		Si.push_back(Si[Si.size() - 2] - Si[Si.size() - 1] * Qi);
		Ti.push_back(Ti[Ti.size() - 2] - Ti[Ti.size() - 1] * Qi);

	}
}
int main()
{
	long long n, a;
	cin >> n >> a;

	cout << n - a << " ";
	if (gcd(n, a) != 1)
	{
		cout << -1;
		return 0;
	}

	long long ret = extended_euclid(n, a);
	while (ret < 0)
	{
		ret += n;
	}

	cout << ret;
	return 0;
}