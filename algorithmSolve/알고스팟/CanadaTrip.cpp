#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int>> board;

bool calcul(int dis)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (dis >= board[i][0] - board[i][1])
			ans += (min(dis - (board[i][0] - board[i][1]), board[i][1]) / board[i][2]) + 1;
	return ans >= k;
}

int asdfsadfsadfsdafmain()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n >> k;
		board.assign(n, vector<int>(3, 0));
		for (int j = 0; j < n; ++j)
			for (int z = 0; z < 3; ++z)
				cin >> board[j][z];
		int lo = 0;
		int hi = 8030000;
		for (int j = 0; j < 100; ++j)
		{
			int mid = (lo + hi) / 2;
			if (calcul(mid))
				hi = mid;
			else
				lo = mid;
		}
		cout << hi << '\n';
	}
	return 0;
}