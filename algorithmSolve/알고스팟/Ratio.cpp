#include <iostream>

using namespace std;

long long n, m, rate;

long long canRate(long long num)
{
	return (m + num) * 100 / (n + num);
}

long long calcul()
{
	long long lo = 0;
	long long hi = 2000000000;
	if (canRate(hi) < rate + 1)
		return -1;
	for (int i = 0; i < 100; ++i)
	{
		long long mid = (lo + hi) / 2;
		if (canRate(mid) >= rate + 1)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int sadsadsadadasdmain()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> n >> m;
		rate = m * 100 / n;
		cout << calcul() << '\n';
	}
	return 0;
}