#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// Ǯ��.
// ó������ DFS�� ���ؼ� ������ ��� ��θ� ��ȸ�ϸ� ����ġ�� ��� ������������ ������ ���Ŀ�
// N��° ������ �ּҰ��� ����ϴ� ������ ������ �Ͽ���. ������ ū �Ǽ����µ� DFS�� �ð����⵵��
// E + V�� �־����� E�� 1��, V�� 1000�̱� ������ �ʹ� �����Ѱ� �ƴѰ� �ϴ� �ǹ��� �����.
// �����δ� �⺻ DFS�� BFS�� �ܼ� ��ȸ�뵵�̱� ������ �Ȱ��� ������ �湮�� ���� ����.
// ������ �̹� ��쿡�� ��� ����� ���� Ž���ؾ� �ϱ⿡ ��� ��ο��� �湮�� ������
// �ٸ� ��ο��� �ٽ� �湮�� ��찡 �����. ���� DFS�� �ð����⵵�� E + V�� �� ��쿡
// ���� �������� �ʰ� ������� ���귮���� ���� �ð��ʰ��� ����. ��¥ Ǯ�̴� �̺� Ž�� +
// 0-1 BFS�� ���� ���ε� �̺� Ž������ BFS ��ȸ�� Ƚ���� �ּ������� �ϰ�, BFS�� �̺� Ž������
// ���� �߰������� ū ����ġ���� ������ ���� Ȯ���Ͽ� �̺� Ž���� �߰����� ����س����� ���̴�.

// �ڼ��� ������ �ּ����� �����.

int N, P, K;
vector<pair<int, int>> board[1001];

// maxcost���� ū ����ġ�� ������ Ƚ���� ��ȯ�ϴ� �Լ�.
bool BFS(int maxcost)
{
    // 0-1 BFS�� �����ϱ� ���� deque�� Ȱ��.
    deque<int> que;
    que.push_back(1);
    // �ּҰ����� �迭 dist�� maxcost���� ū ����ġ���� �ּҰ��̴�.
    vector<int> dist(N + 1, 1e9);
    dist[1] = 0;

    while (!que.empty())
    {
        int here = que.front();
        que.pop_front();

        for (auto next : board[here])
        {
            int there = next.first;
            int cost = next.second;
            int add = cost > maxcost ? 1 : 0;
            if (dist[there] > dist[here] + add)
            {
                dist[there] = dist[here] + add;
                // 0-1 BFS�� ����. ����� 0�̶�� �տ��� ������ ó���ϰ�
                // ����� 1�̶�� �ڿ��� ���߿� ó���Ѵ�.
                if (add)
                    que.push_back(there);
                else
                    que.push_front(there);
            }
        }
    }
    return dist[N] <= K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> P >> K;
    for (int i = 0; i < P; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
    // �������� �����ؾ��Ѵ�. while(from <= to)�� �̿��� ����������
    // ��Ʈ�Ӹ����� �����ϱ� ���� ���� �ּҰ� - 1 ~ �ִ밪 + 1�� ������ �Ѵ�.
    int from = 0, to = 1000001, answer = -1;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (BFS(mid))
        {
            answer = mid;
            to = mid - 1;
        }
        else
        {
            from = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}