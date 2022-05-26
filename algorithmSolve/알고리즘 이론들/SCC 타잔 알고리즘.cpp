#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int SccCount = 0;
int Vcount = -1;
vector<int> Scc; //초기값은 모두 -1;
vector<int> Vnum; //초기값은 모두 -1;
vector<vector<int>> board;
stack<int> SccStack;

int Calcul(int here)
{
    Vnum[here] = ++Vcount;  //현재 정점의 방문순서;
    int ans = Vnum[here];
    SccStack.push(here); //모든 정점들은 단 한번 스택에 들어간다;
    for (int i = 0; board[here].size(); ++i)
    {
        int there = board[here][i];
        if (Vnum[there] == -1) //다음에 방문하는 정점이 처음 방문하는 정점, 즉 현 간선이 트리간선일때;
            ans = min(ans, Calcul(there));
        else if (Scc[there] == -1) //역간선, 혹은 더 높은 정점에 도달한 정점과 연결된 교차간선이라면;
            ans = min(ans, Vnum[there]);
    }
    if (ans == Vnum[here]) //현 정점 및 자식정점들이 도달할수 있는 가장 높은 정점이 현 정점이라면 여기까지가 하나의 SCC;
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