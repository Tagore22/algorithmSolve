#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// ����� ��������. �������� ����� ���ذ� ���� �ʾҴµ� ������ ����
// i, M + i, 2M + 1 ~ ��� �����ִ�. �� �κ��� ó������ ù��° ��ȣ�� 0��
// ������ 1�� �Ŀ� ������ M���� ���� �Ŀ� �ι�° ��ȣ�� ������ ����� �� �˾�����
// �׳� 0�п� ������ 1���Ŀ� ������ ��ٷ� ���� ��ȣ�� ������ �ٽ� 1���Ŀ� ������
// ����̾���. �� �״�� 0�� ��ȣ�� 0, M + 0, 2M + 0�� ����̴�. 
// �� �Ŀ��� 1������ �����Ҷ� N���� �ִ� �Ÿ��� ���ؾ��ߴµ� ������ ���ó�� �ܼ��� �Ÿ���
// ��ġ�� �ʿ��Ѱ� �ƴ϶� �ֱ�� ���� ��ȣ���� �˾ƾ��ߴ�. �̹��� �ǳʷ��� ��ȣ��
// ������ �ǳԴ� ��ȣ���� �۴ٸ� �ֱⰡ �����Ͽ� �׸�ŭ �ð��� �����ϱ� �����̴�.
// ���� ����ü�� ����Ͽ� ����� 4���� ������ �����Ͽ���, �켱���� ť�� �̿��Ͽ����߱⿡
// ������ �����ε����� �����ߴ�.
// ����, N�� M�� �ִ밪�� ���� 10��, 70���̱⿡ �ִ밪�� 99999 * 70�� + 699999���� int����
// ����⿡ long long�� �̿��ߴ�.

// �ڼ��� ������ �ּ����� �����.

// �� �ð�, �� ��ġ, ���° �ֱ��ΰ�, ������ �ǳ� ���� ��ȣ
struct pos
{
    // time�� �ִ밪�� int���� ����� num�� �Ŀ� time�� �̿��ϴ� ������ ���Ǳ⿡
    // long long���� �����Ͽ���.
    long long time;
    int here;
    long long num;
    int prev;

    bool operator<(const pos& lhs) const
    {
        return time < lhs.time;
    }
};

int N, M;
vector<pair<int, int>> board[100001];

void DK()
{
    vector<long long> dist(N + 1, 9223372036854775806);
    dist[1] = 0;
    priority_queue<pos> que;
    que.push(pos{ 0, 1, 0, -1 });

    while (!que.empty())
    {
        long long time = -que.top().time;
        int here = que.top().here;
        int num = que.top().num;
        int prev = que.top().prev;
        que.pop();

        if (time > dist[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int next = board[here][i].second;
            // ����Ѵ�� ���� ��ȣ�� ���� ��ȣ���� �۴ٸ� �ֱ⸦ �������Ѿ� �Ѵ�.
            long long newnum = prev > next ? num + 1 : num;
            // �ֱ� * M + ���� ��ȣ���� ��ȭ���� �ȴ�.
            long long cost = newnum * M + next;
            if (cost < dist[there])
            {
                dist[there] = cost;
                que.push(pos{ -dist[there], there, newnum, next });
            }
        }
    }
    // �������� �ǳʴ� �ð� 1���� �߰����־�� �Ѵ�.
    cout << dist[N] + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        board[from].push_back(make_pair(to, i));
        board[to].push_back(make_pair(from, i));
    }
    DK();
    return 0;
}