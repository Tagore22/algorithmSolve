#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Alpha = 26;
int n;
vector<string> StrVec;
vector<int> InNum;
vector<int> OutNum;
vector<vector<int>> board;
vector<vector<vector<string>>> VVS;
vector<int> answer;

void MakeGraph()
{
	OutNum.assign(Alpha, 0);
	InNum.assign(Alpha, 0);
	board.assign(Alpha, vector<int>(Alpha, 0));
	VVS.assign(Alpha, vector<vector<string>>(Alpha, vector<string>()));
	for (int i = 0; i < n; ++i)
	{
		int a = StrVec[i][0] - 'a';
		int b = StrVec[i][StrVec[i].size() - 1] - 'a';
		++board[a][b];
		++OutNum[a];
		++InNum[b];
		VVS[a][b].push_back(StrVec[i]);
	}
}

void DFS(int here)
{
	for (int there = 0; there < board[here].size(); ++there)
		while (board[here][there] > 0)
		{
			--board[here][there];
			DFS(there);
		}
	answer.push_back(here);
}

bool CheckGraph()
{
	int PlusNum = 0;
	int MinusNum = 0;
	for (int i = 0; i < Alpha; ++i)
	{
		int del = OutNum[i] - InNum[i];
		if (abs(del) > 2)
			return false;
		else if (del == 1)
			++PlusNum;
		else if (del == -1)
			++MinusNum;
	}
	if ((PlusNum == 1 && MinusNum == 1) || (PlusNum == 0 && MinusNum == 0))
		return true;
	else
		return false;
}

void Calcul()
{
	answer.clear();
	MakeGraph();
	if (!CheckGraph())
		return;

	for (int i = 0; i < Alpha; ++i)
		if (OutNum[i] == InNum[i] + 1)
		{
			DFS(i);
			reverse(answer.begin(), answer.end());
			return;
		}
	for (int i = 0; i < Alpha; ++i)
		if (OutNum[i] != 0)
		{
			DFS(i);
			reverse(answer.begin(), answer.end());
			return;
		}
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
		for (int j = 0; j < n; ++j)
			cin >> StrVec[j];
		Calcul();
		if (answer.empty() || answer.size() != n + 1)
			cout << "IMPOSSIBLE" << '\n';
		else
		{
			for (int i = 1; i < answer.size(); ++i)
			{
				int a = answer[i - 1];
				int b = answer[i];
				cout << VVS[a][b].back() << ' ';
				VVS[a][b].pop_back();
			}
			cout << '\n';
		}
	}
	return 0;
}