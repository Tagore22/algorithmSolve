#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// �ִ� 1000�ڸ��� �ش��ϴ� �� ������ �����ϴ� ������.
// �翬�� long long�� �������� �Ƶ��� ����� ������ string���� ������ �����Ͽ���.
// �ٸ� Ǯ�̸� ���� vector �ϳ��� �� ���� ǥ���Ͽ� Ǫ�� ���� �� ������.
// string�� �Ź� int -> string, string -> int���� ��ȯ�� �־ �׷��� ����.

// �ڼ��� ������ �ּ����� �����.

string board[4];
int N;

string PlusStr(string lhs, string rhs)
{
    // lhs�� �� ������ ���̱� ������ ������ ���̰� ª�ų� ����.
    // �׷��⿡ lhs�� ���̸� rhs�� �����ش�.
    while (lhs.size() != rhs.size())
    {
        lhs = "0" + lhs;
    }
    int plus = 0;
    string str = "";
    // �� ���ڸ����� ��ȸ�� �ϸ� �� �ڸ����� ���Ѵ�.
    for (int i = lhs.size() - 1; i >= 0; --i)
    {
        int cur = (lhs[i] - '0') + (rhs[i] - '0') + plus;
        plus = cur >= 10 ? 1 : 0;
        cur %= 10;
        str = to_string(cur) + str;
    }
    str = plus == 1 ? "1" + str : str;
    return str;
}

int main()
{
    cin >> N;
    board[1] = board[2] = "1";
    for (int i = 3; i <= N; ++i)
        board[i % 3] = PlusStr(board[(i - 2) % 3], board[(i - 1) % 3]);
    cout << board[N % 3] << '\n';
    return 0;
}