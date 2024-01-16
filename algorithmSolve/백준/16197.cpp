#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ���� �ƴ� BFS�����ε� ���� 2���� �������Ѿ� �ؼ� ���� ��� ������.
// Ư�� �湮 ���θ� üũ�ϴ� bool �迭�� �����Ǿ�� �ϱ� ������ 2���� �迭 2���� �ƴ�
// 4���� �迭 �ϳ��� ����� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

struct point
{
    int zero_y;
    int zero_x;
    int one_y;
    int one_x;
};

char board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ��, ��, ��, ��
int N, M;
point from;

void BFS()
{
    queue<point> que;
    que.push(from);
    // ����Ѵ�� 2���� ������ �����Ǳ� ������ �� �湮���ε� �ϳ��� 4���� �迭�� �����Ǿ�� �Ѵ�.
    bool visit[20][20][20][20];
    memset(visit, false, sizeof(visit));
    visit[from.zero_y][from.zero_x][from.one_y][from.one_x] = true;
    int answer = 0;

    while (!que.empty() && answer < 10)
    {
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int zero_y = que.front().zero_y;
            int zero_x = que.front().zero_x;
            int one_y = que.front().one_y;
            int one_x = que.front().one_x;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                bool zero_over = false;
                bool one_over = false;

                // �� �������� �̵�.
                int nz_y = zero_y + rot[i][0];
                int nz_x = zero_x + rot[i][1];
                int no_y = one_y + rot[i][0];
                int no_x = one_x + rot[i][1];

                // ���� �ϳ��� �迭���� ����ٸ� ������ answer�� ����ϰ� Ż���Ѵ�.
                if (nz_y < 0 || nz_y >= N || nz_x < 0 || nz_x >= M)
                    zero_over = true;
                if (no_y < 0 || no_y >= N || no_x < 0 || no_x >= M)
                    one_over = true;
                if (zero_over || one_over)
                {
                    if (zero_over && one_over)
                    {
                        continue;
                    }
                    else
                    {
                        cout << answer << '\n';
                        return;
                    }
                }
                if (visit[nz_y][nz_x][no_y][no_x])
                    continue;
                // ���� ��ġ�� ���̶�� ��������, �׷��� �ʴٸ� ���簪���� �湮 ���θ� �����ϰ� ť�� �ִ´�.
                // �ٸ� ���� ��ġ�� ���̶�� rot[][] ���� �ٽ� �����ؼ� �ڷ� ������Ű�� ����� �ִ�.
                pair<int, int> next_zero = board[nz_y][nz_x] == '#' ? make_pair(zero_y, zero_x) :
                    make_pair(nz_y, nz_x);
                pair<int, int> next_one = board[no_y][no_x] == '#' ? make_pair(one_y, one_x) :
                    make_pair(no_y, no_x);
                visit[next_zero.first][next_zero.second][next_one.first][next_one.second] = true;
                que.push(point{ next_zero.first, next_zero.second, next_one.first,
                              next_one.second });
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    string str;
    bool isFind = false;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'o')
            {
                if (!isFind)
                {
                    from.zero_y = i;
                    from.zero_x = j;
                    isFind = true;
                }
                else
                {
                    from.one_y = i;
                    from.one_x = j;
                }
            }
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}