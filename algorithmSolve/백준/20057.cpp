#include <iostream>

using namespace std;

// Ǯ��.
// ��Ʊ⺸�� ��ǥ�� �򰥸��� �ʾƾ� �ϴ� �ո��� ���� ��������.
// ������ ����̵��� ȸ���� �� ������ �� �κи� �� �˾�ä�� ���� Ǯ�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[500][500];
int rot[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} }; // ��, ��, ��, ��
int N, answer = 0;


// �������� �־��� ����̵��� �̵��� ���� ��ȭ�� �����ϴ� �Լ�. ��ǥ ������ ����ߴ�.
void MoveTornado(int y, int x, int dir)
{
    int ten = board[y][x] / 10;
    int seven = board[y][x] * 7 / 100;
    int five = board[y][x] / 20;
    int two = board[y][x] / 50;
    int one = board[y][x] / 100;

    if (dir == 0)
    {
        // 5%.
        if (x - 2 <= 0)
            answer += five;
        else
            board[y][x - 2] += five;
        board[y][x] -= five;

        // 10% ��.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += ten;
        else
            board[y - 1][x - 1] += ten;
        board[y][x] -= ten;

        // 10% �Ʒ�.
        if (y + 1 > N || x - 1 <= 0)
            answer += ten;
        else
            board[y + 1][x - 1] += ten;
        board[y][x] -= ten;

        // 2% ����.
        if (y - 2 <= 0)
            answer += two;
        else
            board[y - 2][x] += two;
        board[y][x] -= two;

        // 2% �Ʒ�.
        if (y + 2 > N)
            answer += two;
        else
            board[y + 2][x] += two;
        board[y][x] -= two;

        // 1% ����.
        if (y - 1 <= 0 || x + 1 > N)
            answer += one;
        else
            board[y - 1][x + 1] += one;
        board[y][x] -= one;

        // 1% �Ʒ�.
        if (y + 1 > N || x + 1 > N)
            answer += one;
        else
            board[y + 1][x + 1] += one;
        board[y][x] -= one;

        // 7% ��.
        if (y - 1 <= 0)
            answer += seven;
        else
            board[y - 1][x] += seven;
        board[y][x] -= seven;

        // 7% �Ʒ�.
        if (y + 1 > N)
            answer += seven;
        else
            board[y + 1][x] += seven;
        board[y][x] -= seven;

        // ������
        if (x - 1 <= 0)
            answer += board[y][x];
        else
            board[y][x - 1] += board[y][x];
        board[y][x] = 0;
    }

    if (dir == 1)
    {
        // 5%.
        if (y + 2 > N)
            answer += five;
        else
            board[y + 2][x] += five;
        board[y][x] -= five;

        // 10% ��.
        if (y + 1 > N || x - 1 <= 0)
            answer += ten;
        else
            board[y + 1][x - 1] += ten;
        board[y][x] -= ten;

        // 10% �Ʒ�.
        if (y + 1 > N || x + 1 > N)
            answer += ten;
        else
            board[y + 1][x + 1] += ten;
        board[y][x] -= ten;

        // 2% ����.
        if (x - 2 <= 0)
            answer += two;
        else
            board[y][x - 2] += two;
        board[y][x] -= two;

        // 2% �Ʒ�.
        if (x + 2 > N)
            answer += two;
        else
            board[y][x + 2] += two;
        board[y][x] -= two;

        // 1% ����.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += one;
        else
            board[y - 1][x - 1] += one;
        board[y][x] -= one;

        // 1% �Ʒ�.
        if (y - 1 <= 0 || x + 1 > N)
            answer += one;
        else
            board[y - 1][x + 1] += one;
        board[y][x] -= one;

        // 7% ��.
        if (x - 1 <= 0)
            answer += seven;
        else
            board[y][x - 1] += seven;
        board[y][x] -= seven;

        // 7% �Ʒ�.
        if (x + 1 > N)
            answer += seven;
        else
            board[y][x + 1] += seven;
        board[y][x] -= seven;

        // ������
        if (y + 1 > N)
            answer += board[y][x];
        else
            board[y + 1][x] += board[y][x];
        board[y][x] = 0;
    }

    if (dir == 2)
    {
        // 5%.
        if (x + 2 > N)
            answer += five;
        else
            board[y][x + 2] += five;
        board[y][x] -= five;

        // 10% ��.
        if (y - 1 <= 0 || x + 1 > N)
            answer += ten;
        else
            board[y - 1][x + 1] += ten;
        board[y][x] -= ten;

        // 10% �Ʒ�.
        if (y + 1 > N || x + 1 > N)
            answer += ten;
        else
            board[y + 1][x + 1] += ten;
        board[y][x] -= ten;

        // 2% ����.
        if (y - 2 <= 0)
            answer += two;
        else
            board[y - 2][x] += two;
        board[y][x] -= two;

        // 2% �Ʒ�.
        if (y + 2 > N)
            answer += two;
        else
            board[y + 2][x] += two;
        board[y][x] -= two;

        // 1% ����.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += one;
        else
            board[y - 1][x - 1] += one;
        board[y][x] -= one;

        // 1% �Ʒ�.
        if (y + 1 > N || x - 1 <= 0)
            answer += one;
        else
            board[y + 1][x - 1] += one;
        board[y][x] -= one;

        // 7% ��.
        if (y - 1 <= 0)
            answer += seven;
        else
            board[y - 1][x] += seven;
        board[y][x] -= seven;

        // 7% �Ʒ�.
        if (y + 1 > N)
            answer += seven;
        else
            board[y + 1][x] += seven;
        board[y][x] -= seven;

        // ������
        if (x + 1 > N)
            answer += board[y][x];
        else
            board[y][x + 1] += board[y][x];
        board[y][x] = 0;
    }

    if (dir == 3)
    {
        // 5%.
        if (y - 2 <= 0)
            answer += five;
        else
            board[y - 2][x] += five;
        board[y][x] -= five;

        // 10% ��.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += ten;
        else
            board[y - 1][x - 1] += ten;
        board[y][x] -= ten;

        // 10% �Ʒ�.
        if (y - 1 <= 0 || x + 1 > N)
            answer += ten;
        else
            board[y - 1][x + 1] += ten;
        board[y][x] -= ten;

        // 2% ����.
        if (x - 2 <= 0)
            answer += two;
        else
            board[y][x - 2] += two;
        board[y][x] -= two;

        // 2% �Ʒ�.
        if (x + 2 > N)
            answer += two;
        else
            board[y][x + 2] += two;
        board[y][x] -= two;

        // 1% ����.
        if (y + 1 > N || x - 1 <= 0)
            answer += one;
        else
            board[y + 1][x - 1] += one;
        board[y][x] -= one;

        // 1% �Ʒ�.
        if (y + 1 > N || x + 1 > N)
            answer += one;
        else
            board[y + 1][x + 1] += one;
        board[y][x] -= one;

        // 7% ��.
        if (x - 1 <= 0)
            answer += seven;
        else
            board[y][x - 1] += seven;
        board[y][x] -= seven;

        // 7% �Ʒ�.
        if (x + 1 > N)
            answer += seven;
        else
            board[y][x + 1] += seven;
        board[y][x] -= seven;

        // ������
        if (y - 1 <= 0)
            answer += board[y][x];
        else
            board[y - 1][x] += board[y][x];
        board[y][x] = 0;
    }
}

void MakeAnswer()
{
    // �־��� ������ ���� ����̵��� ��� �̵��ϰ� �̵� �� ���� ��ǥ�� 1, 1�̶�� �������� ����Ѵ�.
    pair<int, int> cur = make_pair(N / 2 + 1, N / 2 + 1);
    int idx = -1, dir, mul;

    // ����̵��� ��, ��, ��, �� ������� �����̱⿡ �� ������� �̵� ��ǥ�� ¥�� �ǰ�,
    // 2�� ���� �� + 1��ŭ �̵��Ѵ�. �̰��� �̿��ϸ� �ȴ�.
    while (true)
    {
        ++idx;
        dir = idx % 4;
        mul = idx / 2 + 1;
        for (int i = 0; i < mul; ++i)
        {
            int y = cur.first + rot[dir][0];
            int x = cur.second + rot[dir][1];

            MoveTornado(y, x, dir);

            cur = make_pair(y, x);
            if (cur == make_pair(1, 1))
            {
                cout << answer << '\n';
                return;
            }
        }
    }
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