#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

// Ǯ��.
// �Ｚ ������� Ư���� ������ ������ �����ϰ� ���Ƴ��� ������.
// ħ���ϰ� �� Ǭ�� ����. ������ ūƲ�� ������ ����.

// 1. �迭�� 2�� Li���� * 2�� Li���� ũ��� ������.
// 2. ��� �κ� �迭�� �ð� �������� 90�� ȸ����Ų��.
// 3. ������ ������ �����ϴ� ĭ�� 2�� ���϶�� ������ ���� 1�� �پ���.
// 4. �̰��� Q�� ��ȸ������ ���� �ִ� ������ ���հ� ���� ū ����� ������ ����϶�.

// �ڼ��� ������ �ּ����� �����.

int board[64][64], temp[64][64];
int seq[1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int N, Q, len, div_num, ice_sum = 0, max_piece = 0;
bool ismelt[64][64];

// �κ� �迭�� ȸ����Ű�� �Լ�. �� y�� x���� ���۰��� ������ �ʿ��ϴ�.
void RotateBoard(int from_y, int to_y, int from_x, int to_x)
{
    for (int i = 0; i < div_num; ++i)
        for (int j = 0; j < div_num; ++j)
            temp[from_y + i][from_x + j] = board[to_y - j][from_x + i];
}

// ȸ���� ���� ���� �迭�� �ű�� �Լ�. ó���� swap()�� �̿��ؼ� �ұ
// ���������� �׷��� �ϳ��� ��ǥ���� ������ �ǵ帮�� ��찡 �־ �� �����ߴ�.
// ���� �뷮�� ���� �� �����ϴ��� �̰� ������ ���Ҵ�.
// ���� �迭 ��ü�� �ſ� ū���� �ƴ϶� �ӵ��� �׸� ���̳��� ���� ���̴�.
void ClearBoard()
{
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            board[i][j] = temp[i][j];
}

// ��� ��ǥ���� ������� �˻��ϴ� �Լ�. �̷л� �ִ� ���귮��
// 2�� 6����(64) * 2�� 6������ 4�������� 1600���� �������̴�.
// ������ �ɷ����� ���ǹ����� �ֱ� ������ �ð����� ����� �����ߴ�.
void CheckMelt()
{
    memset(ismelt, false, sizeof(ismelt));
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
        {
            if (board[i][j] == 0)
                continue;

            int num = 0;
            for (int iter = 0; iter < 4; ++iter)
            {
                int dy = i + rot[iter][0];
                int dx = j + rot[iter][1];

                if (dy < 0 || dy >= len || dx < 0 || dx >= len)
                    continue;

                if (board[dy][dx] > 0)
                    ++num;
            }
            if (num < 3)
                ismelt[i][j] = true;
        }

    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            if (ismelt[i][j])
                --board[i][j];
}

// �� ����� ũ��� �����ִ� ������ �ѷ��� ���ϴ� BFS�Լ�.
void FindBFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    ismelt[y][x] = true;
    ice_sum += board[y][x];
    int cur_piece = 1;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= len || dx < 0 || dx >= len || ismelt[dy][dx] || board[dy][dx] == 0)
                continue;

            que.push(make_pair(dy, dx));
            ismelt[dy][dx] = true;
            ice_sum += board[dy][dx];
            ++cur_piece;
        }
    }
    max_piece = max(max_piece, cur_piece);
}

// �迭�� ��ȸ�ϸ� BFS�� ȣ���ϴ� �Լ�.
void FindAnswer()
{
    memset(ismelt, false, sizeof(ismelt));
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            if (board[i][j] != 0 && !ismelt[i][j])
                FindBFS(i, j);
}

void MakeAnswer()
{
    // 1. �迭�� 2�� Li���� * 2�� Li���� ũ��� ������.
    // 2. ��� �κ� �迭�� �ð� �������� 90�� ȸ����Ų��.
    // 3. ������ ������ �����ϴ� ĭ�� 2�� ���϶�� ������ ���� 1�� �پ���.
    // 4. �̰��� Q�� ��ȸ������ ���� �ִ� ������ ���հ� ���� ū ����� ������ ����϶�.
    for (int iter = 0; iter < Q; ++iter)
    {
        // 1 ~ 2�� �ܰ�.
        div_num = pow(2, seq[iter]);
        for (int i = 0; i < len; i += div_num)
            for (int j = 0; j < len; j += div_num)
                RotateBoard(i, i + div_num - 1, j, j + div_num - 1);

        ClearBoard();
        // 3�� �ܰ�.
        CheckMelt();
    }
    // 4�� �ܰ�.
    FindAnswer();
    cout << ice_sum << '\n' << max_piece << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    len = pow(2, N);
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            cin >> board[i][j];

    for (int i = 0; i < Q; ++i)
        cin >> seq[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}