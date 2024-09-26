#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 풀이.
// 이런 문제가 나올때마다 늘 생각하는거지만 어떻게 풀으라고 하는건지 모르겠다.
// 확장 유클리드 호제법 이런걸 수학과 나온 사람 아니면 얼마나 안다고 이런걸 내지.
// 어이가 없다. 아직도 모르겠다. 알려고 하지도 않았지만. 나중에 코딩테스트에서 이런 류의 문제가
// 나오지 않았으면 하는 바램뿐이다.

// 그래도 나중에 한번 훑어는 보자.

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