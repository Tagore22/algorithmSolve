#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> Capa, Flow;
const int n = 6;

int FF(int source, int sink)//시작은 0번, 끝은 5번;
{
    int answer = 0;
    Flow.assign(n, vector<int>(n, 0));
    while (true)
    {
        vector<int> Parent(n, -1);
        Parent[source] = source;
        queue<int> que;
        que.push(source);
        while (!que.empty() && Parent[sink] == -1)
        {
            int here = que.front();
            que.pop();

            for (int there = 0; there < n; ++there)
                if (Parent[there] == -1 && Capa[here][there] - Flow[here][there] > 0)
                {
                    Parent[there] = here;
                    que.push(there);
                }
        }
        if (Parent[sink] == -1)
            break;
        int Amount = 987654321;
        for (int p = sink; p != source; p = Parent[p])
            Amount = min(Amount, Capa[Parent[p]][p] - Flow[Parent[p]][p]);
        for (int p = sink; p != source; p = Parent[p])
        {
            Flow[Parent[p]][p] += Amount;
            Flow[p][Parent[p]] -= Amount;
        }
        answer += Amount;
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Capa.assign(n, vector<int>(n, 0));
    Capa[0][1] = 10;
    Capa[0][3] = 5;
    Capa[1][2] = 9;
    Capa[1][4] = 7;
    Capa[3][4] = 5;
    Capa[2][5] = 9;
    Capa[4][5] = 7;
    cout << FF(0, 5) << '\n';
    return 0;
}