#include <iostream>

using namespace std;

// Ǯ��.
// �������� �־��� ������ ������ ����.

// 1. ���翡�� Ż���Ҽ� �ִ� ���� �����Ѵ�. (�迭�� ���� �ܰ��� ����Ǿ� �ִ� ������ �����Ѵ�.)
// 2. ��� �������� ���� ���뺸�� ���ٸ� ������� �Ѱܳ���, �׷��� �ʴٸ� ���� ��Ƹ�����.

// �̶� ���翡 ��������� ���� ������ ����ϴ� �����̴�.
// �����Ұ��� 1�� �����ε�, �� ���� ��, ���� �ܰ�({0, 0}, {0, 1}��)���� �����Ҽ� �ִ� ��� ����
// ����� ������ ���� �ʴ´ٴ� ���̴�. �׷��⿡ ���� �ֽô��� �����ϱ����� �ش� �������� '#'ó���Ͽ�
// �Ŀ� ���� ����Ҷ� ���Խ�Ű�� �ʾҴ�.

// �ڼ��� ������ �ּ����� �����.

char board[250][250];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int R, C, total_w = 0, total_s = 0, cur_w, cur_s;

// ��ǥ���� ��ȸ�ϸ� ��Ÿ��ȭ('#')��Ű�� �Լ�.
void DFSZero(int y, int x)
{
    board[y][x] = '#';

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#')
            continue;

        DFSZero(dy, dx);
    }
}

// ����� 1�� ���ǿ� ���� �ܰ��� ����� (Ż�Ⱑ����) ������ ��Ÿ��ȭ('#') �����ִ� �Լ�.
void CheckZero()
{
    for (int iter = 0; iter < C; ++iter)
    {
        if (board[0][iter] == '.')
            DFSZero(0, iter);
        if (board[R - 1][iter] == '.')
            DFSZero(R - 1, iter);
    }

    for (int iter = 1; iter < R - 1; ++iter)
    {
        if (board[iter][0] == '.')
            DFSZero(iter, 0);
        if (board[iter][C - 1] == '.')
            DFSZero(iter, C - 1);
    }
}

// ��ǥ���� ��ȸ�ϸ� �����ȿ� ���밪�� ���� ���� ���ϴ� �Լ�. �̹� �湮�� ��ǥ�� ��Ÿ��ȭ�Ͽ�
// �ߺ��� �����Ѵ�.
void CalDFS(int y, int x)
{
    if (board[y][x] == 'o')
        ++cur_s;
    else if (board[y][x] == 'v')
        ++cur_w;
    board[y][x] = '#';

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#')
            continue;

        CalDFS(dy, dx);
    }
}

void MakeAnswer()
{
    CheckZero();

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] != '#')
            {
                cur_w = cur_s = 0;
                CalDFS(i, j);
                if (cur_w < cur_s)
                    total_s += cur_s;
                else
                    total_w += cur_w;
            }

    cout << total_s << ' ' << total_w << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}