#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �־��� ������ �����Ͽ� K��°�� ū ���� ����ϴ� ������.
// sort()�� ����Ͽ� ��ü�� ������ K��° ���� ����ص� �ǳ� nth_element()�� �̿��Ͽ� K��° ��������
// �����Ͽ� ����ϴ� ���� �� ������ ������ nth_element()�� ����Ͽ���.

// �ڼ��� ������ �ּ����� �����.

int board[1000];
int N, K;

void MakeAnswer()
{
    --K;
    // K��° �������� ����.
    nth_element(board, board + K, board + N, greater<>());
    cout << board[K] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}