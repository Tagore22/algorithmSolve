#include <iostream>
#include <deque>

using namespace std;

// Ǯ��.
// ���� ��ü�� ��û ������� ������ ������ �߸�¥�� �Ϸ����� Ǭ ������.
// ġ������ �Ǽ��� 2������ �־���.

// 1. ������ �߸�«. �������� ���õȰ��� �̵� �� ���̾�� ��ġ�� ���ε� ���� �̵����� ���ļ� ������ ��â ������.
// 2. ���� �߸����. ���� ��������ν� �뷮�� ���̰� ���ʿ��� ������ ���ִ� ���� ������ ������ ���Ұ� ��������
// �����ϰ� �ִ� ������, �����ڵ��� ��� ������ Ǯ��������. �̰� �Ǽ��ߴ�.

// ������ Ǯ�̸� ���ĺ����� ������ 1���� ������ ���� �ᱹ �ٽ� Ǫ�°� �´� ��Ȳ�� �Ǿ���.
// �ϴ� �������� ���õ� ��� Ǯ�� ���� ���� �����Ѵ�� �ڷ��� ������ �����ϵ��� ����.

// �ڼ��� ������ �ּ����� �����.

struct Fireball
{
    // ����, ����, �ӷ�, ������ ��;
    int m;
    int s;
    int d;
    int turn;
};

deque<Fireball> board[51][51];
int N, M, K; // �迭�� ���� ũ��, ���̾�� ����, �����̴� Ƚ��;
int rot[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int turn = 1;

// ��� ���̾���� �̵��ϴ� �Լ�.
void MoveFireball()
{
    // �� ��ǥ���� ��ȸ�ϸ� ���� �Ͽ� �̵��ϴ� ��� ���̾���� �̵���Ų��.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            // �̺κ��� �߿��ϴ�. ���� �� ���ķ� ���Ұ� ������ ���ɼ��� �����ϴ�. ���� �̸� ������ ������ �����س����Ѵ�.
            // �׷��� ������ ���Ŀ� �����׼����� �� ���� ������.
            int dsize = board[i][j].size();
            for (int iter = 0; iter < dsize; ++iter)
            {
                // �� ���� ���Ұ� ���� �Ͽ��� �̹� �̵��� ���Ҷ�� �� ���ķδ� ��� �̹� �̵��� ���ҵ��̱� ������
                // �����Ѵ�.
                if (board[i][j].front().turn != turn)
                    break;

                int m = board[i][j].front().m;
                int s = board[i][j].front().s;
                int d = board[i][j].front().d;
                int turn = board[i][j].front().turn;

                // 1������ -�� ���� N������, N������ +�� ���� 1������ ���� ���� �迭�̱⿡
                // ��ⷯ ������ �̿��Ѵ�.
                int dy = (i + (rot[d][0] * s)) % N;
                if (dy > 0)
                    dy = dy % N == 0 ? N : dy % N;
                else
                    dy = N + dy % N;
                int dx = (j + (rot[d][1] * s)) % N;
                if (dx > 0)
                    dx = dx % N == 0 ? N : dx % N;
                else
                    dx = N + dx % N;
                // ���ο� ��ġ�� ���̾�� �����ϰ� ���� ��ġ�� ���̾�� ���� �Ѵ�.
                board[dy][dx].push_back(Fireball{ m, s, d, turn + 1 });
                board[i][j].pop_front();
            }
        }
    }
}

// ��ĭ�� ������ ���̾�� �����ҽ� ��ġ�� �Լ�.
void FusionFireball()
{
    // ��� ���Ҹ� ��ȸ�ϸ� ������ �����ҽ� ��ģ��.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            // �� ����Ѵ�� ���Ұ� �����ɽ� ������ board[i][j].size()�� ���������� �ȴ�.
            int dsize = board[i][j].size();
            if (dsize >= 2)
            {
                // ��� ������ ������ Ȯ���ϰ� ��� ���ҵ��� �ӷ°� ������ ��ģ��.
                int m = 0, s = 0;
                bool isSame = true, isEven = board[i][j].front().d % 2;
                for (int iter = 0; iter < dsize; ++iter)
                {
                    m += board[i][j].front().m;
                    s += board[i][j].front().s;
                    if (isSame)
                        isSame = isEven == board[i][j].front().d % 2 ? true : false;
                    board[i][j].pop_front();
                }

                m /= 5;
                // ������ ���� 5�� ������ 0�̶�� �������.
                if (m == 0)
                    continue;
                s /= dsize;
                int d = isSame ? 0 : 1;
                // ������ ���̾���� 4���� ������.
                for (int iter = 0; iter < 4; ++iter)
                {
                    board[i][j].push_front(Fireball{ m, s, d, turn });
                    d += 2;
                }
            }
        }
    }
}

// K���� �̵� ���� ���� ������ ��� ��ġ�� �Լ�.
void CalMass()
{
    int answer = 0;
    // ��� ���Ҹ� ��ȸ�ϸ� ���� ������ ��ģ��.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            // ��� ����� ���ҵ��� ��ȭ�� ���⿡ ���� �̷��� ���� �ʰ�
            // board[i][j].size()�� �ص� �ȴ�.
            int dsize = board[i][j].size();
            for (int iter = 0; iter < dsize; ++iter)
                answer += board[i][j].front().m;
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
    {
        MoveFireball();
        ++turn;
        FusionFireball();
    }
    CalMass();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    int r, c, m, d, s;
    for (int i = 0; i < M; ++i)
    {
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back(Fireball{ m, s, d, 1 });
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}