#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ó������ ������ �̿��� �׸��� �˰������� Ǯ�� ������ �˾Ҵµ� ���� �ƴϾ���.
// ���� ��� 5, 1, 8, 2, 3, 9��� ����� 15���� ���� ���� 18�̴�.
// ��¥ Ǯ�̴� �Ʒ��� ���� ����Ž���̾���. 
// 0 ~ N - 1���� ��ȸ�ϸ� ���� ���ҹ�ȣ idx ������ ���� board[idx]���� ũ�ٸ� �������� �Ѿ��
// ��� ȣ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[1000], dp[1000];
int N;

int BackTrack(int idx)
{
    // ���� ����. �� ������ ���ҿ� �����Ͽ��ٸ� ���̻� ���ư��� ������ ���Ұ��� �״�� ��ȯ�Ѵ�.
    if (idx == N - 1)
        return board[idx];

    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    // ������� ����� �ִ� �ּҰ��� ��� ���簪�̴�.
    ans = board[idx];
    // idx��° ���� ���Ұ����� board[idx]���� ũ�ٸ� ��� �õ��غ���.
    for (int i = idx + 1; i < N; ++i)
        if (board[i] > board[idx])
            ans = max(ans, BackTrack(i) + board[idx]);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = 0;
    for (int i = 0; i < N; ++i)
        answer = max(answer, BackTrack(i));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}