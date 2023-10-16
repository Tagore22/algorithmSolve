#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// Ǯ��.
// �׷��� Ž�� ��������. 1�� �������� �����ؼ� �Ÿ��� 2������ ������ ã�� �� �������� ���� ����ϸ� �ȴ�.
// DFS Ȥ�� BFS�� ��� Ǯ�� �ִ�. �̹� Ǯ�̴� BFS��.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
bool isanswer[501], visit[501];
int N, M;

// BFS��ȸ�� �����ϴ� �Լ�.
void BFS()
{
    queue<int> que;
    que.push(1);
    memset(isanswer, false, sizeof(isanswer));
    memset(visit, false, sizeof(visit));
    visit[1] = true;
    int len = 0;

    // ť�� ����ų� �̵��� 3�� �̻��� ��� �ݺ����� Ż���Ѵ�.
    while (!que.empty() && len < 2)
    {
        // �̹� �̵��� �̹� ť�� ��� ���ҵ鸸�� ����ɼ� �ִ�.
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            // here���� �̵��Ҽ� �ִ� ��� �̵��� �����Ѵ�.
            for (int i = 0; i < board[here].size(); ++i)
            {
                int there = board[here][i];

                // ���� ���� there�� �̹� �湮�Ѱ��̶�� �����Ѵ�.
                if (visit[there])
                    continue;

                visit[there] = true;
                isanswer[there] = true;
                que.push(there);
            }
        }
        // len�� ���������� �ƴ� �� ���������� �����ؾ� ������ �´´�.
        ++len;
    }
}

void MakeAnswer()
{
    BFS();

    int answer = 0;
    // 1���� �Ŷ��̹Ƿ� �����ϰ� 2������ ���� ã�´�.
    for (int i = 2; i <= N; ++i)
    {
        if (isanswer[i])
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}