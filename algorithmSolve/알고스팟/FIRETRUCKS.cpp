#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<vector<pair<int, int>>> board;
vector<int> fire;
vector<int> answer;
int v, e, n, m;

void DK() // 0부터 시작
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push(make_pair(0, 0));
	answer.assign(v + 1, numeric_limits<int>::max());
	answer[0] = 0;
	while (!que.empty())
	{
		auto now = que.top();
		que.pop();
		int cost = now.first;
		int here = now.second;

		if (cost > answer[here])
			continue;

		for (int i = 0; i < board[here].size(); ++i)
		{
			auto next = board[here][i];
			int there = next.first;
			int len = next.second;

			if (cost + len < answer[there])
			{
				answer[there] = cost + len;
				que.push(make_pair(answer[there], there));
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < fire.size(); ++i)
		ans += answer[fire[i]];
	cout << ans << '\n';
}

int main() // 각 정점은 모두 연결되어있고, 각 간선의 최소치를 갱신해야할 필요도 없음. 양방향 통행이다.
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> v >> e >> n >> m;
		board.assign(v + 1, vector<pair<int, int>>());
		fire.clear();
		for (int j = 0; j < e; ++j)
		{
			int a, b, c;
			cin >> a >> b >> c;
			board[a].push_back(make_pair(b, c));
			board[b].push_back(make_pair(a, c));
		}
		for (int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;
			fire.push_back(a);
		}
		for (int j = 0; j < m; ++j)
		{
			int a;
			cin >> a;
			board[0].push_back(make_pair(a, 0));
		}
		DK();
	}
	return 0;
}