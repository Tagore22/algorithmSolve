#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> makeVector(const vector<int>& vec, int a, int b)
{
	return vector<int>(vec.begin() + a, vec.begin() + b);
}

void calcul(const vector<int>& a, const vector<int>& b)
{
	if (a.size() == 0)
		return;
	int root = a[0];
	int rootIdx = distance(b.begin(), find(b.begin(), b.end(), root));
	calcul(makeVector(a, 1, rootIdx + 1), makeVector(b, 0, rootIdx));
	calcul(makeVector(a, rootIdx + 1, a.size()), makeVector(b, rootIdx + 1, b.size()));
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