#include <iostream>

using namespace std;

// Ǯ��.
// ó������ ��ȭ���� �̿��ؼ� Ǯ �����̾��µ� ������ ������ ���� �ʾҴ�.
// �׷��ٰ� �˰� �� ���� ���� �ִ�ġ�� 15, 28, 19�϶���� ���̴�.
// ���ÿ��� ���Ե� �� ���� 8000�� ä �ȵǴµ� ���������
// 1�� ������Ű�鼭 ���� ���ʷ� 3���� ���� ���� E, S, M�� �����Ҷ�
// ������ answer�� ������ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[3] = { 1, 1, 1 };
int E, S, M;

void MakeAnswer()
{
    int answer = 1;
    while (true)
    {
        // 3���� ���� ���� E, S, M�� ������ ��� �ݺ����� Ż���Ͽ� ���� ���.
        if (board[0] == E && board[1] == S && board[2] == M)
            break;

        // 1�� ��� �÷�������. �ٸ� ���� ���ʰ��� 0�� �ƴ� 1�̱� ������
        // 1�������� ���������� 0�̶�� ���� �ٲ��־���Ѵ�.
        ++answer;
        board[0] = (board[0] + 1) % 16;
        board[0] = board[0] == 0 ? 1 : board[0];
        board[1] = (board[1] + 1) % 29;
        board[1] = board[1] == 0 ? 1 : board[1];
        board[2] = (board[2] + 1) % 20;
        board[2] = board[2] == 0 ? 1 : board[2];
    }
    cout << answer << '\n';
}

void Input()
{
    cin >> E >> S >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}