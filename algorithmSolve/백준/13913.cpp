#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MaxNum = 100000;
int ways[MaxNum + 1];
int parent[MaxNum + 1];
int n, k;

void BFS(int now)
{
    memset(parent, -1, sizeof(parent));
    ways[now] = 0;
    queue<int> que;
    que.push(now);
    parent[now] = -10;
    while (!que.empty())
    {
        int here = que.front();
        que.pop();
        if (here == k)
            return;
        int there = here + 1;
        if (parent[there] == -1)
        {
            parent[there] = here;
            ways[there] = ways[here] + 1;
            que.push(there);
        }
        there = here - 1;
        if (parent[there] == -1 && there >= 0)
        {
            parent[there] = here;
            ways[there] = ways[here] + 1;
            que.push(there);
        }
        there = here * 2;
        if (parent[there] == -1)
        {
            parent[there] = here;
            ways[there] = ways[here] + 1;
            que.push(there);
        }
    }
}

void ShowAnswer(int num)
{
    cout << ways[num] << '\n';
    vector<int> answer;
    while (parent[num] != -10)
    {
        answer.push_back(num);
        num = parent[num];
    }
    answer.push_back(num);
    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    BFS(n);
    ShowAnswer(k);
    return 0;
}