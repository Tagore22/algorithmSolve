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
	EdgeNum[here] = ++CountNum;             //���� ������ ������ ����
	int ans = EdgeNum[here];                //������ ���ϰ� �� ������ ������. �� ������ ���� �������̴�.
	int child = 0;                          //���� ������ ��Ʈ�̸鼭 �ڽķ�Ʈ�� 1�� ���϶�� �������� �ƴϴ�.
	for (int i = 0; i < board[here].size(); ++i)
	{
		int there = board[here][i];
		if (EdgeNum[there] == -1)           //���� ������ ���� �湮���� ���� �����̶�� here���� there�� Ʈ������.
		{
			++child;                        
			int MinEgde = FindCutter(there, false); //there���� �����Ҽ� �ִ� ���� ��Ʈ�� ����� ����.

			if (!IsRoot && EdgeNum[here] < MinEgde) //there���� �� �������� �� ��Ʈ�� ������ �������� ���Ѵٸ� �� ������ ������.
				IsCutter[here] = true;              //��Ʈ�� �ڽ� ������ ��ȸ�� �ʿ䵵 ���� �ڽ� ������ ���� ���� ������.   
			ans = min(ans, MinEgde);                //ans�� �� �������� �����Ҽ� �ִ� ���� ��Ʈ�� ����� ����. 
		}
		else
			ans = min(ans, EdgeNum[there]);         //there�� �̹� ������ �����̶�� �� ������ ������,Ȥ�� �������̸�(�� �׷����� ���� �׷����̴�.)
	}                                               //���������� �����Ҽ� �ִ� ���� ��Ʈ�� ����� ������ ã�´�.  
	if (IsRoot)                                     //��Ʈ�϶����� �ڽ� ������ ���� ���� �����ȴ�.
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