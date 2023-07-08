#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ���������� �� �� ��� ���ư����, �� �ּ����� ����(����ġ)�� �ʿ�� �����Ƿ�
// ���ͽ�Ʈ�� �˰����� ����ؾ� �ߴ�. �ݹ� ���ö� �����̾���.
// ���� ��ü�� �׳� ���ͽ�Ʈ�� ���� �����⸸ �ϸ� �Ǵ� ������ ũ�� �������� ����.
// �ٸ� ���ͽ�Ʈ�� �˰��򿡼� �򰥷ȴ� 2������ �� ����صξ�� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<pair<int, int>>> board;
int N, M;
const int MAX_NUM = 987654321;

// ���ͽ�Ʈ�� ��ȸ �Լ�. ���������� ����Ͽ� �����ϴ� ��� �����鿡�� �ٽ� ����Ѵ�.
// �ٸ� ��ȸ�� �ּ� ���� �迭�� �����ΰ� �ִ밪���� �ʱ�ȭ�Ͽ� �Ź� ������ ����������
// �� ���������� ���̰� �ּ� ���̺��� ��ų� ���ٸ� �����Ѵ�.
void DK()
{
    vector<int> dis(N + 1, MAX_NUM);
    // ���������� ������������ ���̴� 0.
    dis[1] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));

    while (!que.empty())
    {
        // ���� ������ ���������κ����� ���̸� ť���� ������.
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // ����Ͽ��� ������ �ּұ��̺��� ���� �� ���̰� ��ų� ���ٸ� �����Ѵ�.
        if (cost > dis[here])
            continue;

        // ���� �������� �����Ҽ� �ִ� �ٸ� �������� ��� ��ȸ�Ѵ�.
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            // ���� ���� + ���� �������� �ٸ� ���� there������ ���̰� ���������� there������ ����
            // dis[there]���� ª�ٸ� �����Ѵ�. ���⼭ <���� <=���� �򰥸����� �־��µ� �̷���
            // ����ġ�� ���� 0�϶��� �����ϸ� �ȴ�. A -> B�� 0�̶�� B�� �����Ͽ����� A�� ������ �Ǵµ�
            // ����ġ�� 0�̶� cost + len�� dis[A]�� ���� �������� �ȴ�. ���⼭ <�� �ƴ� <=�� ����ϰ� �Ǹ�
            // �ٽ� A�� ���ư��� ������ <=�� �ƴ� <�� ����Ͽ��� �Ѵ�.
            if (cost + len < dis[there])
            {
                dis[there] = cost + len;
                que.push(make_pair(-dis[there], there));
            }
        }
    }

    // ������������ �ּұ��̸� ����Ѵ�.
    cout << dis[N] << '\n';
}

void MakeAnswer()
{
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<pair<int, int>>());
    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}