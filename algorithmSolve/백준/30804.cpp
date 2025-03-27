#include <iostream>

using namespace std;

// Ǯ��.
// �������ʹ� 2���� ��쿡 ���δ�. ù°�� ������ ���Ҷ��̰�, ��°�� ���ĵ� ���¿����� �� ���̴�.
// �� �������� ù°�� ����. ������ from�� to�� ��� 0���� �����ϸ� ���������� 1ĭ�� �÷�����.
// �� ���� ������ �̹� ������ ���̰ų�, ���� ������ ���� ������ 1���϶��̴�. �׷��� �ʴٸ�
// from�� 1�� �÷� �������� �ٿ������� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[200000], counts[10];
int N, answer = -1;

void MakeAnswer()
{
    // ������ from�� to�� ��� 0���� �����ϸ� ������ ���� ������ num�� 1�� �����Ѵ�.
    int from = 0, to = 0, nums = 1;
    counts[board[from]] = 1;
    // from�� to���� Ŀ������ ���� ������, to�� N�� ���ų� Ŀ�������� �ݺ��Ѵ�.
    while (to < N)
    {
        // �����ʰ��� �̹� ������ ���̰ų�, ���� ������ ���� ������ 1���϶����� to�� 1 ��������
        // �������� �ø���.
        if (counts[board[to + 1]] >= 1 || nums < 2)
        {
            ++to;
            ++counts[board[to]];
            nums = counts[board[to]] == 1 ? nums + 1 : nums;
        }
        // �׷��� ���� ��� from�� 1 �������� �������� �ٿ�����.
        else
        {
            answer = max(answer, to - from + 1);
            --counts[board[from]];
            nums = counts[board[from]] == 0 ? nums - 1 : nums;
            ++from;
        }
    }
    // ���� ���� 1���� ������ �����ϸ� answer�� -1���� ������ �ʴ´�.
    answer = answer == -1 ? N : answer;
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