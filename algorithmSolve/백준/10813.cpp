#include <iostream>

using namespace std;

// Ǯ��.
// �־����� ���ҵ��� ���� ��ȯ�ϴ� ������.
// ó������ 1 ~ N���� ���� �� �ְ�
// 2���� �� from, to�� M�� �־����� board[from]�� board[to]�� ����
// M�� ��ȯ�ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[101];
int N, M;

void MakeAnswer()
{
    int from, to;
    // M����ŭ from�� to�� �־������� board[from]�� board[to]�� ��ȯ�Ѵ�.
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        swap(board[from], board[to]);
    }

    // ��� ���.
    for (int i = 1; i <= N; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // �ʱⰪ�� 1 ~ N������ �������� �־�����.
    for (int i = 1; i <= N; ++i)
        board[i] = i;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}