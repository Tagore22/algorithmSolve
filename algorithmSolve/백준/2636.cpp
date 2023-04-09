#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��. 
// ������ Ǯ� ġ�� ������ ����ϴ�. ��¼�� �ƿ� ��������;
// Ǫ�� ������ ������ ���� 3������ �ݺ��ϸ� �ȴ�.

// 1. ����� ġ� �и��Ѵ�. (DFS)
// 2. �迭�� ��ȸ�ϸ� � ��ǥ y, x�� ġ� ����� �´�� �ִ��� Ȯ���ϰ� ismelt ���� �����Ѵ�.
// 3. �ٽ� �迭�� ��ȸ�ϸ� ����� �´��� ġ���� ���� �����Ѵ�(1���� 0����)

// �ݺ��� �ִ��� ���̱� ���� ġ��� ��� ���� ġ��� ���� �����Ͽ� �� ������ �ø��� �ִ�.

int board[100][100];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
bool ismelt[100][100];
int R, C, cheese = 0; // ���� ġ���� ����.

// �迭�� ���� ����� ġ��� �и��ϴ� �Լ�. 1����Ŭ ���� �ٸ� �Լ���� ���������� �ݺ����־�� �Ѵ�.
void FindAirDFS(int y, int x)
{
    ismelt[y][x] = true;

    int dy, dx;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || ismelt[dy][dx] || board[dy][dx] != 0)
            continue;

        FindAirDFS(dy, dx);
    }
}

// y, x���� ġ� ����� �´�� �ִ��� Ȯ���ϴ� �Լ�. �´�� �ִٸ�
// ismelt ���� true�� �����Ͽ� �̹� ����Ŭ�� ���δ�.
void FindMelt(int y, int x)
{
    int dy, dx;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C)
            continue;

        if (ismelt[dy][dx] && board[dy][dx] == 0)
        {
            ismelt[y][x] = true;
            break;
        }
    }
}

void MakeAnswer()
{
    // ����Ŭ�� answer��, ���� ġ� prev.
    int answer = 0, prev = 0;
    while (cheese > 0)
    {
        memset(ismelt, false, sizeof(ismelt));
        FindAirDFS(0, 0);

        ++answer;
        prev = cheese;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (board[i][j] == 1)
                    FindMelt(i, j);

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (board[i][j] == 1 && ismelt[i][j])
                {
                    --cheese;
                    board[i][j] = 0;
                }
    }
    cout << answer << '\n';
    cout << prev << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                ++cheese;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}