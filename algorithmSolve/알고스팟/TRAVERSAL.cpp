#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> makeVector(const vector<int>& vec, int a, int b)
{
	vector<int> mV;
	if (a > b)
		return mV;
	for (int i = a; i <= b; ++i)
		mV.push_back(vec[i]);
	return mV;
}

void calcul(const vector<int>& a, const vector<int>& b)
{
	if (a.size() == 0)
		return;
	if (a.size() == 1)
	{
		cout << b[0] << ' ';
		return;
	}
	int root = a[0];
	int rootIdx = distance(b.begin(), find(b.begin(), b.end(), root));
	calcul(makeVector(a, 1, rootIdx), makeVector(b, 0, rootIdx - 1));
	calcul(makeVector(a, rootIdx + 1, a.size() - 1), makeVector(b, rootIdx + 1, b.size() - 1));
	cout << root << ' ';
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
		int n;
		cin >> n;
		vector<int> first(n, 0);
		vector<int> second(n, 0);
		for (int j = 0; j < n; ++j)
			cin >> first[j];
		for (int j = 0; j < n; ++j)
			cin >> second[j];
		calcul(first, second);
		cout << '\n';
	}
	return 0;
}