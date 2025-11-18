#include <iostream>

using namespace std;

int N, Z, M;
bool dis[1001] = { false, }, visit[1001] = { false, };

void DFS(int idx, int dist)
{
    if (idx == Z)
    {
        cout << dist << '\n';
        exit(0);
    }
    visit[idx] = true;
    int next = (idx + dist) % N;
    next = next == 0 ? N : next;
    if (!visit[next] && !dis[next])
        DFS(next, dist);
    visit[idx] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Z >> M;
    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        dis[num] = true;
    }

    for (int i = 1; i < Z; ++i)
        DFS(1, i);
    return 0;
}