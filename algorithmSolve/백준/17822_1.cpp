#include <iostream>
#include <queue>
#include <cstring>

// �־����� ��ȣ�� 12�� ������� �����Ͽ� �ð� �����̴�.
// �ð� �������� �������� �ǵڸ� �Ǿ����� �ű��,
// �ݽð� ������ �Ǿ��� �ǵڷ� �ű��.

using namespace std;

// 17822���� �����ϸ鼭 ���� ���� ã�� �������� DFS�� �̿��� Ǯ��.
// ������ Ǯ�� ��Ŀ��� �и� ��ġ�� �κ��� �������� �ұ��ϰ� N�� M�� �ִ� 50�ۿ� �ȵǾ�
// ��� ���Ƶ� 50 * 50 * 4 = 10000�ۿ� �ȵǾ��⿡ �׳� Ǯ������
// �ڲ� ������ �ɷ� �ٽ� Ǯ��Ҵ�. �ٵ� ���� �ڲ� �̻��ؼ� ���� �ظž��µ�
// �˰��� DFS���� ����ĭ���� �Ѿ�� DFS(dy, dx)�� �ٽ� ȣ���ϴ�
// ��� ������ �ؾ������ �־���.... �Ф�...

// �� ����Ͽ��� �ִ밪�� �׸� ũ�� �ʾƼ� ���� �ߺ��� �����ص� ���ɿ� ū ���̴� ������.
// �׷��� �����͸� �ߴٴ� ������ ���Ǹ� ����.

struct rota
{
    int x;
    int d;
    int k;
};

deque<int> board[51];
bool check[51][51];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��
rota r[50];
int N, M, T;
bool isfind;

void MoveClock(int idx)
{
    int div = r[idx].x;
    int dir = r[idx].d;
    int num = r[idx].k;

    for (int i = 1; i <= N; ++i)
        if (i % div == 0)
        {
            if (dir == 0)
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].back();
                    board[i].pop_back();
                    board[i].push_front(cur);
                }
            else
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].front();
                    board[i].pop_front();
                    board[i].push_back(cur);
                }
        }
}

void DFS(int y, int x)
{
    for (int iter = 0; iter < 4; ++iter)
    {
        int dy = y + rot[iter][0];
        int dx = x + rot[iter][1];

        if (dy <= 0 || dy > N)
            continue;

        if (dx == M)
            dx = 0;
        else if (dx == -1)
            dx = M - 1;

        if (check[dy][dx])
            continue;

        if (board[y][x] == board[dy][dx])
        {
            isfind = true;
            check[y][x] = true;
            check[dy][dx] = true;
            DFS(dy, dx); // �̺κ��� �����ϰ� �־���. ��ü ����...
        }
    }
}

void EraseNum()
{
    memset(check, false, sizeof(check));
    isfind = false;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0 && !check[i][j])
                DFS(i, j);

    if (isfind)
    {
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (check[i][j])
                    board[i][j] = 0;
    }

    else
    {
        int num = 0;
        int sum = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    ++num;
                    sum += board[i][j];
                }

        double div = static_cast<double>(sum) / num;

        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    if (board[i][j] > div)
                        --board[i][j];
                    else if (board[i][j] < div)
                        ++board[i][j];
                }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        MoveClock(i);
        EraseNum();
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            answer += board[i][j];

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int cur;
            cin >> cur;
            board[i].push_back(cur);
        }

    for (int i = 0; i < T; ++i)
        cin >> r[i].x >> r[i].d >> r[i].k;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}