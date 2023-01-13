#include <iostream>

using namespace std;

//Ǯ��
//2193�� ������ �Ǻ���ġ �ذ������ Ǭ ���.
//N��° �ڸ����� 0�̶�� ���ڸ��� ���� ���� �͵� �Ǵ� N-1���� �ü� ������,
//1�̶�� �ٷ� ���ڸ��� 0�� �ΰ� �� ���� N-2���� �ü� �����Ƿ� ���� ����
//N = N-1 + N-2�� ��ȭ�Ŀ� �ش��Ѵ�.

long long board[90];
int N;

void MakeAnswer()
{
    board[0] = 1;
    board[1] = 1;

    for (int i = 2; i < N; ++i)
        board[i] = board[i - 1] + board[i - 2];

    cout << board[N - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}