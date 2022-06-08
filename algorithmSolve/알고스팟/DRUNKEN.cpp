#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> answer;
vector<pair<int, int>> d;
vector<int> way;
int v, e;
const int MAXNUM = 987654321;

void Floyd()
{
	for (int i = 0; i < v; ++i)
		d.push_back(make_pair(way[i], i));
	sort(d.begin(), d.end());

	answer.assign(v, vector<int>(v, 0));
	for (int i = 0; i < v; ++i)
		for (int j = 0; j < v; ++j)
		{
			if (i != j)
				answer[i][j] = board[i][j];
			else
				answer[i][j] = 0;
		}

	for (int k = 0; k < v; ++k)
	{
		int delay = d[k].second;
		for (int i = 0; i < v; ++i)
			for (int j = 0; j < v; ++j)
			{
				board[i][j] = min(board[i][j], board[i][delay] + board[delay][j]);
				answer[i][j] = min(answer[i][j], board[i][delay] + way[delay] + board[delay][j]);
			}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	way.assign(v, 0);
	for (int i = 0; i < v; ++i)
		cin >> way[i];
	board.assign(v, vector<int>(v, MAXNUM));
	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		board[a - 1][b - 1] = c;
		board[b - 1][a - 1] = c;
	}
	Floyd();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int from, to;
		cin >> from >> to;
		cout << answer[from - 1][to - 1] << '\n';
	}
	return 0;
}