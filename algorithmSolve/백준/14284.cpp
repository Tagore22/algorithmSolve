#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ���� ���� ������ �ִ� �׷����� ���� ����Ʈ�� �־����� ������ �Ѱ��� �߰��Ͽ� S�� T�� �̾�����
// ����ġ ���� �ּҰ��� ���ؾ��ϴ� ������. �� S���� T�� �ּ� ��θ� ���ϸ� �ȴ�. ����ġ���� �ּҰ���
// 1�̹Ƿ� ������ ���⿡ ���ͽ�Ʈ��� �����Ͽ���.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[5001];
int N, M, from, to;
const int MAXNUM = 987654321;

// ���ͽ�Ʈ�� �˰����� �����ϴ� �Լ�
void DK()
{
    vector<int> dist(N + 1, MAXNUM);
    dist[from] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, from));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > dist[here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int next = cost + p.second;

            if (dist[there] > next)
            {
                dist[there] = next;
                que.push(make_pair(-next, there));
            }
        }
    }
    cout << dist[to] << '\n';
}

void MakeAnswer()
{
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}