#include <iostream>
#include <vector>

using namespace std;//������ ��ȣ�� 0������ v-1������. �������� 0�� �������� 1�� ���� �׷���

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

			if (MinVec[here] != MINNUM && MinVec[there] > MinVec[here] + cost) //���� ����Ŭ�� �����Ұ��.
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

			if (MaxVec[here] != MAXNUM && MaxVec[there] < MaxVec[here] + cost) //���� ����Ŭ�� �����Ұ��.
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