#include <iostream>

using namespace std;

//�ָԱ��������� Ǭ ����. �ִ밪�� �ʹ� Ŀ�� �ɱ� ���������� �پ��� �κе� ���Ƽ� �ѹ� �غ��Ҵ��� �¾Ҵ�.
//����� �� Ǯ�̴� 1261_1�� ã����.

//Ǯ��
//�Է¹޴� 2���� �迭�� ������ � ���� y, x���� �����ϱ� ���� �μ���� �ϴ� �ּ����� ������ �����ϴ� ������ �迭 walls�� ����
//�̵������� ��� �������� ��ȸ�ϸ� walls�� �����ϰ� �������� walls[N-1][M-1]�� ����Ѵ�.
//�� ����Ͽ����� ��ȸ�ϴ� ��� ����� ���� 4�� 10000�����̱⿡ �ʹ� ������ walls�� �����ϴ� ���ǹ����� �ϳ� ���� ����� ���� �پ���
//������ �ȰͰ���. �ð����⵵���� ���ϱ� ������ Ǯ��

int board[100][100];
int walls[100][100];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int M, N;
const int MAX_NUM = 987654321;

void CalAnswer(int y, int x)
{
    if (y == N - 1 && x == M - 1)
        return;

    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy < 0 || cy >= N || cx < 0 || cx >= M)
            continue;

        if (walls[y][x] + board[cy][cx] < walls[cy][cx])
        {
            walls[cy][cx] = walls[y][x] + board[cy][cx];
            CalAnswer(cy, cx);
        }
    }
}

void MakeAnswer()
{
    CalAnswer(0, 0);
    cout << walls[N - 1][M - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            walls[i][j] = MAX_NUM;
    walls[0][0] = 0;

    cin >> M >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}