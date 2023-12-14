#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �ܼ��� ������ �Է¹޾� �������� K��°�� ū ���� ����ϸ� �Ǵ� ������.
// ó������ sort()�� �̿��ߴµ� ���� �����غ��� nth_element()�� �ξ� �� ������.
// ������ ���� ��Ծ�߰ڴ�.
// �ٸ�, nth_element()���� �����ؾ������� �ִµ� ������ �����ϴ� �������� ���κ� ��,
// end�κ��� �������� ������ ���� ������ nth_element�� �����̵Ǵµ� �ι�° ���� nth��
// ������ �ȴٴ� ���̴�. ���� ����� nth�� �������� ��� ���� �������� �����ϱ� �����̴�.

// �ڼ��� ������ �ּ����� �����.

int board[5000000];
int N, K;

void MakeAnswer()
{
    --K;
    // �Է¹��� ������ ����. ��Ȯ���� K - 1��° ���� �����Ѵ�.
    nth_element(board, board + K, board + N);
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