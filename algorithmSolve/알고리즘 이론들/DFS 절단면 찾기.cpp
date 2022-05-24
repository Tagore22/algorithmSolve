#include <iostream>
#include <vector>

using namespace std;

const int MaxNum = 0415;
vector<bool> IsCutter(MaxNum,false);
vector<int> EdgeNum(MaxNum,-1);
vector<vector<int>> board;
int CountNum = 0;

void FindCutter(int here, bool IsRoot)
{
	EdgeNum[here] = ++CountNum;             //현재 정점에 도달한 순서
	int ans = EdgeNum[here];                //앞으로 비교하게 될 순서의 최종값. 그 시작은 현재 순서값이다.
	int child = 0;                          //현재 정점이 루트이면서 자식루트가 1개 이하라면 절단점이 아니다.
	for (int i = 0; i < board[here].size(); ++i)
	{
		int there = board[here][i];
		if (EdgeNum[there] == -1)           //다음 정점이 아직 방문하지 않은 정점이라면 here부터 there은 트리간선.
		{
			++child;                        
			int MinEgde = FindCutter(there, false); //there에서 도달할수 있는 가장 루트에 가까운 순서.

			if (!IsRoot && EdgeNum[here] < MinEgde) //there에서 현 정점보다 더 루트에 가깝게 도달하지 못한다면 현 정점은 절단점.
				IsCutter[here] = true;              //루트는 자식 정점을 순회할 필요도 없이 자식 정점의 수에 의해 결정됨.   
			ans = min(ans, MinEgde);                //ans는 현 정점에서 도달할수 있는 가장 루트에 가까운 순서. 
		}
		else
			ans = min(ans, EdgeNum[there]);         //there가 이미 도달한 정점이라면 그 간선은 역간선,혹은 순간선이며(현 그래프는 무향 그래프이다.)
	}                                               //마찬가지로 도달할수 있는 가장 루트에 가까운 순서를 찾는다.  
	if (IsRoot)                                     //루트일때에는 자식 정점의 수에 의해 결정된다.
		IsCutter[here] = child > 1;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return 0;
}