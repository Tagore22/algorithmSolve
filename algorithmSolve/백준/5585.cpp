#include <iostream>

using namespace std;

// Ǯ��.
// ���� ���� �ż��� �Ž������� ����ٴ°� �ִ��� ū ���� ���� ����Ѵٴ� ���̴�.
// �� ���� ū ������� ������������ �������� �� ��Ȳ���� ������ �ִ� ���� ���� �ż��� ������� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[6] = { 500, 100, 50, 10, 5, 1 };
int money;

void MakeAnswer()
{
    // ���� �����ؾ��� �ݾװ� ������ 1000���� �̿���
    // �Ž������� ���Ѵ�.
    cin >> money;
    money = 1000 - money;
    int answer = 0;

    // ��� ���� ������������ ��ȸ�ϵ�, �� ��Ȳ���� ������ �ִ� ���� ū����
    // �������.
    for (int i = 0; i < 6; ++i)
    {
        int cur = money / board[i];
        answer += cur;
        money -= cur * board[i];
    }
    cout << answer << '\n';
}

int main()
{
    MakeAnswer();
    return 0;
}