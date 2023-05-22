#include <iostream>
#include <algorithm>

using namespace std;

// 11497���� �ٸ� Ǯ��.
// 2������ �޶����µ� ������ ����.

// 1. deque�� ���� �ʰ� �׳� �迭�� �ذ�.
// 2. �� ��Ʈ�Ӹ�(0, 1�� N - 1, N - 2)�� ó������ ����.

// 1���� �ϼ��� �ڵ带 ���� �˵��� ������ deque�� �̿��� Ǯ�̿� ���ϸ�
// ���� ���� + 2�� ���� ����. �׷��⿡ ���� deque�� ���� �ʰ� ���� ���� board[i]�� board[i + 2]�� ����ϸ� �ȴ�.

// 2���� ���ۿ� ��ġä�� ���� ���ε�, ���� ��� ������ ���õ� 2 4 5 7 9 �� ����
// �� ������ ������ ���� 2 4 5 7 9���� ����� ��� board[i]�� board[i + 2]�� ����ϴµ� ���ĵ� �����̱⿡
// ��Ʈ�Ӹ��� board[0]�� board[1]�� ��갪 2�� board[0]�� board[2]�� ��갪 3���� ������ �������ۿ� ����.

// �׷��⿡ ���� ��Ʈ�Ӹ����� ������� �ʾƵ� �������� ���� �ִ�.

int board[10000];
int T, N;

void MakeAnswer()
{
    for (int test = 0; test < T; ++test)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];

        sort(board, board + N);

        int answer = 0;
        // �迭�� ��ȸ�ذ��� i��° ���ҿ� i + 2��° ���ҷ� ����ϰ�, ���߿� ��Ʈ�Ӹ����� ���� ������־��µ�
        // ���ĵ� �����̱⿡ ��Ʈ�Ӹ����� ������ i��° ���ҿ� i + 2��° ������ ��갪���� �������ۿ� ����.
        for (int i = 0; i < N - 2; ++i)
            answer = max(answer, abs(board[i] - board[i + 2]));

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}