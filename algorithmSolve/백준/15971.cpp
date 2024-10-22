#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ������ ���� �����ѵ� ��������� ���������� �������� �̵��ϴ� �Ÿ��� �����߿��� ���� ��Ÿ��� ������ ����ϸ� �ȴ�.
// �׷��� ���ؼ��� que�� ���� ��ġ�� ���� �̿��� ������� �̵��� ���� ��Ÿ����� ������ �־�������Ƿ� ���ο� ����ü��
// �����ߴ�. �������� �׸� ������ ����.

// �ڼ��� ������ �ּ����� �����.

struct ver
{
    // ���� ����ġ, ���� ����� �Ÿ���, �� �̵���.
    int where;
    int maxway;
    int sum;
};

vector<pair<int, int>> board[100001];
int N;
pair<int, int> pos;

void BFS()
{
    queue<ver> que;
    // �̺κп��� �Ǽ��� �ߴµ� �������� ���� ����� �̵����� -1�� �ʱ�ȭ�߾���. ������
    // N�� 1�̰ų� ������ == ������ ��츦 �����ϸ� �ٷ� 0 - (-1)�� �Ǿ� 0�� �ƴ� 1�� �Ǿ������.
    // ���� 0���� �ʱ�ȭ�ؾ߸� �Ѵ�.
    que.push(ver{ pos.first, 0, 0 });
    bool visit[100001] = { false, };
    visit[pos.first] = true;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int where = que.front().where;
            int maxway = que.front().maxway;
            int sum = que.front().sum;
            que.pop();

            // ���� ������ �����ߴٸ� �� �̵��� - ���� ����� �Ÿ����� ����ϰ� Ż���Ѵ�.
            if (where == pos.second)
            {
                cout << sum - maxway << '\n';
                return;
            }

            for (auto& cur : board[where])
            {
                int next = cur.first;
                // �̹� ������ �������� �ʾҴٸ� �̵��Ÿ��� ���� ����� �̵����� ���Ͽ� �����ϰ�
                // ���տ� �̹� �̵��Ÿ��� ���Ͽ� ť�� �ִ´�. ���� �湮���� ���� �����Ѵ�.
                if (!visit[next])
                {
                    int cost = cur.second;
                    int nextmax = max(maxway, cost);
                    que.push(ver{ next, nextmax, sum + cost });
                    visit[next] = true;
                }
            }
        }
    }
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> pos.first >> pos.second;
    int from, to, dis;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to >> dis;
        board[from].push_back(make_pair(to, dis));
        board[to].push_back(make_pair(from, dis));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}