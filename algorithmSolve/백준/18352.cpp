#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������ ������ ������ڸ� X���� K�� �̵��Ͽ������� ������ ��ȣ�� ������������ ����ϸ� �ȴ�.
// �� ���� ������ �Ÿ��� 1�̱� ������ ���� ���ͽ�Ʈ�� ������� �ʾƵ� �ǰ�,
// �������� �־����⿡ ���� ����-���带 ������� �ʾƵ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
int N, M, K, X;

// ��� ��ȸ�� �����ϴ� BFS�Լ�.
void BFS()
{
    queue<int> que;
    que.push(X);
    vector<bool> visit(N + 1, false);
    visit[X] = true;
    // K�� �̵����� ����� �˱� ���� ����.
    int idx = 0;

    // ť�� ������� �ʾ����� K���� �̵����� ��� ��ȸ�Ѵ�.
    while (!que.empty() && idx < K)
    {
        int qsize = que.size();
        ++idx;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            for (int i = 0; i < board[here].size(); ++i)
            {
                int there = board[here][i];

                if (visit[there])
                    continue;

                que.push(there);
                visit[there] = true;
            }
        }
    }

    vector<int> answer;
    // �� ���� ���� ť�� ��� ��� �������� ������.
    while (!que.empty())
    {
        answer.push_back(que.front());
        que.pop();
    }

    // �������� ����ٸ� -1�� ����ϰ� Ż���Ѵ�.
    if (answer.empty())
    {
        cout << -1 << '\n';
        return;
    }

    // �׷��� �ʴٸ� ������������ �����Ͽ� ����Ѵ�.
    sort(answer.begin(), answer.end());
    for (int i : answer)
        cout << i << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K >> X;
    board.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}