#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ���� v���� �����Ͽ� ���絵�� K�̻��� �ش��ϴ� ������ ������ ����ϴ� ������. ���絵��
// ������ ���絵�� ���ο� ������ ���絵�� �� ���� ���� ����� �� �ִ�. BFS�� �̿��Ͽ�
// ����� �ʰ� ����Ҽ� �ִ�. ������ �������� �ʾƼ� �Ѱ�� �����ε� �� Ǯ��� �ϴ�.

// �ڼ��� ������ �ּ����� �����.

int N, Q;
const int MAXNUM = 1000000001;
vector<pair<int, int>> board[5001];

void BFS(int limit, int from)
{
    queue<pair<int, int>> que;
    // ���絵�� �ʱⰪ�� �ſ� ū������ �ؾ��Ѵ�. �׷��� min()�� ���� ���� ���絵��
    // �������� ���ɼ� �ֱ� �����̴�.
    que.push(make_pair(from, MAXNUM));
    bool visit[5001] = { false, };
    visit[from] = true;
    int answer = 0;

    while (!que.empty())
    {
        int here = que.front().first;
        int l = que.front().second;
        que.pop();

        // ���� ����� ����� ��� �������� ��ȸ�ϸ� ���絵�� K���� ũ�ų� ����
        // �������� ť�� ������ �̶� ��°� answer�� 1�� ������Ű�� �湮 ���θ�
        // �����Ѵ�.
        for (auto& next : board[here])
        {
            int there = next.first;
            int usa = next.second;
            int nextl = min(usa, l);
            // ��湮�̰ų�, ���絵�� K���� ���������� �����Ѵ�.
            if (visit[there] || nextl < limit)
                continue;
            ++answer;
            que.push(make_pair(there, nextl));
            visit[there] = true;
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    int limit, from;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> limit >> from;
        BFS(limit, from);
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    int from, to, u;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to >> u;
        board[from].push_back(make_pair(to, u));
        board[to].push_back(make_pair(from, u));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}