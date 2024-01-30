#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �������� ���� �˰����� ���� ���� ������. �׷��� �����ӿ��� Ȯ���ߴ�.
// ó������ BFS, DFS���� �׷��� ��ȸ�� �����ߴµ� �Դ� ���� �ٽ� �湮�ϱ⿡ ���� ��̴�.
// �����δ� �ּ� ���д� Ʈ���� �̿��ؾ� �ߴ�. �׷��� ������ �湮�ߴ� �������� �ٸ� ������ �̵��Ҽ� �ֱ� �����̴�.
// ���������� 1�̰� ���������� 0�ε� �̰� �ڹٲ�� ���� Ǯ�̰� �����ߴ�. 

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[1001];
int N, M;

// �ִ� �Ƿε��� ����ϴ� �Լ�.
int Prim_Max()
{
    // ���� ���� �Ƿε��� ã�ƾ� �ϱ� ������ -1�� �ʱ�ȭ ��Ų��.
    vector<int> dist(N + 1, -1);
    dist[0] = 0;
    vector<bool> visit(N + 1, false);
    int ans = 0;

    for (int iter = 0; iter <= N; ++iter)
    {
        int u = -1;
        for (int v = 0; v <= N; ++v)
            // ���� Ʈ���� ���Ե��� ���� �������� ���� �Ƿε��� ���� ������ ã�´�.
            if (!visit[v] && (u == -1 || dist[v] > dist[u]))
                u = v;

        visit[u] = true;
        ans += dist[u];

        // ���� �湮�� �������� ���ް����� �������� ��ȸ�ϸ�
        // ���� �湮���� ���� �����鿡 ���� �Ƿε��� �����Ѵ�.
        for (auto next : board[u])
        {
            int there = next.first;
            int cost = next.second;
            if (!visit[there] && cost > dist[there])
                dist[there] = cost;
        }
    }
    return ans;
}

// �ּ� �Ƿε��� ����ϴ� �Լ�.
int Prim_Min()
{
    // ���� ���� �Ƿε��� ã�ƾ� �ϱ� ������ 1000�� �ʱ�ȭ ��Ų��.
    vector<int> dist(N + 1, 1000);
    dist[0] = 0;
    vector<bool> visit(N + 1, false);
    int ans = 0;

    for (int iter = 0; iter <= N; ++iter)
    {
        int u = -1;
        for (int v = 0; v <= N; ++v)
            // ���� Ʈ���� ���Ե��� ���� �������� ���� �Ƿε��� ���� ������ ã�´�.
            if (!visit[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        visit[u] = true;
        ans += dist[u];

        // ���� �湮�� �������� ���ް����� �������� ��ȸ�ϸ�
        // ���� �湮���� ���� �����鿡 ���� �Ƿε��� �����Ѵ�.
        for (auto next : board[u])
        {
            int there = next.first;
            int cost = next.second;
            if (!visit[there] && cost < dist[there])
                dist[there] = cost;
        }
    }
    return ans;
}

void MakeAnswer()
{
    int max_num = Prim_Max();
    int min_num = Prim_Min();
    // �Ƿε��� ������ ���� �Ƿε��� ������ ���Ѵ�. ���� �ִ� �Ƿε��Ӹ� �ƴ϶�
    // �ּ� �Ƿε� ���� �����Ͽ� ����ؾ��Ѵ�.
    cout << max_num * max_num - min_num * min_num << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, isDownhill;
    for (int i = 0; i <= M; ++i)
    {
        cin >> from >> to >> isDownhill;
        board[from].push_back(make_pair(to, abs(isDownhill - 1)));
        board[to].push_back(make_pair(from, abs(isDownhill - 1)));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}