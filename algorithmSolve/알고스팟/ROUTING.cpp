#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<vector<pair<int, double>>> board;
int n, m;

void DK()
{
	vector<double> noise(n, numeric_limits<double>::max());
	noise[0] = 1;
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
	que.push(make_pair(1, 0));
	while (!que.empty())
	{
		auto now = que.top();
		que.pop();
		double cost = now.first;
		int here = now.second;

		if (cost > noise[here])
			continue;

		for (int i = 0; i < board[here].size(); ++i)
		{
			auto next = board[here][i];
			int there = next.first;
			double NextCost = next.second;

			if (cost * NextCost < noise[there])
			{
				noise[there] = cost * NextCost;
				que.push(make_pair(noise[there], there));
			}
		}
	}
	cout << noise[n - 1] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(10);

	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> n >> m;
		board.assign(n, vector<pair<int, double>>());
		for (int j = 0; j < m; ++j)
		{
			int a, b;
			double c;
			cin >> a >> b >> c;
			board[a].push_back(make_pair(b, c)); //어차피 가장 최소의 가중치를 따라 움직이기때문에 따로 갱신할필요가 없다.
			board[b].push_back(make_pair(a, c));
		}
		DK();
	}
	return 0;
}