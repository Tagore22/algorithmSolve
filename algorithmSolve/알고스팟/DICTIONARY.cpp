#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> StrVec;
vector<vector<int>> board;
int n;
const int Alpha = 26;
vector<bool> check;
vector<int> answer;

void MakeGraph()
{
	for (int i = 1; i < StrVec.size(); ++i)
	{
		int j = i - 1;
		int len = min(StrVec[i].size(), StrVec[j].size());
		for (int k = 0; k < len; ++k)
			if (StrVec[i][k] != StrVec[j][k])
			{
				int a = StrVec[j][k] - 'a';
				int b = StrVec[i][k] - 'a';
				board[a][b] = 1;
				break;
			}
	}
}

void DFS(int here)
{
	check[here] = true;
	for (int there = 0; there < board[here].size(); ++there)
		if (!check[there] && board[here][there] == 1)
			DFS(there);
	answer.push_back(here);
}

void DFSAll()
{
	for (int i = 0; i < Alpha; ++i)
		if (!check[i])
			DFS(i);
}

vector<int> Topologic()
{
	reverse(answer.begin(), answer.end());
	for (int i = Alpha - 1; i > 0; --i)
		for (int j = i - 1; j > 0; --j)
			if (board[answer[i]][answer[j]] == 1)
				return vector<int>();
	return answer;
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
		cin >> n;
		StrVec.assign(n, "");
		board.assign(Alpha, vector<int>(Alpha, 0));
		check.assign(Alpha, false);
		answer.clear();
		for (int j = 0; j < n; ++j)
			cin >> StrVec[j];
		MakeGraph();
		DFSAll();
		if (Topologic().empty())
			cout << "INVALID HYPOTHESIS" << '\n';
		else
		{
			for (int i = 0; i < answer.size(); ++i)
				cout << static_cast<char>(answer[i] + 'a');
			cout << '\n';
		}
	}
	return 0;
}