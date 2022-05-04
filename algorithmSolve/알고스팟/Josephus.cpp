#include <iostream>
#include <list>

using namespace std;

int n, k;
list<int> L;

void calcul()
{
	list<int>::iterator iter = L.begin();
	while (L.size() > 2)
	{
		iter = L.erase(iter);
		if (iter == L.end())
			iter = L.begin();
		for (int i = 0; i < k - 1; ++i)
		{
			++iter;
			if (iter == L.end())
				iter = L.begin();
		}
	}
	cout << L.front() << ' ' << L.back() << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> n >> k;
		for (int j = 1; j <= n; ++j)
			L.push_back(j);
		calcul();
	}
	return 0;
}