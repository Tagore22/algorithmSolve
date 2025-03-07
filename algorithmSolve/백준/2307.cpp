#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ������ �ϳ��� ���ִ� �Ϳ��� �Ǽ��� �ߴ�. ó������ ������ ���ֱ� ���ؼ� ����ó�� vector �迭�� �ƴ�
// int ���� �迭�� ���� �� ���� ������ �������� �����Ͽ� �ϳ��� INF�� �ٲ㰬��. �翬�� �ð��ʰ��� ����.
// �� ���� ��� ������ �ǵ帮�� �ʾ��� ����� �ִܰ�θ� ���� �����Ͽ� �� ��θ� �ǵ帮�� �Ͱ�
// ���ͽ�Ʈ�� �Լ��� ������ �����ؼ� int ���� �迭�� �ƴ� �ٽ� vector �迭�� ����ϴ� ���� �̿���
// ���� �����ߴ�.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[1001];
int parent[1001]; // �ִ� ��θ� �����Ѵ�.
const int INF = 987654321;
int N, M, minans, maxans = -INF;

int DK(int from, int to)
{
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));
    vector<int> dist(N + 1, INF);
    dist[1] = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost < dist[here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int next = p.second;
            // ����� Ư�� ������ ����� ���. �������� ���� int ���� �迭���� ����ġ�� �����Ͽ�
            // ���� �����Ͽ����� �� ����� �ξ� �� ������ �����ߴ�.
            if ((from == here && to == there) || (from == there && to == here))
                continue;
            int nextdist = cost + next;
            if (dist[there] > nextdist)
            {
                dist[there] = nextdist;
                que.push(make_pair(-nextdist, there));
                // Ư�� ������ ������ �ʴ� ��쿡�� ��θ� ���Ѵ�.
                if (from == 0 && to == 0)
                    parent[there] = here;
            }
        }
    }
    return dist[N];
}

void MakeAnswer()
{
    parent[1] = 0;
    minans = DK(0, 0);
    int to = N;
    // N���� �����Ͽ� 1���� ��� �ִ� ��θ� ��ȸ�ϸ� ������ �ϳ��� �����.
    while (parent[to] != 0)
    {
        int from = parent[to];
        maxans = max(maxans, DK(from, to));
        if (maxans == INF)
        {
            cout << -1 << '\n';
            return;
        }
        to = from;
    }
    cout << maxans - minans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, time;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> time;
        board[from].push_back(make_pair(to, time));
        board[to].push_back(make_pair(from, time));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}