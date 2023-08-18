#include <iostream>

using namespace std;

// Ǯ��.
// ����� ���� ������. �ٸ� �Ѱ��� �����ؾ������� �ִµ�
// �ٸ� ��� ������ ���� �ѹ����ۿ� �������� 6, 9�� ����� ��ü������ ���� �ִٴ� ���̴�.
// ���� ���� �Է¹����� ó������ ������ ��ȸ�ϸ� ������ ������ ���� �����ϵ�, 6�� 9�� ���ļ� 2�� ��������
// ��ü�Ͽ� ���� ū ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

string str;
int board[10];

void MakeAnswer()
{
    // ó������ ������ ��ȸ�ϸ� ������ ���� �����Ѵ�.
    for (int i = 0; i < str.size(); ++i)
        ++board[str[i] - '0'];

    int ans = 0;
    // 0 ~ 9�߿��� 6�� 9�� ������ ������ ������ ����Ƚ���� �ִ���� ���Ѵ�.
    for (int i = 0; i < 9; ++i)
        if (i != 6)
            ans = max(ans, board[i]);

    // 6�� 9�� ����Ƚ���� ���� 2�� ������, �������� �����Ѵٸ� ������Ų��. ex) 3���� ���� 2�� ���������� 1������ 
    // �����δ� 2���� �ʿ��ϴ�.
    int sixornine = (board[6] + board[9]) / 2;
    if (sixornine * 2 != board[6] + board[9])
        ++sixornine;

    // 6�� 9�� ����Ƚ���� ���� �ִ� ����Ƚ���� �ִ밪�� ����Ѵ�.
    ans = max(ans, sixornine);
    cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}