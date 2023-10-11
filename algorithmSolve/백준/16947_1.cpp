#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// 16947���� �� ���� Ǯ��.
// �켱 ù°�� �Ǽ��ߴ����� ����Ŭ�� ������ �ľ����� ���Ѱ��̴�.
// �־����� �������� ����Ŭ�� 1�����̴�. ������ Ǯ������ ����Ŭ�� ����� ����
// DFS�� 1 ~ N������ ��� ��ȸ�߾���.

// �ι�°�� �Ǽ��Ѱ��� BFSŽ���� �������̴�.
// ����Ŭ�� �ƴѰ����� ����Ŭ������ �̵��� �������� �˾ƾ߸� �Ѵ�.
// ������ ����Ŭ�� ������ ����Ŭ�� �ƴѰ������� �̵��� �������� ���� �ȴ�.

// �� 2������ ���� ū �������ϸ� �����״�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
bool isCircle[3001], visit[3001];
int parent[3001], answer[3001];
int N, start;
bool isfind = false;

// ��ȯ�� ã�� �Լ�.
void FindCircle(int here, int prev)
{
    visit[here] = true;

    for (int there : board[here])
    {
        // ����Ŭ�� 1�����̱⿡ �̹� ã�Ҵٸ� ��� DFS�� �����Ѵ�.
        if (isfind)
            return;

        if (visit[there])
        {
            // ���� ������ �̹� �湮�� ���̶�� ���� ����Ŭ�� �̷��.
            if (prev != there)
            {
                // ������� ���� ����(������)���� ��� ����Ŭ���� �����ϰ� Ż���Ѵ�.
                int p = here;
                while (p != there)
                {
                    isCircle[p] = true;
                    p = parent[p];
                }
                isCircle[p] = true;
                isfind = true;
                return;
            }
        }
        // �׷��� ���� ��� �湮 ������ �����ϰ� ��͸� ȣ���Ѵ�.
        else
        {
            parent[there] = here;
            FindCircle(there, here);
        }
    }
}

// �� ����Ŭ�� �������� ����Ŭ�� �ƴ� ���������� �Ÿ��� ����ϴ� �Լ�.
void Findlen()
{
    queue<pair<int, int>> que; // ��ġ, �Ÿ�.
    // �� ����Ͽ��� ����Ŭ�� �������� ����Ŭ�� �ƴ� �������� �Ÿ��� ����ϴ� ���� �� ���Ѵ�.
    for (int i = 1; i <= N; ++i)
    {
        if (isCircle[i])
        {
            que.push(make_pair(i, 0));
            visit[i] = true;
        }
    }

    while (!que.empty())
    {
        int here = que.front().first;
        int cost = que.front().second;
        que.pop();

        for (int there : board[here])
        {
            // ���� �湮�� ������ ����Ŭ�� �����̰ų� Ȥ�� �̹� �Ÿ��� ����� �����̱⿡ �����Ѵ�.
            if (visit[there])
                continue;

            // �Ÿ��� ������ְ� �湮 ����(��� ����)�� �����ϰ� ���� ������ ���� ť�� �ִ´�.
            answer[there] = cost + 1;
            visit[there] = true;
            que.push(make_pair(there, answer[there]));
        }
    }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    FindCircle(1, -1);

    memset(visit, false, sizeof(visit));
    Findlen();
    for (int i = 1; i <= N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    memset(isCircle, false, sizeof(isCircle));
    int from, to;
    for (int i = 0; i < N; ++i)
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