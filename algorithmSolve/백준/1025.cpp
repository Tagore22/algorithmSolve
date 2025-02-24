#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// Ǯ��.
// ������ Ǯ�̰� �������� �ʾ� �Ѱ�� �����ε� ������ Ʋ�� ���� ���Ʈ���� �˰��� ���Ҵ�. 
// � ��ǥ (y, x)���� ���������� y, x���� ������ �ִ� 9�ڸ��� ���� ���鶧 ���� ū ���� �������� ���ؾ� �ϴµ�
// BFS�� �̿��Ͽ� Ǯ����. ó������ 8�������� ���ư��� ������ ®�µ� �ٽ� ���캸�� ���η� ��ĭ ���η� 2ĭ�� 
// �����̴� ��쵵 �־��⿡ ����� �� Ǯ�̰� �ƴϾ���. ��������� (-N, -M) ~ (N, M)���� ��� ��츦 ���� 2�� for������ 
// ť�� �־� ��ȸ�� �Ͽ���. �� �κе� ó������ ��ȸ���� �Ƴ��ٰ� -N ~ N - 1���� ������ �����ߴµ� 
// 1, 1, 4�� ��� int i = 0; i < 0�̱� ������ �ƿ� ť�� �ƹ��͵� ���� �ʾ� ����� �� ������
// ������ �ʾҴ�. �ļ��Ѵ�� �������� �÷� ������ �����. N, M���� �ſ� �۾Ƽ� BFS�� Ǯ�� �־���.

// �ڼ��� ������ �ּ����� �����.

// ť�� �� ����� ���� Ÿ��.
// ���� ���� y��ǥ, x��ǥ, �����ϴ� y��, �����ϴ� x��, ���� ���̴�.
struct pos
{
    int y; 
    int x;
    int plus_y;
    int plus_x;
    int num;
};

int board[9][9];
int N, M, answer = -1;

void BFS(int y, int x)
{
    queue<pos> que;
    for (int i = -N; i <= N; ++i)
        for (int j = -M; j <= M; ++j)
        {
            // ���ο� ���� ��� 0��ŭ �����Ѵٸ� ���ѷ����� �Ͼ�⿡ �����ؾ��Ѵ�.
            if (i == 0 && j == 0)
                continue;
            que.push(pos{ y, x, i, j, board[y][x] });
        }

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        int plus_y = que.front().plus_y;
        int plus_x = que.front().plus_x;
        int num = que.front().num;
        que.pop();
        int sqrt_num = sqrt(num);

        // ���� ���� ���� ��������� ������ answer�� ���Ѵ�.
        if (sqrt_num * sqrt_num == num)
            answer = max(answer, num);

        int ny = y + plus_y;
        int nx = x + plus_x;

        // �������� ����ٸ� �����ϰ� �׷��� �ʴٸ� ť�� �ִ´�.
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        que.push(pos{ ny, nx, plus_y, plus_x, num * 10 + board[ny][nx] });
    }
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            BFS(i, j);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
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