#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> potion1;
vector<int> potion2;
int gcd(int p, int q) //알고스팟에 numeric 헤더의 gcd함수를 호출하지 못하여 직접 구현해야했다. 의도적인건가
{
	if (q == 0)
		return p;
	return gcd(q, p % q);
}
void calcul()
{
	int gcdNum = potion1[0];
	for (int i = 0; i < potion1.size(); ++i)
		gcdNum = gcd(gcdNum, potion1[i]);
	vector<int> list;
	for (int i = 0; i < potion1.size(); ++i)
		list.push_back(potion1[i] / gcdNum);
	int maxNum = -1;
	for (int i = 0; i < potion1.size(); ++i)
		maxNum = max(maxNum, static_cast<int>(ceil(static_cast<double>(potion2[i]) / list[i])));
	for (int i = 0; i < potion1.size(); ++i)
		list[i] *= maxNum;
	for (int i = 0; i < potion1.size(); ++i)
		cout << list[i] - potion2[i] << " ";
	cout << '\n';
}
int fadsfsdafsdmain()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		int n;
		cin >> n;
		potion1.assign(n, 0);
		potion2.assign(n, 0);
		for (int j = 0; j < n; ++j)
			cin >> potion1[j];
		for (int j = 0; j < n; ++j)
			cin >> potion2[j];
		calcul();
	}
	return 0;
}