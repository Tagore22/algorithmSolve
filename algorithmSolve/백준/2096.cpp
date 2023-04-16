#include <iostream>

using namespace std;

// Ǯ��.
// DP�� ��ȭ�� �����̵� ������ �����ε� ���� Ǫ�°� ���� ó���ΰ� ����.
// ��������� ���� DP�ʹ� ���� �޶� ���޶����� ����.

// �ٵ� ���� �����غ��� ���� �̷��� ���ŷӰ� Ǯ�� �ʾƵ� ������ �Ʒ�, ������ �Ʒ�, ���� �Ʒ�
// �̷��� �������ۿ� �������� ���ϱ� ������ �׳� for������ �����Ҽ� �ִ� ���� �ִ� �ּҸ� ��� ����ص� �ɵ��ϴ�.

int board[100000][3];
pair<int, int> dp[2][3]; // �ִ�, �ּ�.
int N;

pair<int, int> DP(int y, int x)
{
    // ����ó�� -1�� �ƴϸ� ������� �ʰ� �Ź� �ʱ�ȭ���־�� �Ѵ�.
    pair<int, int>& ans = dp[y % 2][x];
    ans = make_pair(-1, 987654321);

    pair<int, int> next = dp[(y + 1) % 2][x];
    ans = make_pair(max(ans.first, board[y][x] + next.first), min(ans.second, board[y][x] + next.second));

    if (x - 1 >= 0)
    {
        next = dp[(y + 1) % 2][x - 1];
        ans = make_pair(max(ans.first, board[y][x] + next.first), min(ans.second, board[y][x] + next.second));
    }

    if (x + 1 < 3)
    {
        next = dp[(y + 1) % 2][x + 1];
        ans = make_pair(max(ans.first, board[y][x] + next.first), min(ans.second, board[y][x] + next.second));
    }

    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < 3; ++i)
        dp[(N - 1) % 2][i] = make_pair(board[N - 1][i], board[N - 1][i]);

    // ����ó�� �˾Ƽ� �������� �ʰ� �� ��, �� ������ ȣ�����־�� �Ѵ�.
    for (int i = N - 2; i >= 0; --i)
        for (int j = 0; j < 3; ++j)
            DP(i, j);

    pair<int, int> answer = make_pair(-1, 987654321);
    for (int i = 0; i < 3; ++i)
        answer = make_pair(max(answer.first, dp[0][i].first), min(answer.second, dp[0][i].second));

    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}