#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �׷��� �̷��� �̿��� �����̴�. �� ������ Ʋ�� ũ�� ����غ��ڸ�

// 1. ���� ���¿��� �Ͼ�� �ִ� ��� ���⸦ ����Ų��. �ٸ� ���Ͽ� �������� ���Ⱑ �Ͼ�� 1������ ģ��.
// 2. ����� ���� �� ����� �����Ҽ� �ִµ� �װ��� �߷¿� ���� �޲پ� �ִ� ���� ���̻� �޲ܰ��� ������
//    ���� �ݺ��Ѵ�.(�ֺ� ������ �ѿ䰡 �����Ѵٸ� �װͰ� ��ü)

// �̰��� ���̻� ���Ⱑ �������� ���������� �ݺ����ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

char board[12][6];
bool visit[12][6];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int path;

// ���Ⱑ �����ϴ��� Ȯ���ϴ� DFS�Լ�. path�� ���� �÷����� Ȯ���Ѵ�.
void DFS(int y, int x)
{
    visit[y][x] = true;

    ++path;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= 12 || dx < 0 || dx >= 6 || board[dy][dx] != board[y][x] || visit[dy][dx])
            continue;

        DFS(dy, dx);
    }
}

// ����� ���� �ѿ並 �ֺ�� �ϴ� �Լ�. �ѿ䰪�� ���ϱ� ������ char ���� c�� �߰��Ͽ� 
// ���� ��ǥ�� ã�µ� ����Ͽ����Ѵ�.
void Erase(int y, int x, char c)
{
    board[y][x] = '.';

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= 12 || dx < 0 || dx >= 6 || board[dy][dx] != c)
            continue;

        Erase(dy, dx, c);
    }
}

// �̹� �Ͽ� ���Ⱑ �����ϴ��� Ȯ���ϴ� �Լ�.
bool IsBomb()
{
    memset(visit, false, sizeof(visit));

    bool isbomb = false;
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 6; ++j)
            if (board[i][j] != '.' && !visit[i][j])
            {
                path = 0;
                DFS(i, j, board[i][j]);
                if (path >= 4)
                {
                    isbomb = true;
                    Erase(i, j, board[i][j]);
                }
            }
    return isbomb;
}

// ����� ���� �ֺ� ���� �ٷ� �� �ѿ�� �޲ٴ� �Լ�.
// ���̻� �޲ܰ� ���������� �ݺ��ؾ��Ѵ�.
bool GetDown()
{
    bool ischange = false;
    for (int i = 11; i > 0; --i)
        for (int j = 0; j < 6; ++j)
            if (board[i - 1][j] != '.' && board[i][j] == '.')
            {
                ischange = true;
                swap(board[i - 1][j], board[i][j]);
            }
    return ischange;
}

void MakeAnswer()
{
    int answer = 0;
    while (true)
    {
        if (IsBomb())
            ++answer;
        else
            break;

        bool ischange;
        while (true)
        {
            ischange = GetDown();
            if (!ischange)
                break;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    for (int i = 0; i < 12; ++i)
    {
        cin >> str;
        for (int j = 0; j < 6; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}