#include <iostream>

using namespace std;

// Ǯ��.
// DP�� DFS�� ����ϴ� ��������. ��ó�� ��� ��ġ�� ���������� �� dp���� 0���� �ʱ�ȭ�ϰ�
// �迭���� ����� ��ġ������ 1�� ��ȯ�Ѵ�. ��������� ��ȯ�� �Ͼ�� ���� dp���� 0��,
// �迭���� ����� ���� dp���� 1�� �ȴ�. �׸� ����� �ʾҴµ� �������� 33�۹ۿ� �ȵȴ�.

// �ڼ��� ������ �ּ����� �����.

char board[500][500];
int dp[500][500];
int N, M, answer = 0;

// ��ǥ y, x���� �����ؼ� �����Ҽ� �ִ� ��� ��ǥ�� ��ȸ�ϴ� DFS �Լ�.
int DFS(int y, int x)
{
    // �迭���� ����ٸ� 1�� ��ȯ�Ͽ� ������� ������ ��� ��ǥ�� 1�� �ѱ��.
    if (y >= N || y < 0 || x >= M || x < 0)
        return 1;

    // �̹� �湮�ߴ� ���̶�� ������ dp���� �ѱ��.
    // ���� 0�̶�� �������� ���Ѱ��̰� 1�̶�� �����ϴ� ���̴�.
    int& ans = dp[y][x];
    if (ans != -1)
        return ans;

    // �ݵ�� 0���� �ʱ�ȭ�ؾ��ϴµ� ���� �̹� ��ȸ���� �湮�Ѱ��� �Ǵٽ� �湮�Ѵٸ�
    // �װ��� �迭���� ����� ����. �̶� 0�� ��ȯ�Ͽ� ��ȸ�� �Ͼ�� �˷����ϱ� �����̴�.
    ans = 0;
    if (board[y][x] == 'U')
        ans = DFS(y - 1, x);
    else if (board[y][x] == 'R')
        ans = DFS(y, x + 1);
    else if (board[y][x] == 'D')
        ans = DFS(y + 1, x);
    else
        ans = DFS(y, x - 1);
    // ��� ��ȸ�� ������ 2�� for������ ��� dp������ ���ص� �������.
    // �ٸ� �� ����� �� 2�� for���� ��Ǯ�� ���� �ʾƵ� �Ǵ� ����̴�.
    // ��� ��ǥ�� �ݵ�� �ѹ����� �湮�ϱ� �����̴�.
    answer += ans;
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            dp[i][j] = -1;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (dp[i][j] == -1)
                DFS(i, j);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}