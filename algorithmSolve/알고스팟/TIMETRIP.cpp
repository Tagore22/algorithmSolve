#include <iostream>
#include <vector>

using namespace std; //각 정점의 번호는 0번부터 v-1번까지, 방향 그래프이며, 0번에서 시작해서 1번까지 도달 

vector<vector<pair<int, int>>> board;
vector<vector<bool>> CanGo;
vector<int> MaxVec;
vector<int> MinVec;
int v, w;
const int MinNum = 987654321;
const int MaxNum = -987654321;

void CanGoFunc()
{
	for (int i = 0; i < v; ++i)
		CanGo[i][i] = true;
	for (int k = 0; k < v; ++k)
		for (int i = 0; i < v; ++i)
			for (int j = 0; j < v; ++j)
				CanGo[i][j] = CanGo[i][j] || (CanGo[i][k] && CanGo[k][j]);
}

void DKMin()
{
	MinVec.assign(v, MinNum);
	MinVec[0] = 0;
	for (int iter = 0; iter < v - 1; ++iter)
		for (int here = 0; here < v; ++here)
			for (int i = 0; i < board[here].size(); ++i)
			{
				auto next = board[here][i];
				int there = next.first;
				int cost = next.second;

				MinVec[there] = min(MinVec[here] + cost, MinVec[there]);
			}

	for (int here = 0; here < v; ++here)
		for (int i = 0; i < board[here].size(); ++i)
		{
			auto next = board[here][i];
			int there = next.first;
			int cost = next.second;

			if ((MinVec[there] > MinVec[here] + cost) && (CanGo[0][here] && CanGo[here][1]))
			{
				MinVec.clear();
				return;
			}
		}
}

void DKMax()
{
	MaxVec.assign(v, MaxNum);
	MaxVec[0] = 0;
	for (int iter = 0; iter < v - 1; ++iter)
		for (int here = 0; here < v; ++here)
			for (int i = 0; i < board[here].size(); ++i)
			{
				auto next = board[here][i];
				int there = next.first;
				int cost = next.second;

				MaxVec[there] = max(MaxVec[here] + cost, MaxVec[there]);
			}

	for (int here = 0; here < v; ++here)
		for (int i = 0; i < board[here].size(); ++i)
		{
			auto next = board[here][i];
			int there = next.first;
			int cost = next.second;

			if ((MaxVec[there] < MaxVec[here] + cost) && (CanGo[0][here] && CanGo[here][1]))
			{
				MaxVec.clear();
				return;
			}
		}
}

void ShowAnswer()
{
	CanGoFunc();
	DKMin();
	if (MinVec.empty())
		cout << "INFINITY" << ' ';
	else if (!CanGo[0][1])
	{
		cout << "UNREACHABLE" << ' ';
		return;
	}
	else
		cout << MinVec[1] << ' ';
	DKMax();
	if (MaxVec.empty())
		cout << "INFINITY" << ' ';
	else
		cout << MaxVec[1] << ' ';
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
		CanGo.assign(v, vector<bool>(v, false));
		board.assign(v, vector<pair<int, int>>());
		for (int j = 0; j < w; ++j)
		{
			int a, b, c;
			cin >> a >> b >> c;
			board[a].push_back(make_pair(b, c));
			CanGo[a][b] = true;
		}
		ShowAnswer();
		cout << '\n';
	}
	return 0;
}