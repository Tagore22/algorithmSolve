#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �����ϴ� ������ �� �Ｚ�̴�. ���� ������.

// ������ ��û �����ϰ� ���õǾ� �־ ��� ���⿡ �������������,
// ���� �ϳ��� ������ �����ϱ⸸ �ϸ� �Ǵ� ������.

//

int board[21][21];
int people[5];
bool check[21][21];
int N, answer = 987654321;

// �־��� ����� �� ���ű��� �ּ� ���̰��� ���ϴ� ����.
void CalMax(int y, int x, int d1, int d2)
{
    // �� ���ű��� �ο���� �湮 ���θ� �ʱ�ȭ�Ѵ�.
    // �湮 ���δ� �Ŀ� ������ 5�� ���ű��� �ο����� �ľ��ϴµ� ���ȴ�.
    memset(people, 0, sizeof(people));
    memset(check, false, sizeof(check));
    int dy, dx, cur_row = 1;
    int cur_y = y, cur_x = x;

    // 1�� ���ű��� �迭���� �»�ܺ��� ���ϴ� �������� �ľ��Ѵ�.
    // ���� ��� 1������ N��, 2������ N-1�� ���...
    // ���� cur_row�� ���� ���ϰ����ϴ� ���� ��ġ�� �����Ѵ�.
    for (int i = 0; i <= d1; ++i)
    {
        dy = cur_y + i;
        dx = cur_x - i;

        // ���� ���ϰ��� �ϴ� ����� ��ȸ�� �Ѵ�.
        for (; cur_row < dy; ++cur_row)
            for (int c = 1; c <= dx; ++c)
            {
                people[0] += board[cur_row][c];
                // 1�� ���ű��� �ο����� ��� �湮�Ͽ���.
                check[cur_row][c] = true;
            }
    }

    // ���⼭ cur_row�� ���� �����Ѵ�.
    cur_row = 1;

    // 2�� ���ű��� �ο��� ���� �»�ܿ��� ���ϴ����� ��ȸ�ϸ� ���Ѵ�.
    for (int i = 1; i <= d2 + 1; ++i)
    {
        dy = cur_y + i;
        dx = cur_x + i;

        for (; cur_row < dy; ++cur_row)
            for (int c = dx; c <= N; ++c)
            {
                people[1] += board[cur_row][c];
                check[cur_row][c] = true;
            }
    }

    // �������� �ٲ��. (����� ���� ���� ��ǥ)
    // 3�� ���ű����� ���ϴ� ������ �޶�����. ���ʿ��� ���������� ��ȸ�� �ƴ�
    // ������ �Ʒ��� ��ȸ�� �ϸ� ���ʿ��� ���������� �̵��Ѵ�.
    // �����ϴ� ���� ���� ��ġ�� ���ϴ� cur_row�� �ƴ� ���� ��ġ�� ���ϴ�
    // cur_col�� �ٲ��.
    cur_y = y + d1;
    cur_x = x - d1;
    int cur_col = 1;

    for (int i = 0; i <= d2; ++i)
    {
        dy = cur_y + i;
        dx = cur_x + i;

        // ����ó�� ��ȸ�� ���� ������ ���°� �ƴ� ����� ����.
        // �迭���� �״������ ���� ����. 
        // ���⼭ �򰥷��� 5���� ���ȴ�.
        for (; cur_col < dx; ++cur_col)
            for (int r = dy; r <= N; ++r)
            {
                people[2] += board[r][cur_col];
                check[r][cur_col] = true;
            }
    }

    // ���������� �������� �ٲ�� ��ȸ ������ ������ �Ʒ��δ� �״������
    // �����ʿ��� �������� �ٲ��.
    cur_y = y + d2;
    cur_x = x + d2;
    cur_col = N;
    for (int i = 1; i <= d1 + 1; ++i)
    {
        dy = cur_y + i;
        dx = cur_x - i;

        // ���������� ���� ���� ��ȸ�ϵ� �迭���� �״�δ�.
        // ex) ù for���� j������ ��ǥ���� board[i][j];
        for (; cur_col > dx; --cur_col)
            for (int r = dy; r <= N; ++r)
            {
                people[3] += board[r][cur_col];
                check[r][cur_col] = true;
            }
    }

    // ���� �湮���� ���� (������ ����) ��� ������ 5�� ���ű��̹Ƿ�
    // ���⼭ ��� �����ش�.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (!check[i][j])
                people[4] += board[i][j];

    int cur_max = -1;
    int cur_min = 987654321;

    // �������� ����.
    for (int i = 0; i < 5; ++i)
    {
        cur_max = max(people[i], cur_max);
        cur_min = min(people[i], cur_min);
    }

    answer = min(answer, cur_max - cur_min);
}

void CalPosition()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int f = 1; j - f >= 1; ++f)
                for (int s = 1; i + f + s <= N && j + s <= N; ++s)
                    CalMax(i, j, f, s);
}

void MakeAnswer()
{
    CalPosition();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}