#include <iostream>
#include <vector>

using namespace std;

const int MaxNum = 1000;
vector<int> EdgeNum(MaxNum, -1);
vector<bool> IsFinish(MaxNum, false);
vector<vector<int>> board;
int CountNum = 0;

void EdgeCheck(int here)
{
	EdgeNum.push_back(++CountNum);
	for (int i = 0; i < board[here].size(); ++i)
	{
		int there = board[here][i];
		if (EdgeNum[there] == -1)
		{
			cout << "Edge[" << here << "][" << there << "] : 트리간선" << '\n';
			EdgeCheck(there);
		}
		else if (EdgeNum[here] < EdgeNum[there])
			cout << "Edge[" << here << "][" << there << "] : 순방향간선" << '\n';
		else if (IsFinish[there])
			cout << "Edge[" << here << "][" << there << "] : 교차간선" << '\n';
		else
			cout << "Edge[" << here << "][" << there << "] : 역방향간선" << '\n';
	}
	IsFinish[here] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return 0;
}