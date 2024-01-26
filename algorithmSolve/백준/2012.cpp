#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Ǯ��.
// �־��� ������� �������� ������������ �����Ͽ� ���� ����� ���Ѵ�.
// �� ���̰����� ��� ���Ͽ� ����ϸ� �ȴ�. �Ѱ��� ������ �κ��� �ִµ�
// �ִ� ����� 50������ ��� �ο����� �ڽ��� ���� ������ 50������ ���� ���ٸ�
// �ο��� �� 50�����϶� 0 ~ 499999�� ���ؾ��ؼ� int���� �����.
// ���� ������ answer�� Ÿ���� long long �̿��� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[500001];
int N;

void MakeAnswer()
{
    // ���̰��� �ּ������� �ϱ� ���� ���� ������ �������� �������� ����.
    sort(board, board + N);
    // ����Ѵ�� ������ answer�� Ÿ���� long long �̿��� �Ѵ�.
    long long answer = 0;
    // ���̰��� ��� ���� ����Ѵ�.
    for (int i = 0; i < N; ++i)
        answer += abs(i - board[i] + 1);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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