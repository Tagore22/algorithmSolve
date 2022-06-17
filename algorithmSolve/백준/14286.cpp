#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; //양방향 그래프, 정점의 번호는 1번부터 n번까지

vector<vector<int>> Capa, Flow;
int n, m;

void FF(int source, int sink)
{
    Flow.assign(n, vector<int>(n, 0));
    int answer = 0;
    while (true)
    {
        queue<int> Que;
        Que.push(source);
        vector<int> Parent(n, -1);
        Parent[source] = source;
        while (!Que.empty() && Parent[sink] == -1)
        {
            int here = Que.front();
            Que.pop();

            for (int there = 0; there < n; ++there)
                if (Parent[there] == -1 && Capa[here][there] - Flow[here][there] > 0)
                {
                    Parent[there] = here;
                    Que.push(there);
                }
        }
        if (Parent[sink] == -1)
            break;
        int amount = 987654321;
        for (int p = sink; p != source; p = Parent[p])
            amount = min(amount, Capa[Parent[p]][p] - Flow[Parent[p]][p]);
        for (int p = sink; p != source; p = Parent[p])
        {
            Flow[Parent[p]][p] += amount;
            Flow[p][Parent[p]] -= amount;
        }
        answer += amount;
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    Capa.assign(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Capa[a - 1][b - 1] = c;
        Capa[b - 1][a - 1] = c;
    }
    int source, sink;
    cin >> source >> sink;
    FF(source - 1, sink - 1);
    return 0;
}