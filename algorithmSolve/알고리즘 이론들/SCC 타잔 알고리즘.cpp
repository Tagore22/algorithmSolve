#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int SccCount = 0;
int Vcount = -1;
vector<int> Scc; //�ʱⰪ�� ��� -1;
vector<int> Vnum; //�ʱⰪ�� ��� -1;
vector<vector<int>> board;
stack<int> SccStack;

int Calcul(int here)
{
    Vnum[here] = ++Vcount;  //���� ������ �湮����;
    int ans = Vnum[here];
    SccStack.push(here); //��� �������� �� �ѹ� ���ÿ� ����;
    for (int i = 0; board[here].size(); ++i)
    {
        int there = board[here][i];
        if (Vnum[there] == -1) //������ �湮�ϴ� ������ ó�� �湮�ϴ� ����, �� �� ������ Ʈ�������϶�;
            ans = min(ans, Calcul(there));
        else if (Scc[there] == -1) //������, Ȥ�� �� ���� ������ ������ ������ ����� ���������̶��;
            ans = min(ans, Vnum[there]);
    }
    if (ans == Vnum[here]) //�� ���� �� �ڽ��������� �����Ҽ� �ִ� ���� ���� ������ �� �����̶�� ��������� �ϳ��� SCC;
    {
        while (true)
        {
            int x = SccStack.top();
            Scc[x] = SccCount;
            if (x == here)
                break;
        }
        ++SccCount;
    }
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}