#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �ùķ��̼� �����̴�. �־������ ������ �ϸ� �ȴ�.
// �ٸ� �� ���� Ǯ�̰� �ִµ� ������ ������ �̿��ϴ� ���̴�.


// 1. N�� 1�϶����� �״�� ����Ѵ�.
// 2. N�� ¦���϶��� ��� ĭ�� 'O'���� ä���� ����Ѵ�.
// 3. N�� Ȧ���̵�, 4�� ���������� �������� 3�� ���� 1�� ���� ������.

// �̷��� �ϸ� �� ���� Ǯ�� �ִµ��ϴ�.

// �ڼ��� ������ �ּ����� �����.

char board[200][200];
queue<pair<int, int>> que;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int R, C, N;

// ¦������ ��� ���ο� ��ź�� ä��鼭 ���� ��ź�� ��ġ�� �ľ��Ѵ�.
void FillBomb()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] == '.')
                board[i][j] = 'O';
            else
                que.push(make_pair(i, j));
        }
}

// Ȧ������ ��� ���� ��ź�� �Ͷ߸���.
void Explo()
{
    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= R || dx < 0 || dx >= C)
                continue;

            board[dy][dx] = '.';
        }
        board[y][x] = '.';
    }
}

void MakeAnswer()
{
    int time = 1;
    while (time < N)
    {
        ++time;
        if (time % 2 == 1)
            Explo();
        else
            FillBomb();
    }
    // ���⼭ �迭 ���.
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            cout << board[i][j];
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> N;
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