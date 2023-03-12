#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// Ư���Ұ� ���� ���ͽ�Ʈ�� �����̴�.
// �켱����ť�� �̿��Ͽ� ���� �ּҰ����� ũ�ٸ� �����ϰ� �׷��� �ʴٸ� ���� �ִ� ������ ����
// �ٸ����� �ּҰ��� ���س�����.

vector<vector<pair<int, int>>> board;
const int MAX_NUM = 987654321;
int N, M, from, to;

void DK()
{
    vector<int> answer(N + 1, MAX_NUM);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que; // �Ÿ�, ��ġ.
    que.push(make_pair(0, from));

    while (!que.empty())
    {
        int cost = que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > answer[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            if (cost + len < answer[there])
            {
                answer[there] = cost + len;
                que.push(make_pair(answer[there], there));
            }
        }
    }

    cout << answer[to] << '\n';
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
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
    }
    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}