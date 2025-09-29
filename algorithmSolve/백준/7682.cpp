#include <iostream>

using namespace std;

// Ǯ��.
// ��ƴٱ⺸�ٴ� �����ߴ� ������. 3x3 ���ڹ迭�� �־��� �� �ùٸ� �迭�ΰ�
// Ȯ���ϴ� �����ε� �� ���ǵ��� ������ ����.

// 1. o�� x���� ���� �� ����. o�� �İ��̱� �����̴�.
// 2. x�� o���� �� �̻� ���� �� ����.
// 3. x�� o, �Ѵ� 3���� ���� �� ����. �� �� �ϳ��� ���� ��Ȳ���� ������ ������ �����̴�.
// 4. x�� 3���� ������� ��, o���� �Ѱ� ���ƾ� �Ѵ�.
// 5. o�� 3���� ������� ��, x�� ������ �����ؾ��Ѵ�.
// 6. �迭�� ��ĭ�� ����, x�� o ��� 3���� ������ ���ߴ�.

// �̷� ���ǵ��� �����ϸ� �ȴ�. ����Ͽ��� ������ ���Ƽ� �� ���ø��µ��� �ð��� �����.

// �ڼ��� ������ �ּ����� �����.

char board[3][3];
int xnum = 0, onum = 0;

void CheckTictacto()
{
    // ����� 1���� 2�� ����.
    // �� ���ǹ����� o�� �ϳ� ���ų�, o�� x�� ���� ��츸 ����µ�
    // ���ڸ� �����ؼ� �ļ��� ���뿡�� ��ƴ�� �����.
    if (onum > xnum || xnum > onum + 1)
    {
        cout << "invalid" << '\n';
        return;
    }

    int xans = 0, oans = 0;
    for (int i = 0; i < 3; ++i)
    {
        // ���� x�� o�� ���� Ȥ�� ���η� 3���� ���� ���.
        if ((board[i][0] == 'X' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == 'X' && board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            ++xans;

        if ((board[i][0] == 'O' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == 'O' && board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            ++oans;
    }

    // x�� o�� �밢������ 3���� ���� ���.
    if ((board[0][0] == 'X' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[2][0] == 'X' && board[2][0] == board[1][1] && board[1][1] == board[0][2]))
        ++xans;

    if ((board[0][0] == 'O' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[2][0] == 'O' && board[2][0] == board[1][1] && board[1][1] == board[0][2]))
        ++oans;

    // 3�� ����.
    if (xans > 1 && oans > 1)
    {
        cout << "invalid" << '\n';
        return;
    }

    // 4, 5, 6�� ����. �� �Լ��� if������ ����Ͽ��� 4�� ���ǿ� x�� o�� ������ ���� ������ �ִ�.
    // ó������ xnum == onum + 1�� �߰����� �ʾҾ��µ� if������ �˾Ƽ� �ɷ��� �Ŷ�� ������ ����� �����̴�.
    // ������ xnum == onum Ȥ�� xnum == onum + 1�� �ΰ��� ��찡 ����Ǵµ� �� �� ���ڴ� ����� �� ����
    // �� �� ��� Ʋ�� �����̴�. �׷��Ƿ� �ݵ�� xnum == onum + 1�� �߰����־�� �Ѵ�.
    if ((xans > 0 && oans == 0 && xnum == onum + 1) || (oans > 0 && xans == 0 && xnum == onum) || (xans + oans == 0 && xnum + onum == 9))
        cout << "valid" << '\n';
    else
        cout << "invalid" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        string str;
        cin >> str;
        if (str == "end")
            break;
        xnum = onum = 0;
        for (int i = 0; i < 9; ++i)
        {
            board[i / 3][i % 3] = str[i];
            if (str[i] == 'X')
                ++xnum;
            else if (str[i] == 'O')
                ++onum;
        }
        CheckTictacto();
    }
    return 0;
}