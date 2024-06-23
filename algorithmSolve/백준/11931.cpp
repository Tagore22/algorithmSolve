#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ��ü�� ���� ����� ���� �׳� ���ĸ� �ϸ� �Ǵ� ������. �ٸ� N�� �ִ밪�� 100������ �ſ� ũ�� ������
// �ð��� ���� �ɸ���. �켱���� ť�� �̿��ϱ⵵ �غ������� ���� �ѹ��� �����ϴ°��� �� ������ ������
// �� Ǯ�̰� �׳��� �� �������̾���.

int N;
int board[1000000];

void MakeAnswer()
{
    sort(board, board + N, greater<>());
    for (int i = 0; i < N; ++i)
        cout << board[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}