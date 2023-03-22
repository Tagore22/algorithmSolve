#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ����� �ùķ��̼� �����̴�. �־����� ������ 

// 1. ������ Ȯ��.
// 2. ����û������ �ൿ.

// �� �ѻ��̰� ���� �������� �ʱ⿡ ������ ����� �ʴ�.

int board[50][50], temp[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int R, C, T, air; // ����û������ �Ʒ��κ�.


// ������ Ȯ��Ǵ� �Լ�. �ٸ� ���� �迭���� Ȯ��Ǹ� ���� ��ǥ�� Ȯ����� ���� ���̱� ������
// �ٸ� ��ü�� �迭�� Ȯ�갪�� ���Ƴ��� Ȯ���� ������ ���� �迭���� ���ؼ� ���ο� ������ �����ؾ��Ѵ�.
void RenewDust(int y, int x)
{
    int dy, dx, move_num = 0;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || (dy == air - 1 && dx == 0) ||
            (dy == air && dx == 0))
            continue;

        ++move_num;
        // Ȯ�갪�� ��ü�� �迭�� ���������Ѵ�.
        temp[dy][dx] += board[y][x] / 5;
    }
    board[y][x] -= board[y][x] / 5 * move_num;
}


// ��� �迭�� Ȯ���� ������ �Լ�.
void SpreadDust()
{
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] != 0)
                RenewDust(i, j);

    // �� ��ü�� �迭�� �־��� Ȯ��� ������� ���� �迭�� �پ�� �������� ���� 
    // ���ο� ���������� �����Ѵ�.
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            board[i][j] += temp[i][j];
}

// �ݽð� �������� ���� �Լ�.
void MoveCounter()
{
    int y = air - 2;
    int x = 0;
    while (y > 0)
    {
        board[y][x] = board[y - 1][x];
        --y;
    }

    while (x < C - 1)
    {
        board[y][x] = board[y][x + 1];
        ++x;
    }

    while (y < air - 1)
    {
        board[y][x] = board[y + 1][x];
        ++y;
    }

    while (x > 1)
    {
        board[y][x] = board[y][x - 1];
        --x;
    }

    board[y][x] = 0;
}

// �ð� �������� ���� �Լ�.
void MoveClock()
{
    int y = air + 1;
    int x = 0;
    while (y < R - 1)
    {
        board[y][x] = board[y + 1][x];
        ++y;
    }

    while (x < C - 1)
    {
        board[y][x] = board[y][x + 1];
        ++x;
    }

    while (y > air)
    {
        board[y][x] = board[y - 1][x];
        --y;
    }

    while (x > 1)
    {
        board[y][x] = board[y][x - 1];
        --x;
    }

    board[y][x] = 0;
}

// �������� ���ϴ� �Լ�. �̹� ������ ��� �Լ����� ����Ͽ�
// �ùķ��̼��� �����Ѵ�.
void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        SpreadDust();
        MoveCounter();
        MoveClock();
    }

    int answer = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            answer += board[i][j];

    // ����û���Ⱑ ���� -1, -1�� ������ �ֱ⿡ 2�� �����ش�.
    cout << answer + 2 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
                air = i;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}