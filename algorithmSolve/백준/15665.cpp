#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// N���� ������ M���� ���� �ø��� 11��°��.
// �̹����� ��� ���� ����, ���ڸ��� �� ��� ������� �ٸ�
// �Ȱ��� ���� �ݺ��ؼ� ������ �ȵȴ�. �� Ǯ�̴� ������ ���� int prev�� �̿��Ͽ�
// �� �ߺ��� ���Ҵ�.

// �ڼ��� ������ �ּ����� �����.

int board[7], answer[7];
int N, M;

void BackTrack(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // ������ ����� ���� �����Ͽ� �̹��� �� ���� ���ٸ�
    // �����Ѵ�.
    int prev = -1;
    for (int i = 0; i < N; ++i)
    {
        if (board[i] == prev)
            continue;

        answer[idx] = board[i];
        BackTrack(idx + 1);
        prev = board[i];
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}