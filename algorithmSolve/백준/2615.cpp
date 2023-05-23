#include <iostream>

using namespace std;

// Ǯ��.
// ù��°�� ������ �߸��ð�, �ι�°�� �׷� ���� ���� �߸� Ǯ���� �����̴�.
// ������ ���� �򰥸��� �����Ǿ��µ� �׷��� �׷��� ũ�� ����� ������ ������� 20���ε� �ȵȴ�.
// �� ������ ū Ʋ�� ���ڸ� ������ ����.

// 1. �� ĭ�� 0, 1, 2�� �����ϴµ� 0�� ����̰� 1�� 1�� �÷��̾�, 2�� 2�� �÷��̾��̴�.
// 2. ����, ����, �밢������ 5���� �������� ���Ҵٸ� �� �÷��̾ �¸��Ѵ�.
// 3. �ٸ� �������� 6�� �̻����� �ξ��ٸ� �װ��� �¸��� ������ �ʴ´�.
// 4. �ƹ��� �̱��� ���ߴٸ� 0��, ������ �̰�ٸ� �� �÷��̾��� ��ȣ�� ���� ���� ��ǥ���� �Բ� ����ϵ�,
// ���η� 5���� ���Ҵٸ� ���� ���� ��ǥ���� ����Ѵ�.

// ���� ���� ���� 0 ~ 19 �� ��� ��ȸ�ϸ� ����, ����, �밢������ 5���� �������� ������ �ִٸ�
// �� �������� �÷��̾ ����ϰԲ� Ǯ���µ� ���⼭ ������ �Ѱ��� �߻��ߴ�.
// ������ �����Ͽ����� ������ �� 4������. ������, �Ʒ���, ������ �Ʒ�, ���� �Ʒ�.
// ���⼭ ���� �Ʒ��� ��������. ���η� ���������� �����ϰ�� ���� ���� ��ǥ���� ����ؾ� �ϴµ�
// ���� �Ʒ��� ���� ������ �ƴ� ���� �������� ��ǥ���̱� �����̴�.
// �̰� �ϳ� ������ ������ ��̴� T^T.

// ������ ��������. ���� ������ �̻��Ҷ��� �ִ�.

// �ڼ��� ������ �ּ����� �����.

const int MAX_NUM = 20;
int board[MAX_NUM][MAX_NUM];

bool Check(int y, int x, int num)
{
    // ����
    bool isfind = true;
    // �켱 ���� ���������� 5���� �������� ������ �ִ��� Ȯ���Ѵ�.
    for (int i = 1; i <= 4; ++i)
        if (x + i >= MAX_NUM || board[y][x + i] != num)
        {
            isfind = false;
            break;
        }
    // �������� 5���� �������� �������� �������� �� �ڷ� �Ѱ��� �� ã�ƺ���.
    // ���� �� Ȥ�� �ڷε� ���������� �ʾ� ������ 5���� ���������� �������ִٸ� �ٷ� �̰��� �����̴�.
    if (isfind)
        if (((x - 1 >= 0 && board[y][x - 1] != num) || x - 1 < 0) &&
            ((x + 5 < MAX_NUM && board[y][x + 5] != num) || x + 5 >= MAX_NUM))
            return isfind;

    // ����
    isfind = true;
    for (int i = 1; i <= 4; ++i)
        if (y + i >= MAX_NUM || board[y + i][x] != num)
        {
            isfind = false;
            break;
        }
    if (isfind)
        if (((y - 1 >= 0 && board[y - 1][x] != num) || y - 1 < 0) &&
            ((y + 5 < MAX_NUM && board[y + 5][x] != num) || y + 5 >= MAX_NUM))
            return isfind;

    // ������ �Ʒ� �밢��
    isfind = true;
    for (int i = 1; i <= 4; ++i)
        if (x + i >= MAX_NUM || y + i >= MAX_NUM || board[y + i][x + i] != num)
        {
            isfind = false;
            break;
        }
    if (isfind)
        if (((x - 1 >= 0 && y - 1 >= 0 && board[y - 1][x - 1] != num) || x - 1 < 0 || y - 1 < 0) &&
            ((x + 5 < MAX_NUM && y + 5 < MAX_NUM && board[y + 5][x + 5] != num) || x + 5 >= MAX_NUM || y + 5 >= MAX_NUM))
            return isfind;

    //  ������ �� �밢��
    isfind = true;
    // �������� ���� �Ʒ��� �������ִ� �κ�. ���� �Ʒ��� ���� �������� ���� ���� �κ��� �ƴ� ���� �����ʺκ��̱⿡
    // ������ �ɼ� ����. ���⸦ ���� ���� ��̴�.
    for (int i = 1; i <= 4; ++i)
        if (x + i < 0 || y - i >= MAX_NUM || board[y - i][x + i] != num)
        {
            isfind = false;
            break;
        }
    if (isfind)
        if (((x - 1 < MAX_NUM && y + 1 >= 0 && board[y + 1][x - 1] != num) || x - 1 >= MAX_NUM || y + 1 < 0) &&
            ((x + 5 >= 0 && y - 5 < MAX_NUM && board[y - 5][x + 5] != num) || x + 5 < 0 || y - 5 >= MAX_NUM))
            return isfind;
    return false;
}

void MakeAnswer()
{
    for (int i = 1; i < MAX_NUM; ++i)
        for (int j = 1; j < MAX_NUM; ++j)
            if (board[i][j] != 0)
                if (Check(i, j, board[i][j]))
                {
                    cout << board[i][j] << '\n';
                    cout << i << ' ' << j << '\n';
                    return;
                }
    cout << 0 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < MAX_NUM; ++i)
        for (int j = 1; j < MAX_NUM; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}