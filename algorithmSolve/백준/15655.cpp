#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// N���� ���� ������������ �ߺ����� �ʰ� M���� ����� ����ϴ� ������.
// ���� ������ ����.

// �ڼ��� ������ �ּ����� �����.

int board[8], answer[8];
int N, M;

// ��� ��츦 ��ȸ�ϴ� �Լ�.
void BackTrack(int idx, int cur)
{
    // M�� ������� ����� Ż���Ѵ�.
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // �ߺ����� �ʰ� ������ ���� + 1���� ����� �ִ� ��� ��츦 ��ȸ�Ѵ�.
    for (int i = cur + 1; i < N; ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1, i);
    }
}

void MakeAnswer()
{
    // ������������ ������ �ϱ⿡ ������������ ���Ұ����� �����Ѵ�.
    sort(board, board + N);
    BackTrack(0, -1);
}

void Input()
{
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