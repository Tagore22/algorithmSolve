#include <iostream>
#include <algorithm>

using namespace std;

// ������ 1940�� Ǯ�̰� �ʹ� ���� �ɷ��� �ٽ� ã�ƺ���
// �������� ��������. �����Ͽ� �� ������ �տ� ���� �������̳� ������ �̵�����
// ���� M�� ���� ���� �� ������ �˼� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[15000];
int N, M;

void MakeAnswer()
{
    // �������� �˰����� ���� ����.
    sort(board, board + N);
    // ���� �������� ������ �ʱ�ȭ�Ѵ�.
    int answer = 0, from = 0, to = N - 1;
    // ��� ���Ұ��� �����ϱ⿡ ���� �� ���� ���ؼ� M�� ����� ����.
    // ���� from�� to�� ���� ���� �����Ҽ� ����.
    while (from < to)
    {
        // ������ ���� M���� �۴ٸ� ũ�⸦ �÷����ϱ⿡ from�� ���������� �̵��Ѵ�.
        if (board[from] + board[to] < M)
        {
            ++from;
        }
        // ������ ���� M���� ũ�ٸ� ũ�⸦ �ٿ����ϱ⿡ to�� �������� �̵��Ѵ�.
        else if (board[from] + board[to] > M)
        {
            --to;
        }
        // ������ ���� M�̶�� ������ ��� ���̻� ����Ҽ� ���⿡ from�� to�� ���� ������, �������� �̵���Ű��
        // ������ answer�� 1 ������Ų��.
        else
        {
            ++from;
            --to;
            ++answer;
        }
    }
    cout << answer << '\n';
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