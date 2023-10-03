#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// Ǯ��.
// ����Ŭ ��ȯ�� ã�� ������.
// ������ ūƲ�� ������ ����.

// 1. DFS�� �̿��Ͽ� ��� �������� ����Ŭ�� ������ ������ ã�´�.
// 2. ����Ŭ�� ���� �ʴ� ������ BFS�� �̿��Ͽ� ���� ����� ����Ŭ�� ���� �������� ��ġ�� ã�´�.

// ���� �̻��̴�. �ٸ� ������ ������ �κ��� ó���ϴ°� ���ŷο��� ��������.
// �ξ� �� ���� Ǯ�̰� �ִ� �� ������ ���� ���·δ� �������� �������� �����.

// �ڼ��� ������ �ּ����� �����.

struct point
{
    // ���� ��ġ, ���� ��ġ, ���� ��ġ, �Ÿ�.
    int s;
    int h;
    int p;
    int l;
};

vector<vector<int>> board;
bool isCircle[3001], visit[3001];
int parent[3001], answer[3001];
int N, start;

// ����Ŭ�� ���� �������� Ȯ���ϴ� �Լ�.
void FindCircle(int here, int prev)
{
    visit[here] = true;

    // ���� ���� here���� �̵��Ҽ� �ִ� ��� ������ ��ȸ�Ѵ�.
    for (int there : board[here])
    {
        // ������ �Դ� ������ �ƴϸ� ���� ������ �������̶�� here�� ����Ŭ�� ���´�.
        if (prev != there && there == start)
        {
            // ���±��� �����Դ� ��� ������ ���� ����Ŭ�� ���´�.
            while (parent[here] != -1)
            {
                isCircle[here] = true;
                here = parent[here];
                answer[here] = 0;
            }
            isCircle[here] = true;
            answer[here] = 0;
            return;
        }
        // �׷��� �ʰ� �̹� �湮�� ���̶�� �����Ѵ�.
        if (visit[there])
            continue;

        // �����Դ� �������� �����ϰ� ���ȣ���� �Ѵ�.
        parent[there] = here;
        FindCircle(there, here);
    }
}

// ����Ŭ�� ������ �ʴ� �������� ����Ŭ�� ���� ���� ����� ������ ã�� �Լ�.
void Findlen()
{
    queue<point> que; // ���� ��ġ, ���� ��ġ, ���� ��ġ, �Ÿ�.
    for (int i = 1; i <= N; ++i)
    {
        if (!isCircle[i])
        {
            que.push(point{ i, i, -1, 1 });
        }
    }

    while (!que.empty())
    {
        int s = que.front().s;
        int here = que.front().h;
        int prev = que.front().p;
        int len = que.front().l;
        que.pop();

        // ���� ���� here���� �̵��Ҽ� �ִ� ��� ������ ��ȸ�Ѵ�.
        for (int there : board[here])
        {
            // ���� ������ ����Ŭ�� ���´ٸ� �Ÿ��� �����ϰ� Ż���Ѵ�.
            if (isCircle[there])
            {
                answer[s] = len;
                break;
            }
            if (there == prev)
                continue;

            que.push(point{ s, there, here, len + 1 });
        }
    }
}

void MakeAnswer()
{
    // ���� �̺κ��� �ӵ��� ������ �ϴ� �κа���. ���� N���� DFS�� ��ȸ���� �ʾƵ� �Ǵµ�.
    for (int i = 1; i <= N; ++i)
    {
        if (isCircle[i])
            continue;

        memset(visit, false, sizeof(visit));
        parent[i] = -1;
        start = i;
        FindCircle(i, -1);
    }

    // ����Ŭ�� ������ �ʴ� ��� �������� �Ÿ��� ã�´�.
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