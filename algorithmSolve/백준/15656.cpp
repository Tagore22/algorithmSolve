#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �ߺ��� ������ ��� ������ ����ϴ� ������.
// ���� ����� �ʴ�. �ٸ� �ӵ��� �� ������
// answer[]�� ����� int �迭 ��� string�� ����Ͽ� �ϴ�
// �� ������. ������ �𸣰����� int���� char�� �� �۾Ƽ� �׷��� ���⵵ �ϴ�.

// �ڼ��� ������ �ּ����� �����.

int board[7], answer[7];
int N, M;

// ��� ����� ���� ��ȸ�ϴ� �Լ�.
void BackTrack(int idx)
{
    // M���� ������� ����Ѵ�.
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // �ߺ� ���ΰ� ������⿡ 0���� �ٽ� N - 1���� ��ȸ�ϸ� �Ѱ��� �߰��س�����.
    for (int i = 0; i < N; ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1);
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