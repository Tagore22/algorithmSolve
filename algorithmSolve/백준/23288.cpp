#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ������������ �������� ���� ������.
// �ϳ��ϳ� ���⿡ ����� ������ �������� ������ ����.
// �������� �־��� �ൿ ������ ������ ����.

// 1. ���� �־��� ������ �����δ�. �ٸ�, ������ ���������� �迭���� ����ٸ� ������ �ݴ�� �ٲپ� �̵��Ѵ�.
// 2. �̵��� ��ǥ�� y, x��� �Ҷ� ������������ �̵��ϸ� ���� y, x�� ���� ���ĭ N���� ã�´�.
// �� �� ��ǥ�� ���� K�� N�� ������ answer�� ���Ѵ�.
// 3. ��ǥ ���� K�� ���� �ֻ����� �Ʒ��� D�� ���Ͽ� 

// 3-1. K > D��� �ð� �������� ȸ���Ѵ�.
// 3-2. K < D��� �ð� �ݴ�������� ȸ���Ѵ�.
// 3-3. K == D ��, �� �̿ܿ��� ������ ������ ����.

// ������ ���� ��Ģ�� ���� ���� ������ �־����� �� ���Ĵ� 1, 2, 3���� K�� �ݺ��Ѵ�.

// �� ����Ͽ��� ����� ������ �����ؾ� �Ұ��� ����. ���Ÿ� �� ������ �ѹ��� Ǯ�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[20][20];
int dice[6] = { 3, 4, 5, 2, 1, 6 }; // ��â�� �ֻ���. ��, ��, ��, ��, ��, �Ʒ� ����.
int trans[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // ��, ��, ��, �� ����. 
bool visit[20][20];
int N, M, K, dir = 0; // ���ʺ��� �ð� ��������.
pair<int, int> pos;

// �� ��ǥ�� �迭���� ������� Ȯ���ϴ� �Լ�.
bool CheckPos(pair<int, int> pos)
{
    int y = pos.first;
    int x = pos.second;

    return y < 0 || y >= N || x < 0 || x >= M ? false : true;
}

// �ֻ����� �̵��� �����ϴ� �Լ�.
void MoveDice()
{
    // �������� �̵�. ���ʰ� ������ ������ ����.
    if (dir == 0)
    {
        int prev_up = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[0];
        dice[0] = prev_up;
        ++pos.second;
    }
    // �������� �̵�. ���ʰ� ������ ������ ����.
    else if (dir == 1)
    {
        int prev_up = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = prev_up;
        ++pos.first;
    }
    // �������� �̵�. ���ʰ� ������ ������ ����.
    else if (dir == 2)
    {
        int prev_up = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = prev_up;
        --pos.second;
    }
    // �������� �̵�. ���ʰ� ������ ������ ����.
    else
    {
        int prev_up = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = prev_up;
        --pos.first;
    }
}

// BFS�� �̿��Ͽ� ���� ��ǥ���� ������ �ִ� ������ ����ϴ� �Լ�.
int CalPoint()
{
    queue<pair<int, int>> que;
    que.push(pos);
    memset(visit, false, sizeof(visit));
    visit[pos.first][pos.second] = true;
    int ans = 1;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + trans[i][0];
            int dx = x + trans[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx] ||
                board[dy][dx] != board[pos.first][pos.second])
                continue;

            que.push(make_pair(dy, dx));
            visit[dy][dx] = true;
            ++ans;
        }
    }
    return board[pos.first][pos.second] * ans;
}

// ���� ������ ���ϴ� �Լ�. �̸� �̵��غ��� �迭���� ����ٸ� �ݴ� �������� �ٲ۴�.
void CalNextDir()
{
    int y = pos.first;
    int x = pos.second;

    if (dice[5] > board[y][x])
        dir = (dir + 1) % 4;
    else if (dice[5] < board[y][x])
        dir = (dir + 3) % 4;

    pair<int, int> new_pos = pos;
    if (dir == 0)
        ++new_pos.second;
    else if (dir == 1)
        ++new_pos.first;
    else if (dir == 2)
        --new_pos.second;
    else
        --new_pos.first;

    if (!CheckPos(new_pos))
        dir = (dir + 2) % 4;
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < K; ++i)
    {
        MoveDice();
        answer += CalPoint();
        CalNextDir();
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    pos = make_pair(0, 0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}