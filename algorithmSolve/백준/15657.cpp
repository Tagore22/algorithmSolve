#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� ���ŷο��� �����̴�. ������ ������ ����� ������������ �������ϰ� � ���� �����Ҷ�
// ���������� �����ؾ� �Ѵ�. (���ø� �����Ұ�)
// ���� ���� ���� ���� ��ȣ�� �˾ƾ� �ߴ�. �Ű������� �� ���� ��ȣ�� �����Ͽ� ��Ʈ��ŷ���� ��� ������
// ��ȸ�ϸ� �ȴ�. ���� ������ ��� �ϳ��� �迭�� ���� �������� ����Ҽ� �ִ� ����� ��Ծ�ô�.

// �ڼ��� ������ �ּ����� �����.

int board[8], answer[8];
int N, M;

// ��� ������ ��ȸ�ϴ� �Լ�. �ι�° �Ű������� ���� ���� ���ҹ�ȣ�� �����Ѵ�.
void BackTrack(int idx, int prev_num)
{
    // M���� ������� ����ϰ� ��͸� �����Ѵ�.
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // ���� ������ ���������� �����غ���.
    for (int i = prev_num; i < N; ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1, i);
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    BackTrack(0, 0);
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