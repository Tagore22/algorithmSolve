#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ó���� ���� �˰������� �˾Ҵµ� �˰� ���� �ּ� ���д� Ʈ���� �̿���
// �ִ� ���д� Ʈ������. ������ ����Ͽ��µ� �켱���� ť�� ����Ͽ��� �߰�
// ���� ū ������ �������� �������� ���ϴ� ��쿡 � ������ ����� �϶����
// ����� ��� ������ �����ϴ� �� �˾Ҵ��� �װ� �ƴ϶� �׷� ��� 0�� ����ؾ��ߴ�.
// ���� ���ظ� ���� ���� ������ ���� �������Ѱ��� �𸣰ڴ�. Ŭ�ε带 ���ؼ�
// ���� ���θ� �ߴµ� ũ�罺Į�� �� ������ �����ϴٰ� �ϴ� �����δ� �׳� ũ�罺Į��
// ��߰ڴ�.

// �ڼ��� ������ �ּ����� �����.

int N, M, s, e;
vector<pair<int, int>> board[100001];

// ���� �˰��� �Լ�.
void prim()
{
    vector<bool> isadd(N + 1, false);
    vector<int> maxw(N + 1, 0), parent(N + 1, -1);
    maxw[s] = 1e9;
    parent[s] = s;
    priority_queue<pair<int, int>> que;
    que.push({ maxw[s], s });

    while (!que.empty())
    {
        int w = que.top().first;
        int u = que.top().second;
        que.pop();

        // �̹� Ʈ���� ���Ե� �����̰ų� ����ġ�� �� �ִ밪���� �۴ٸ� �����Ѵ�.
        if (isadd[u] || w < maxw[u])
            continue;
        isadd[u] = true;
        // ������ �� �ִ� ��� �������� ��ȸ�ϸ� ����ġ ���� ����� �Ѵ�.
        for (int i = 0; i < board[u].size(); ++i)
        {
            int there = board[u][i].first;
            int weight = board[u][i].second;
            if (!isadd[there] && maxw[there] < weight)
            {
                parent[there] = u;
                maxw[there] = weight;
                que.push({ weight, there });
            }
        }
    }
    int answer = 1000001;
    while (e != s)
    {
        // ����Ѵ�� �� �κ��� �߿��ߴ�. ���� �������� ���Ѵٸ�
        // �����θ� �غ��� ������ ���⿡ 0�� ����Ѵ�.
        if (parent[e] == -1)
        {
            cout << 0 << '\n';
            return;
        }
        answer = min(answer, maxw[e]);
        e = parent[e];
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> s >> e;
    for (int i = 0; i < M; ++i)
    {
        int from, to, k;
        cin >> from >> to >> k;
        board[from].push_back(make_pair(to, k));
        board[to].push_back(make_pair(from, k));
    }
    prim();
    return 0;
}