#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// 5x5ĭ�� �� ĭ�� ���ڰ� �ϳ��� �ְ� �����ϰ� 25���� ���� �����Ҷ� ���° ������ 3��° ���� ������� ã�� ������.
// 2������ ����߾��µ�

// 1. ���� Ȯ���ϴ� ���. � ĭ�� �־����� �� ĭ������ ã���� Ȥ�� �׷��� ���� �Ź� ��� ĭ�� ã�ƺ�����
// 2. � ĭ������ Ȯ���Ѵٸ� �밢���� ��� Ȯ���ϴ°�

// 1���� �ƹ������� ���ڰ� ���Ҵ�. �Ź� ��� ĭ�� Ȯ���ϴ� ���� �ܼ� 25�� ��ȸ�� �ƴ� ���� ���� �밢���� ��� Ȯ���غ����ϱ� �����̴�.
// �ٸ� 2���� �ɷȴµ� �»�ܿ��� ���ϴ��� �밢���� ��ǥ y, x���� y == x �϶��� Ȯ�������� ���ϴܿ��� ���������� �밢����
// � ĭ���� �������� Ȯ���� ���ǹ��� �������� �ʾҴ�. �ǿܷ� ���� �����ߴµ� y + x�� 4�϶�����. 

// �������� �ִ� 25���� ĭ�� ��ȸ�ϸ� ����� ĭ�� ã�� �� ĭ�� �湮 ǥ�÷� �������� ���� ���� ����� ã�ư��鼭
// 3��° ���� ��Ÿ������ ���° �������� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[5][5], nums[25];
bool visit[5][5];
int bingo = 0;

// ���� ��ǥ y, x�� �־������� �� ĭ���κ��� Ȯ���Ҽ� �ִ� ������ ���� Ȯ���ϴ� �Լ�.
void CheckBingo(int y, int x)
{
    // �»�ܿ��� ���ϴ������� �밢�� 
    if (y == x)
    {
        bool isFind = true;
        for (int i = 0; i < 5; ++i)
        {
            if (!visit[i][i])
            {
                isFind = false;
                break;
            }
        }
        bingo = isFind ? bingo + 1 : bingo;
    }
    // ���ϴܿ��� ���������� �밢��
    // ���� y + x == 4�϶��� ���ϴܿ��� ���������� 5ĭ¥�� �밢���� ����� �ִ�.
    if (y + x == 4)
    {
        bool isFind = true;
        for (int i = 0; i < 5; ++i)
        {
            if (!visit[4 - i][i])
            {
                isFind = false;
                break;
            }
        }
        bingo = isFind ? bingo + 1 : bingo;
    }

    // ���� �� ����.
    bool isFindCol = true;
    bool isFindRow = true;
    for (int i = 0; i < 5; ++i)
    {
        if (!visit[y][i])
            isFindRow = false;
        if (!visit[i][x])
            isFindCol = false;
    }
    bingo = isFindCol ? bingo + 1 : bingo;
    bingo = isFindRow ? bingo + 1 : bingo;
}

// �־��� ��ȣ�� �湮 ǥ�ø� �����ϰ� ���� ��� ���� �����ϴ��� Ȯ���Ѵ�.
void CheckPoint(int num)
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            if (board[i][j] == num)
            {
                visit[i][j] = true;
                CheckBingo(i, j);
                return;
            }
        }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    for (int iter = 0; iter < 25; ++iter)
    {
        // ���� �־��� ��ȣ�� �湮�ϰ� �����ϴ� ������ ������ Ȯ���Ѵ�.
        CheckPoint(nums[iter]);

        // ���� ���� 3�� �̻��̶�� ���° �������� ����ϰ� Ż���Ѵ�.
        if (bingo >= 3)
        {
            cout << iter + 1 << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];

    for (int i = 0; i < 25; ++i)
        cin >> nums[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}