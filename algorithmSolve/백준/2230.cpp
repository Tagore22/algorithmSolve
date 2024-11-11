#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� Ǯ�̰� ������ �ȳ��� ��Ǯ���� �����ε�, ������ ��û ���� Ǯ����. �������Ͱ� �ٷ� �������� �����̴�.
// �Ѵ� 0���� �����ؼ� �� ���̰� M���� �۴ٸ� to�� ���� 1�� �÷����� ���� ���� ���̸� ���Ѵ�. �� ���� �ٽ�
// from�� 1�÷� �Ǵٽ� ���� ���� ���̸� ���Ѵ�. �ٸ� to�� �ִ� N - 1������ �����ϴ°� �ؾ�� �ȵȴ�.
// �̷��� �ִ� 10������ ��ȸ�ȿ� ���� Ǯ�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[100000];
int N, M;

void MakeAnswer()
{
    // �������͸� ����ϱ� ���� ����.
    sort(board, board + N);
    int from = 0, to = 0, answer = 2100000000; // M�� �ִ� 20���̱� ������ �׺��� Ŀ���Ѵ�.
    // from�� to���� �� Ŀ���ų� to�� N���� ������������ ���ȴ�.
    while (from <= to && to < N)
    {
        // �� ���� ���̰� M���� �۴ٸ� to�� 1�������� ���̸� Ű���.
        if (board[to] - board[from] < M)
        {
            ++to;
        }
        // �� ���� ���̰� M���� ó������ Ŀ������ �� ���� ������ answer�� ���ϰ�
        // from�� 1�������� �ٽ� M���� ū ���� ���� ���̰��� ���Ѵ�.
        else
        {
            answer = min(answer, board[to] - board[from]);
            ++from;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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