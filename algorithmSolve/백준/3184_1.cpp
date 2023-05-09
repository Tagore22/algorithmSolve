#include <iostream>

using namespace std;

// �ٽú��� �ܰ��� ���ϴ� ���� ���� ó������ �ʿ䰡 ������.
// ���� ������ �κп� ��� ��� ����� ������� ������ �����Ѵٰ� �����ִµ�,
// �̰��� �ٸ� ���� ���翡�� Ż�� ������ �ܰ����� �������� �ʴ´ٴ� ���̱� �����̴�.
// ���� �� Ǯ�̴� DFS�� ����ϴ� Ǯ���ε�, �ִ� 250 * 250 = 62500 ��ŭ�� DFS�� ���ȣ���Ҽ�
// �ֱ⿡ ��ƸԴ� �޸𸮰� BFSǮ���� 1.5�迡 ���Ѵ�.
// ���Ƚ���� �þ�� DFS���� BFS�� �� ���������ٴ� �� ��������.

char board[250][250];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int R, C, total_w = 0, total_s = 0, cur_w, cur_s;

void DFS(int y, int x)
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

        DFS(dy, dx);
    }
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] != '#')
            {
                cur_w = cur_s = 0;
                DFS(i, j);
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