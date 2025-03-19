#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// K������ �ּ� ���д� Ʈ���� ����Ѵ�. �̶� �ּ� ���д� Ʈ���� ���Ҽ� �ִٸ� �� ���� ����ϰ�
// ���� ª�� ����ġ�� ���Ŀ� ������� ���ϰ� �ִ밪���� �����Ѵ�. ���Ҽ� ���ٸ� 0�� ����Ѵ�.
// �Ʒ� Ǯ�̴� ���� �˰������� �����Ͽ�����, ������ ���̰� ���⿡ ũ�罺Į �˰����� �� �������ϴ�.

// �ڼ��� ������ �ּ����� �����.

struct ver
{
    int from;
    int to;
    int cost;
};

vector<pair<int, int>> V[1001];
int N, M, K;
const int MAXNUM = 987654321;

void Prim()
{
    bool visit[1001] = { false, };
    // from���� �����Ͽ� to���� ����Ǵ� cost������ ����ġ.
    vector<ver> dist(N + 1, ver{ -1, -1, MAXNUM });
    dist[1].cost = 0;
    // ���� MST���� ���� ª�� ����.
    ver edge = ver{ -1, -1, MAXNUM };
    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        // ���۰��� -1�� �ʱ�ȭ
        int u = -1;
        for (int j = 1; j <= N; ++j)
        {
            if (!visit[j] && (u == -1 || dist[j].cost < dist[u].cost))
                u = j;
        }

        // �����Ҽ� �ִ� ������ ���ٸ� 0�� ����Ѵ�.
        if (dist[u].cost == MAXNUM)
        {
            cout << 0 << ' ';
            return;
        }
        visit[u] = true;
        ans += dist[u].cost;
        if (u != 1 && dist[u].cost < edge.cost)
            edge = dist[u];

        for (auto& next : V[u])
        {
            int there = next.first;
            int len = next.second;
            if (dist[there].cost > len)
                dist[there] = ver{ u, there, len };
        }
    }
    cout << ans << ' ';
    // ���� ª�� ������ ���� �����Ͽ� ���� ������� �ʴ´�.
    for (auto& p : V[edge.from])
        if (p.first == edge.to)
            p.second = MAXNUM;
    for (auto& p : V[edge.to])
        if (p.first == edge.from)
            p.second = MAXNUM;
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
        Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= M; ++i)
    {
        int from, to;
        cin >> from >> to;
        V[from].push_back(make_pair(to, i));
        V[to].push_back(make_pair(from, i));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}