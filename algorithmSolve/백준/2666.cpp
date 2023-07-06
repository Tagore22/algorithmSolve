#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// dp�����ε� ���� �� ���ڼ� �׷��� BFS�� Ǯ�� �־���.
// Ǯ�� ��ü�� ���� ����� �ʴ�. ���� 2���� ��ġ first�� second���� ���� �̵��ؾ��� ��ġ�� �̵��� �Ź� �̵����� ����
// �ּҰ��� �����ָ� �ȴ�. �ٸ� BFS�� Ǯ������ Ʋ�� ���� first�� ������ second���� ���� ����, second�� ������ first���� ������
// ���������� �����̴µ� ������ Ʋ���� ����.

// �ڼ��� ������ �ּ����� �����.

int N, T, first, second;
int board[20];
int dp[21][21][20];

// �� idx��° ��ġ�� first�� second�� ��� �̵����Ѻ��� �� ª������ �����ϴ� �Լ�.
int FindAnswer(int first, int second, int idx)
{
    if (idx == T)
        return 0;

    int& ans = dp[first][second][idx];
    if (ans != -1)
        return ans;

    // idx��° ��ġ�� first�� second�� ��� �̵����Ѻ��� �� ª������ ��ȯ�Ѵ�.
    ans = min(abs(board[idx] - first) + FindAnswer(board[idx], second, idx + 1),
        abs(board[idx] - second) + FindAnswer(first, board[idx], idx + 1));

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = FindAnswer(first, second, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> first >> second >> T;
    for (int i = 0; i < T; ++i)
        cin >> board[i];

    if (first > second)
        swap(first, second);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}