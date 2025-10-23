#include <iostream>
#include <queue>
#include <vector>

// Ǯ��.
// ����� ��������. ������ڸ� ���� ���� �ִܰŸ��� �̿��ؾ��ϱ⿡ ó������ �÷��̵� ����
// �˰����� ���÷�����, ������ �ִ� ������ ��������. �÷��̵� ������ ���� ������
// 3�� for���� �̿��ϱ� ������ �ð����� ���� ������� ���Ұ� ���ߴ�. �׷��� ��Ƽ ���ͽ�Ʈ��
// ����ؾ��ߴ�. ������ ���ͽ�Ʈ����� �������� dist �迭�ε� ������ �Ѱ��� ���������κ���
// �� ������ �ִܰŸ��� �����Ѵٸ�, ��Ƽ ���ͽ�Ʈ�󿡼��� � ������������ �� �� ������
// ��·�� � ���������κ����� �ִܰŸ��� �����ϴ� �������� �ִ�. �̰͸� �˸� �����
// Ǯ �� �ִ� ��������.

// �ڼ��� ������ �ּ����� �����.

using namespace std;

int V, E, M, S, x, y;
// �� �����鰣�� ������ ���ͷ� ����.
vector<pair<int, int>> dist[10001];
vector<int> mac, star, macdist, stardist;

// ��Ƽ ���ͽ�Ʈ�� ���� �Լ�.
void Dijkstra(const vector<int>& srt, bool ismac)
{
    priority_queue<pair<int, int>> que;
    // �� ������ 1������ V������ �����ϱ⿡ ���͸� V + 1���� �����ؾ��Ѵ�.
    vector<int> mindist(V + 1, 100000001);
    // ���۰����� ť�� �ִ´�.
    for (const auto& n : srt)
    {
        que.push(make_pair(0, n));
        mindist[n] = 0;
    }

    // ����Ͽ��� dist �迭�� �������� �ٸ� ������ �����ٴ� ���� �����ϰ��
    // �Ϲ����� ���ͽ�Ʈ��� �ٸ� �� ����.
    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > mindist[here])
            continue;

        for (int i = 0; i < dist[here].size(); ++i)
        {
            int there = dist[here][i].first;
            int len = dist[here][i].second;
            if (len + cost < mindist[there])
            {
                mindist[there] = len + cost;
                que.push(make_pair(-mindist[there], there));
            }
        }
    }
    // ��Ÿ������� �Ƶ�������� ���� �������� �ʱ� ����
    // 2���� �Ű������� �̿��Ͽ��� dist �迭�� ���������� �����߱⿡
    // ���� ������ �ؾ��Ѵ�.
    if (ismac)
        macdist = mindist;
    else
        stardist = mindist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 0; i < E; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from].push_back(make_pair(to, cost));
        dist[to].push_back(make_pair(from, cost));
    }
    cin >> M >> x;
    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        mac.push_back(num);
    }
    cin >> S >> y;
    for (int i = 0; i < S; ++i)
    {
        int num;
        cin >> num;
        star.push_back(num);
    }
    Dijkstra(mac, true);
    Dijkstra(star, false);
    int answer = 200000001;
    for (int i = 1; i <= V; ++i)
    {
        // �� dist[i]�� 0�̶�� i���� i�� �̵��� ����ε� �̴� ���õǾ�� �ϴ� ��Ȳ�̱⿡
        // ���� if������ �ɷ����ߴ�.
        if (macdist[i] == 0 || stardist[i] == 0 || macdist[i] > x || stardist[i] > y)
            continue;
        answer = min(answer, macdist[i] + stardist[i]);
    }
    cout << (answer != 200000001 ? answer : -1) << '\n';
    return 0;
}