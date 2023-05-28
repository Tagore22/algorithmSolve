#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// �������� ������ ������ �������� ����� �Ｚ�ٿ� ������.
// ����� ���� ���� ����. ������ ���õ� ������ �����Ͽ� �������� �����ϸ� �ǳ�,
// �� ������ �ϳ� �����ϴ�.

// 1. ���� ũ�Ⱑ ū ��� �׷��� ã�´�. �ٸ� ������(0)�� ��� �׷쿡�� ���� ������ �����ؾ��Ѵ�.
// 2. 1������ ã�� ���� ū ����� �����Ѵ�. ���� �׷���� ������ �ش��ϴ� ���� ������ ��´�.
// 3. ���ڿ� �߷��� �ۿ��Ͽ� -1�� ������ �������� �Ʒ��� ��ĭ�̶�� �Ʒ������� �̵��Ѵ�.
// 4. ���ڰ� �ݽð� �������� ȸ���Ѵ�.
// 5. �ٽ� �߷��� �ۿ��Ѵ�.

// �ϳ��� Ǯ�������. 
// 1������ �ϳ� �����ϴ�. ����Ͽ��� ������(0)�� ��� �׷쿡�� ���� �ִ�. �׷��� ������ BFS��ȸ�� ���� ����
// �̹� ��ȸ���� ���������� ��ǥ������ �ٽ� �湮�� ���� ���� ������ �ٲپ� ���� ��ȸ���� ������ �����ϰ� �ٲپ���Ѵ�.
// 2���� ���Ű� �߿��ѵ� ��ǻ� ������ �ʴ� M + 1�� �����Ͽ� �Ŀ� ���ǹ����� ��ĭó���� ���� �ϸ� �ȴ�. �� ���� �������� �������� ���Ѵ�.
// 3���� while���� �̿��Ͽ� �̵��ϴ� ĭ�� ���������� ��� �Ʒ��� �̵���Ű�� �ȴ�.
// 4���� �� �迭�ϳ��� ����� �̵����� �������� �ٽ� ���迭�� �����Ű�� �ȴ�.
// 5���� 3������ ���� �Լ��� �ٽ� ���� �ȴ�.

// �ϳ� ����������, �׷��� ���߷��� �����Ͽ� �ѹ��� Ǯ����. �ٸ� �����ߴ� ��ŭ �ð��� �ϳ� �ɷȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ��, ��, ��, ��.
int N, M;
bool visit[20][20];
vector<pair<int, int>> vec;
int max_b, max_r;
pair<int, int> pos;

// BFS��ȸ�� �����ϴ� �Լ�.
void BFS(int y, int x, int num)
{
    // ���� �ִ� ��ϰ��� ������ ��ϰ�.
    int b_num = 1;
    int r_num = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // ���� ���� board�� ���� ���ų� ������(0)�϶����� �̵������ϴ�.
            if (dy < 0 || dy >= N || dx < 0 || dx >= N || (board[dy][dx] != 0 &&
                board[dy][dx] != num) || visit[dy][dx])
                continue;

            visit[dy][dx] = true;
            que.push(make_pair(dy, dx));
            // ����Ͽ��� �������� ��� �ٸ� �׷쿡�� ���Ҽ� �ֱ⿡ ��ǥ������ ���Խ���
            // �Ŀ� �湮�� �����ϰԲ� �ٲ۴�.
            if (board[dy][dx] == 0)
            {
                vec.push_back(make_pair(dy, dx));
                ++r_num;
            }
            ++b_num;
        }
    }

    // �׷��� �ּ� ���� 2�� �̻��̴�.
    if (b_num <= 1)
        return;

    // ���� ��ǥ�� ���� ���ǹ���.
    bool isfind = false;
    if (max_b < b_num)
        isfind = true;
    else if (max_b == b_num)
        if (max_r <= r_num)
            isfind = true;

    if (isfind)
    {
        max_b = b_num;
        max_r = r_num;
        pos = make_pair(y, x);
    }
}

// ��� ��ǥ�� ��ȸ�ϸ� �ִ� �׷��� ���� ���ϰ� ������ĭ�� ���ſ��θ� �Ź� ���Ž����ش�.
void BFSAll()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visit[i][j] && (board[i][j] != -1 && board[i][j] != 0 && board[i][j] != M + 1))
            {
                vec.clear();
                BFS(i, j, board[i][j]);
                for (int i = 0; i < vec.size(); ++i)
                    visit[vec[i].first][vec[i].second] = false;
            }
}

// �ִ� �׷��� ���� �Լ�.
void EraseBFS()
{
    int num = board[pos.first][pos.second];
    queue<pair<int, int>> que;
    que.push(pos);

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // ����ĭ�� ����(M + 1�� �ٲ۴�). �ٸ�, ���� ���Ͽ� ���� ��ǥ�� ���ư����� ���� ������
            // �湮 ������ bool�迭�� �ʿ����.
            if (dy < 0 || dy >= N || dx < 0 || dx >= N || (board[dy][dx] != 0 &&
                board[dy][dx] != num))
                continue;

            board[dy][dx] = M + 1;
            que.push(make_pair(dy, dx));
        }
    }
}

// �߷��� �ۿ��Ű�� �Լ�.
void Gravity()
{
    bool isfind;
    while (true)
    {
        isfind = false;
        for (int i = N - 2; i >= 0; --i)
            for (int j = 0; j < N; ++j)
                if ((board[i][j] != -1 && board[i][j] != M + 1) && board[i + 1][j] == M + 1)
                {
                    swap(board[i][j], board[i + 1][j]);
                    isfind = true;
                }
        // ���� �̵��Ҽ� �ִ� ��ǥ�� �����ϴ��� ��� �ݺ��ϸ鼭 �߷��� �ۿ��Ų��.
        if (!isfind)
            break;
    }
}

// 90���� �ݽð� ȸ���ϴ� �Լ�. ���� �׷����� �����ϸ� ����.
void Rotate()
{
    int temp[20][20];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = board[j][N - 1 - i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = temp[i][j];
}

void MakeAnswer()
{
    int answer = 0;
    while (true)
    {
        max_b = 1;
        BFSAll();// ���⼭ ��� �׷� �˻�. �׷��� ���ٸ� while�� Ż��.(max_b�� 2���� �۴ٸ�)
        if (max_b == 1)
            break;
        answer += max_b * max_b;
        EraseBFS();// ����.
        Gravity();// ù��° �߷� �ۿ�.
        Rotate();// 90�� �ݽð� ȸ��.
        Gravity();// �ι�° �߷� �ۿ�.
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}