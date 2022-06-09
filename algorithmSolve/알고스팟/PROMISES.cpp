#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; //정점의 번호는 0번부터 v-1번까지이며 양방향 그래프

vector<vector<int>> board;
int v, m, n;
int answer;
const int MAXNUM = 987654321;

void Floyd()
{
	for (int i = 0; i < v; ++i)
		board[i][i] = 0;

	for (int k = 0; k < v; ++k)
		for (int i = 0; i < v; ++i)
			for (int j = 0; j < v; ++j)
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void Update(int from, int to, int w)
{
	if (board[from][to] <= w)
	{
		++answer;
		return;
	}

	for (int i = 0; i < v; ++i)
		for (int j = 0; j < v; ++j)
			board[i][j] = min({ board[i][j], board[i][from] + w + board[to][j], board[i][to] + w + board[from][j] });
}

void ShowAnswer()
{
	Floyd();
	answer = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Update(a, b, c);
	}
	cout << answer << '\n';
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
		cin >> v >> m >> n;
		board.assign(v, vector<int>(v, MAXNUM));
		for (int j = 0; j < m; ++j)
		{
			int a, b, c;
			cin >> a >> b >> c;
			board[a][b] = min(board[a][b], c);
			board[b][a] = min(board[b][a], c);
		}
		ShowAnswer();
	}
	return 0;
}