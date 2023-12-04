#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// -2������ ����� �����̴�. ����� 2������ �ٸ����� 2�� -2�������� ���鶧�� ���� �˼� �ִµ�
// �������� -1�� ������ ��찡 �ִ�. �� �� -2������ 110���� �����غ��� �˼� �ְ�����
// �������� -1�� ���, �������� ������ 1�� ������ ���簪�� -1���� ���밪�� �÷��ָ�
// ��Ȯ�ϰ� Ǯ����.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int N;

void MakeAnswer()
{
    // 0�� -2�������� ���� ����� ����.
    if (N == 0)
    {
        cout << 0 << '\n';
        return;
    }
    // N�� ������ �����ϱ⿡ 0���� ū���� �ϸ� �ȵȴ�.
    while (N != 0)
    {
        int result = N % -2;
        // N�� -2�� ���� �������� 0�̶�� �������.
        if (result == 0)
        {
            board.push_back(0);
            N /= -2;
        }
        // -2�� ���� ����� 0�� �ƴ϶�� ������ ���������� 1�� �ٲٰ�
        // N�� 1 ���ҽ�Ų�� -2�� ������.
        else
        {
            board.push_back(1);
            N = (N - 1) / -2;
        }
    }
    for (int i = board.size() - 1; i >= 0; --i)
        cout << board[i];
    cout << '\n';
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