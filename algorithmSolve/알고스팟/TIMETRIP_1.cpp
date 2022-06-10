#include <iostream>
#include <vector>

using namespace std;//정점의 번호는 0번부터 v-1번까지. 시작점은 0번 도착점은 1번 방향 그래프

vector<vector<pair<int, int>>> board;
vector<int> MaxVec;
vector<int> MinVec;
int v, w;
const int MAXNUM = -987654321;
const int MINNUM = 987654321;

void BFMin()
{
	MinVec.assign(v, MINNUM);
	MinVec[0] = 0;
	for (int iter = 0; iter < v - 1; ++iter)
		for (int here = 0; here < v; ++here)
			for (int i = 0; i < board[here].size(); ++i)
			{
				int there = board[here][i].first;
				int cost = board[here][i].second;

				if (MinVec[here] != MINNUM)
					MinVec[there] = min(MinVec[there], MinVec[here] + cost);
			}
	for (int here = 0; here < v; ++here)
		for (int i = 0; i < board[here].size(); ++i)
		{
			int there = board[here][i].first;
			int cost = board[here][i].second;

			if (MinVec[here] != MINNUM && MinVec[there] > MinVec[here] + cost) //음수 사이클이 존재할경우.
			{
				MinVec.clear();
				return;
			}
		}
}

void BFMax()
{
	MaxVec.assign(v, MAXNUM);
	MaxVec[0] = 0;
	for (int iter = 0; iter < v - 1; ++iter)
		for (int here = 0; here < v; ++here)
			for (int i = 0; i < board[here].size(); ++i)
			{
				int there = board[here][i].first;
				int cost = board[here][i].second;

				if (MaxVec[here] != MAXNUM)
					MaxVec[there] = max(MaxVec[there], MaxVec[here] + cost);
			}
	for (int here = 0; here < v; ++here)
		for (int i = 0; i < board[here].size(); ++i)
		{
			int there = board[here][i].first;
			int cost = board[here][i].second;

			if (MaxVec[here] != MAXNUM && MaxVec[there] < MaxVec[here] + cost) //음수 사이클이 존재할경우.
			{
				MaxVec.clear();
				return;
			}
		}
}

void ShowAnswer()
{
	BFMin();
	if (MinVec[1] == MINNUM)
	{
		cout << "UNREACHABLE" << '\n';
		return;
	}
	else if (MinVec.empty())
		cout << "INFINITY" << ' ';
	else
		cout << MinVec[1] << ' ';
	BFMax();
	if (MaxVec.empty())
		cout << "INFINITY" << '\n';
	else
		cout << MaxVec[1] << '\n';
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
		cin >> v >> w;
		board.assign(v, vector<pair<int, int>>());
		for (int j = 0; j < w; ++j)
		{
			int a, b, c;
			cin >> a >> b >> c;
			board[a].push_back(make_pair(b, c));
		}
		ShowAnswer();
	}
	return 0;
}