#include <iostream>
#include <map>

using namespace std;

map<int, int> board;

int calcul(int a, int b)
{
	map<int, int>::iterator iter = board.lower_bound(a);
	if (iter != board.end() && iter->second > b)
		return board.size();

	iter = board.lower_bound(a);
	if (iter != board.begin())
	{
		--iter;
		while (true)
		{
			if (iter->second > b)
				break;
			if (iter == board.begin())
			{
				board.erase(iter);
				break;
			}
			else
			{
				board.erase(iter--);
			}
		}
	}
	board.insert(make_pair(a, b));
	return board.size();
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
		int n, answer;
		cin >> n;
		answer = 0;
		board.clear();
		for (int j = 0; j < n; ++j)
		{
			int a, b;
			cin >> a >> b;
			answer += calcul(a, b);
		}
		cout << answer << '\n';
	}
	return 0;
}
