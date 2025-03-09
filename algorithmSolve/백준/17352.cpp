#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// �α����� �������� �������߿��� �ϳ��� ����ϸ� �Ǵ� ������. ������ �����Ͽ��� DFS �Ҷ� �̿� ����Ѱ�
// �����ߴ���. BFS�ε� �Ȱ��� �����ϱ� ������ 1������ BFS�� �����ϰ� N������ ��ȸ�� ���� ���� �湮����
// ���� ù��° ������ ã���� �Ǿ���.

// �ڼ��� ������ �ּ����� �����.

vector<int> board[300001];
bool visit[300001] = { false, };
int N;

void BFS(int from)
{
    queue<int> que;
    que.push(from);
    visit[from] = true;

    // ���� from���� �湮�Ҽ� �ִ� ��� �������� ã�´�.
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto& there : board[here])
        {
            if (visit[there])
                continue;

            visit[there] = true;
            que.push(there);
        }
    }
}

void MakeAnswer()
{
    BFS(1);
    for (int i = 1; i <= N; ++i)
    {
        // 1�� �������� �����Ҽ� ������ ù��° ������ ã�� ����Ѵ�.
        if (!visit[i])
        {
            cout << 1 << ' ' << i << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int from, to;
    for (int i = 0; i < N - 2; ++i)
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