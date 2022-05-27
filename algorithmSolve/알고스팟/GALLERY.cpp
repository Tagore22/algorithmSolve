#include <iostream>
#include <vector>

using namespace std;

const int INSTALLED = 0;
const int WATCHED = 1;
const int UNWATCHED = 2;
vector<bool> check;
vector<vector<int>> board;
int InstallNum;
int g;

int DFS(int here)
{
	int stat[3] = { 0,0,0 };
	check[here] = true;
	for (int i = 0; i < board[here].size(); ++i)
	{
		int there = board[here][i];
		if (!check[there])
			++stat[DFS(there)];
	}
	if (stat[UNWATCHED])
	{
		++InstallNum;
		return INSTALLED;
	}
	else if (stat[INSTALLED])
		return WATCHED;
	else
		return UNWATCHED;
}

void DFSAll()
{
	check.assign(g, false);
	InstallNum = 0;
	for (int i = 0; i < g; ++i)
		if (!check[i] && (DFS(i) == UNWATCHED))
			++InstallNum;
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
		int h;
		cin >> g >> h;
		board.assign(g, vector<int>());
		for (int j = 0; j < h; ++j)
		{
			int a, b;
			cin >> a >> b;
			board[a].push_back(b);
			board[b].push_back(a);
		}
		DFSAll();
		cout << InstallNum << '\n';
	}
	return 0;
}