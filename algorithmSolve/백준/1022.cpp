#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Ǯ��.
// �����ϰ� ���Ƴ��� ������. �� ������ ūƲ�� ���ڸ� �̷��ϴ�.

// 1. ���� �ݽð�������� 1�� Ŀ����. �̸� ��� �ϳ��� ������Ű�� ���Ҽ��� �ְ�, �׸���� ���Ҽ��� �ִµ��ϴ�.
// 2. ���� ���� ���� ����ϵ�, ��� ���� ĭ�� �����ϰ� ����Ѵ�. ���� ��� 100�� 1�� �ִٸ� 1�� �տ� ��ĭ�� ��� ����Ѵ�.

// 1�� �κ��� �׸���δ� ���ε� ������ �����ϳ��� ������Ű��� �ߴ�. �ִ밪�� 5000������ ���ٰ��ص� ��� ����� ����
// (5000 * 2 + 1)�� �������� 1���� ���� �Ѱ� ������ �ð��ʰ����� �ɸ��� �ʴ´�.
// 2���� �ǿܷ� �����ѵ� ���� ū ���� ã�Ƽ� �� ���� ���ڸ������� ����Ͽ� ��� ���� ����Ҷ� �ڸ����� ���Ͽ�
// �׸�ŭ ������ ���� ����ϸ� �ȴ�. �ٸ� �̺κп��� �Ǽ��� �־ �� �ظ̴�.

// �ڼ��� ������ �ּ����� �����.

int r1, c1, r2, c2, iter, y = 5000, x = 5000, cur = 1, max_num = -1;
int from_y, from_x, to_y, to_x;
vector<vector<int>> board;

// ���� ��ǥ�� ��¹��������� Ȯ���ϴ� �Լ�.
bool Check(int y, int x)
{
    if ((from_y <= y && y <= to_y) && (from_x <= x && x <= to_x))
        return true;
    return false;
}

// �ݽð� �������� ���ư��� ��ǥ �� ���簪�� �����ϴ� �Լ�.
void RotateFunc()
{
    // ���۰� ���� �������� ������ Ȯ���ؾ��Ѵ�.
    if (Check(y, x))
    {
        board[y - from_y][x - from_x] = cur;
        max_num = max(max_num, cur);
    }

    int rot;
    for (int i = 1; i <= iter; ++i)
    {
        // ù��° ������
        ++x;
        ++cur;
        if (Check(y, x))
        {
            board[y - from_y][x - from_x] = cur;
            max_num = max(max_num, cur);
        }

        // ����
        rot = i * 2 - 1;
        for (int idx = 0; idx < rot; ++idx)
        {
            --y;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }

        // ����
        ++rot;
        for (int idx = 0; idx < rot; ++idx)
        {
            --x;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }

        // �Ʒ���
        for (int idx = 0; idx < rot; ++idx)
        {
            ++y;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }

        // �ι�° ������
        for (int idx = 0; idx < rot; ++idx)
        {
            ++x;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }
    }
}

// int�� num�� �ڸ����� Ȯ���ϴ� �Լ�. ���⼭ ����� ���� �Ǽ��� �־��µ�
// while���� ���ǹ��� num > 10�̶�� �߾���. �׷��� 10, 100�� 10�� �������
// �ڸ����� 1�� �۾����� ���Ǿ�����. ;;
int CalLen(int num)
{
    int ans = 1;
    while (num >= 10)
    {
        num /= 10;
        ++ans;
    }

    return ans;
}

void MakeAnswer()
{
    // �ִ� ������� ���ƾ��ϳ� ����Ѵ�.
    iter = max({ abs(r1), abs(c1), abs(r2), abs(c2) });
    board.resize(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));
    from_y = 5000 + r1;
    from_x = 5000 + c1;
    to_y = 5000 + r2;
    to_x = 5000 + c2;
    // ���⼭ iter��ŭ ȸ���Ѵ�.
    RotateFunc();
    max_num = CalLen(max_num);
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            // ���簪�� �ִ밪�� �ڸ����� ���Ͽ� ���ڶ�ٸ� �������� �޲پ��ش�.
            int now = board[i][j];
            int len = CalLen(now);
            for (int iter = 0; iter < max_num - len; ++iter)
                cout << ' ';
            cout << now << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}