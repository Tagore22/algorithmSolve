#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �������� ���� �������� Ǯ���� ���ǿ� ��ȸ ������.
// ���� ��ü�� �ſ� �����Ѵ�. ���� �ִ� ��� ��츦 ����ؼ� ���� �ּҰ��� ����ϸ� �ȴ�.
// �ٸ� 2���� �߿��� �κ��� �����Ѵ�.

// 1. ����� �������� ���� �����ϵ� �� ���� ����.(�ƹ������ε� �����ϸ� �ȴ�)
// 2. ����ġ���� ȿ���� ũ��.

// Ư�� 2���� �ӵ��� 124 -> 0���� Ȯ ���̰� ����.
// ���� 1���� �ڵ��� ������ �ϴµ� �ſ� �߿��ϴ�.

// �ڼ��� ������ �ּ����� �����.

int board[10][10];
bool visit[10];
int N, answer = 978654321;

// ��� ��츦 ����غ��� �Լ�.
void DFS(int cur, int num, int sum)
{
    // �� ����� 2���� ����ġ��. �̹� ����� ���� ������ �ּҰ����� ũ�ٸ� �����Ѵ�.
    if (sum > answer)
        return;

    if (num == N)
    {
        // N���� ��� �������� ������ �������� ���� �������� �ǵ��ư��� �ִٸ�
        // answer�� �����Ѵ�.
        int end = board[cur][0];
        if (end != 0)
            answer = min(answer, sum + end);
        return;
    }

    // ��� ���õ��� ��ȸ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        // �̹� �湮�� �����̰ų� �����Ҽ� ���� �����̶�� �����Ѵ�.
        if (visit[i] || board[cur][i] == 0)
            continue;

        visit[i] = true;
        DFS(i, num + 1, sum + board[cur][i]);
        visit[i] = false;
    }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));

    visit[0] = true;
    DFS(0, 1, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}