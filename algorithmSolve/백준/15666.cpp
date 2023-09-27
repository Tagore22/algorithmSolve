#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ��°������ �ø�� ��û ���� ������. ��������� ����� �ʾ�������.
// ���� �ִ� ��� ������ ������������ ����ϴ� ������. �ٸ� �̹�����
// ��� ������ ���� i��° ���� �ڿ� ������ ���麸�� ������ �۰ų� ���ƾ��Ѵ�.
// �� ��Ʈ��ŷ�� �����ϵ�, ���簪�� ���� ���������� �����ؾ��Ѵٴ� ���̴�.
// ���� �ߺ� ��뵵 ��밡���ϴ� ���� bool�迭�� ���� �ߺ����θ� üũ�� �ʿ䵵 ����.

// �ڼ��� ������ �ּ����� �����.

int board[8], answer[8];
int N, M;

// ��� ������ ����� �Լ�.
void BackTrack(int num, int idx)
{
    // M���� ������ ���� ��� ����ϰ� Ż���Ѵ�.
    if (num == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    int prev_num = 0;
    // ���������� N - 1���� ��ȸ�ϸ� ��� ������ �����.
    // �ٸ� ���� ������ 2�� �̻� �������� ���ϱ⿡ ������ ������
    // üũ�ϸ� ���Ѵ�.
    for (int i = idx; i < N; ++i)
    {
        if (board[i] == prev_num)
            continue;

        prev_num = board[i];
        answer[num] = board[i];
        BackTrack(num + 1, i);
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