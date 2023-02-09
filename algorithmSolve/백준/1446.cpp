#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��
// BFS�� ���ؼ� ���� �ִ� ��� ��Ȳ�� ����Ѵ�.

// 1. �������� ���ؼ� ����.
// 2. �������� ������ �ʰ� �׳� ����.

// �־��� ��������� 2���� �迭�� �����س��� BFS�� 0���� ��ȸ�ϵ�, ���� ��ġ���� �������� ������� �ʴ� ��츦 ����Ͽ� que�� �ְ�
// �������� �����Ѵٸ� ��� �������� ����ϴ� ��� ���� que�� �־��ش�. �ٸ� �����ؾ������� �������� ��������� �����ؾ��ϴ� D����
// �� ���� ���� �����ؾ��Ѵٴ� ���̴�. �׷��⿡ que���� �Ǿ� ���Ҹ� �������� �� ��ġ�� D�� ���ٸ� �̵��� �Ÿ��� ������ answer��
// ���Ͽ� �ּҰ��� �����ϰ�, D���� ũ�ٸ� ����Ͽ��� �����ؾ��Ѵ�.

// �и� �߰��� ��ġ�� �κе� �ִµ� ����Ȱ� N�� D�� ���� ª�Ƽ� �׷��� ����.

vector<vector<pair<int, int>>> board; // ��������, �Ÿ�
int N, D, answer;

void BFS()
{
    answer = D;
    queue<pair<int, int>> que; // ��������, �Ÿ�
    que.push(make_pair(0, 0));
    while (!que.empty())
    {
        int here = que.front().first;
        int cost = que.front().second;
        que.pop();

        if (here == D) // ���������� �����Ͽ��� ���.
        {
            answer = min(answer, cost);
            continue;
        }
        else if (here > D) // ������������ �� ���� ���� �����ؾ��Ѵ�.
        {
            continue;
        }

        for (int i = 0; i < board[here].size(); ++i) // �������� �����Ѵٸ� ��� �������� ������.
        {
            int there = board[here][i].first;
            int len = board[here][i].second;
            que.push(make_pair(there, cost + len));
        }

        que.push(make_pair(here + 1, cost + 1)); // �������� �ƿ� ���� �ʾ�����.
    }
}

void MakeAnswer()
{
    BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> D;
    board.resize(D, vector<pair<int, int>>());
    for (int i = 0; i < N; ++i)
    {
        int from, to, len;
        cin >> from >> to >> len;
        board[from].push_back(make_pair(to, len));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}