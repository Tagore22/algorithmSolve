#include <iostream>

using namespace std;

//Ǯ��
//��ȭ�ĸ� ã�Ƴ��� ������ ������. �̹� �ڸ��� 1�� ���°� ���� �ڸ��� 0�϶��� �����ϱ⿡ ���� �ڸ��� 0�� ����̰�,
//�̹� �ڸ��� 0�϶����� ���� �ڸ��� 1�̵� 0�̵� ������⿡ ���� �����ش�.
//���������� board[N-1][0]�� board[N-1][1]�� ���ؼ� ����ϸ� �ȴ�. �ٸ�, N�� Ŀ������ int�� �������� ����⿡
//long long �������� board�� �����ؾ��Ѵ�.

long long board[90][2];
int N;

void MakeAnswer()
{
    board[0][0] = 0;
    board[0][1] = 1;

    for (int i = 1; i < N; ++i)
    {
        board[i][0] = board[i - 1][0] + board[i - 1][1];
        board[i][1] = board[i - 1][0];
    }

    cout << board[N - 1][0] + board[N - 1][1] << '\n';
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