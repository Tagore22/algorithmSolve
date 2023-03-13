#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �����Ұ� ���� �����̴�. �׷��� Ǯ�� ����� ���� ����� �ʴ�.

// 1. ���� ������ �������� ���Ѵ�.
// 1-1. ���� 2�� �̻��̶�� ������ �ϼ���(�ʱⰪ�� 0) ����Ѵ�.
// 1-2. ���� 0����� 0�� ����Ѵ�.
// 1-3. ������ 1����� �� �������� �Ѿ��.
// 2. 1���� ������ ������ ��ȭ�� �����(��´�). �� ��ȭ�� ������ �Լ��� ȣ���Ͽ� ������ ���̰����� �����ϰ� �ٽ� 
// �������� ���Ѵ�.
// 3. �ݺ�.

// �� �Լ����� �ּ��� �����Ұ�.

int board[300][300], temp[300][300];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
bool check[300][300];
int N, M;

// ������ �������� ã�� ���� �ʿ��� DFS�Լ�. �����¿�� �̵��ϸ� ������ ���̰� 1�̻��̸� ���� �湮���� ���� ��� ���� �湮�Ѵ�.
void DFS(int y, int x)
{
    check[y][x] = true;
    int dy, dx;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx] == 0 || check[dy][dx])
            continue;

        DFS(dy, dx);
    }
}

// ������ �������� ���ϴ� �Լ�. DFS�� ȣ��ɶ����� 1���� ���� ������ ������ �̿��Ͽ� ������ �������� ��ȯ�Ѵ�.
int CalIceberg()
{
    memset(check, false, sizeof(check));
    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0 && !check[i][j])
            {
                ++ans;
                DFS(i, j);
            }
    return ans;
}

// 1���� ���� ������ ��ȭ�ϴ� ���� �����ϴ� �Լ�. �迭�� ��ȸ�ϸ� �� ������ �����¿��� �ٴ幰�� ���� �� �ٸ� �迭 temp�� �����Ͽ��ٰ�
// �迭�� ��ȸ�� ������ �ٽ� ��ȸ�ϸ� board�� �����Ѵ�. ��ȸ >> ��ȸ >> ������ �ƴ� ��ȸ >> ���� >> ��ȸ�� ������ �߻��Ҽ� �ִ�.
// ���� ��� ������ �׸� 2���� (3, 1)�� �� 5�� ���� 1���� ���� 3�� �Ǿ�� ������ ��ȸ >> ���� >> ��ȸ�� �ϸ� ������ 1�� 0�� �Ǿ�
// ���� 5�� �����Ҷ� �ٴ幰�� ��ġ�� 2�� �ƴ� 3�� �Ǿ� 2�� �ȴ�. �׷��� ��ȸ >> ��ȸ >> ������ ������ �����ؾ� �Ѵ�.
void MinusHeight()
{
    int dy, dx, minus;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0)
            {
                minus = 0;
                for (int iter = 0; iter < 4; ++iter)
                {
                    dy = i + rot[iter][0];
                    dx = j + rot[iter][1];

                    if (dy < 0 || dy >= N || dx < 0 || dx >= M)
                        continue;

                    minus = board[dy][dx] == 0 ? minus + 1 : minus;
                }

                temp[i][j] = minus;
            }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0)
                board[i][j] = max(0, board[i][j] - temp[i][j]);
}

// �������� ���ϴ� �Լ�. ������ �� ����� �ٿ� ����.
void MakeAnswer()
{
    int time = 0, now;
    while (true)
    {
        // 1. �� ��Ȳ���� ������ �������� ���Ѵ�.
        now = CalIceberg();
        // 1-1. ������ ���� 2�� �̻��̶�� ���� �ð�(time)�� ����Ѵ�.
        if (now > 1)
        {
            cout << time << '\n';
            return;
        }
        // 1-2. ������ ���� 0����� 0�� ����Ѵ�.
        else if (now == 0)
        {
            cout << 0 << '\n';
            return;
        }
        // 1-3. ������ �Ѱ�(�� �̿ܰ��� 1�ۿ� ����)��� �������� �Ѿ��.
        // 2. 1���� ������(++time), ������ ��ȭ���� �����Ѵ�. �� �� �ݺ�.
        ++time;
        MinusHeight();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}