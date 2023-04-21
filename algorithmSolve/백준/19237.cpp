#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

// Ǯ��.
// ��û ������ ��������. �����͵��� ����� ��� ��ĵ� ���Ƽ� �����Ұ� ���Ҵ�.

// �ٸ� ũ�� ���� ����� �ʴµ� ������ ������ ����.

// 1. ������ �־��� ����� �켱������ ���� �̵��Ѵ�.
// 1-1. �ٸ� ��� �̵��� ���� ĭ�� �ִ� ������ 1�� �����Ѵ�.
// 2. ��� �� �̵������� ��ĭ�� ���������� �� �����Ѵٸ� ��ȣ�� ���� ���� �� �����ϰ� ��� ���ܽ�Ų��.

// �̰��� ū Ʋ�̴�. �ٸ� ����Ͽ��� ������ ��ü�� ����ϱ� ������ �� �����͸� ����ϴ� ���� �� ������� �� ����.

// �ڼ��� ������ �ּ��� �����.


// ��� ��ü�� �����ϴ� ����ü.
struct shark
{
    int y;
    int x;
    int dir;
};

int rot[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // ��, �Ʒ�, ����, ������.

// ���� ����� �׿� ���� �켱������ �����ϴ� ����.
vector<vector<vector<int>>> shark_rot;
// ��ǥĭ�� �����ϴ� ������ �����ϴ� �����̳�.
vector<vector<deque<int>>> board;
// ���� ��ü�� �����ϴ� ����.
vector<shark> sharks;
// ��ǥ�� ������ �� ��ȣ�� �����ϴ� ����.
vector<vector<pair<int, int>>> small; // ����� ��ȣ, ������ ���ӽð�.
int N, M, K, shark_num; // ������ ����, ����� ��, ������ ���ӽð�.
// �̹��Ͽ� �ش� ��ǥ�� ������ �����Ͽ����� Ȯ���ϴ� bool �迭.
bool check[20][20];

// ������ ���ҽ�Ű�� �Լ�. �� �̵��� ��ǥ �̿��� �ٸ� ��ǥ���� ��� ��
// �̵��� �� ��ü������ 1�� ���ҽ�Ų��.
void SmallDown()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!check[i][j] && small[i][j].first != 0)
            {
                --small[i][j].second;
                if (small[i][j].second == 0)
                    small[i][j].first = 0;
            }
}

// idx�� �� �̵���Ű�� �Լ�.
void SharkMove(int idx)
{
    int y = sharks[idx].y;
    int x = sharks[idx].x;
    int dir = sharks[idx].dir - 1;

    vector<int>& cur_rot = shark_rot[idx - 1][dir];
    int dy, dx;

    // ����� ���⿡ ���� �켱���� ������ ��ȸ�ϸ� ���ο� ������ ã�ƺ���
    // �� �������� �̵��Ҽ� �ִٸ�(�迭���� ����� �ʰ� �ش� ��ǥ���� ������ ���ٸ�) �̵��Ѵ�.
    for (int i = 0; i < 4; ++i) // ����� ��ǥ�� �ٲٴ°� ��������.
    {
        dy = y + rot[cur_rot[i] - 1][0];
        dx = x + rot[cur_rot[i] - 1][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || small[dy][dx].first != 0)
            continue;

        // ���⼭ �����ؾ��� �͵��� ����� ����.
        // 1. ��(��ǥ���� ����).
        // 2. �� �����ϴ� �����̳��� ����.
        // 3. ����ĭ�� ������ 1 ���ҽ�Ŵ.(���� �̹��� ������ ������ٸ� �װͱ�����)
        // 4. ���� ��ǥ���� ���ο� ��ǥ���� �Ŀ� ��ü������ ������ ���ҽ�Ű�� �κп���
        // ���ܵǱ⿡ �װ��� üũ�ϴ� bool �迭.
        sharks[idx].y = dy;
        sharks[idx].x = dx;
        sharks[idx].dir = cur_rot[i];
        board[dy][dx].push_back(idx);
        board[y][x].pop_front();
        --small[y][x].second;
        if (small[y][x].second == 0)
            small[y][x].first = 0;
        check[y][x] = true;
        check[dy][dx] = true;
        return;
    }

    // ��� ������ �����Ͽ� ������ ã�� ���Ͽ�����.
    // ���������� �켱������ ��ȸ�ϸ� ���� �ڽ��� ������ ã��
    // �װ����� �̵��Ѵ�.

    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[cur_rot[i] - 1][0];
        dx = x + rot[cur_rot[i] - 1][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || small[dy][dx].first != idx)
            continue;

        // ���⼭ �����ؾ��� �͵��� ����� ����.
        // 1. ��(��ǥ���� ����).
        // 2. �� �����ϴ� �����̳��� ����.
        // 3. ����ĭ�� ������ 1 ���ҽ�Ŵ.(���� �̹��� ������ ������ٸ� �װͱ�����)
        // 4. ���� ��ǥ���� ���ο� ��ǥ���� �Ŀ� ��ü������ ������ ���ҽ�Ű�� �κп���
        // ���ܵǱ⿡ �װ��� üũ�ϴ� bool �迭.
        sharks[idx].y = dy;
        sharks[idx].x = dx;
        sharks[idx].dir = cur_rot[i];
        board[dy][dx].push_back(idx);
        board[y][x].pop_front();
        --small[y][x].second;
        if (small[y][x].second == 0)
            small[y][x].first = 0;
        check[y][x] = true;
        check[dy][dx] = true;
        return;
    }
}

// ��� �� �̵���Ű�� �Լ�.
// ��� �̵��� ���� �Ŀ� � ��ǥ���� ���������� ��
// �����Ѵٸ� ���� ���� ��ȣ�� �� �����ϰ� �������� ���ܽ�Ų��.
void SharkAllMove()
{
    for (int i = 1; i <= M; ++i)
    // ���⼭ �̹� ���ܵ� ������ �ɷ����� ���ǹ��� �����Ѵ�.
        if (sharks[i].y != -1)
            SharkMove(i);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            deque<int>& cur = board[i][j];

            // �ϳ��� ��ǥ���ȿ� 2���� �̻��� �� �����Ѵٸ� ��ȣ������ �����Ͽ�
            // ���� ���� ��ȣ�� �� �����ϰ� ��� ���ܽ�Ų��. y���� -1�� �������
            // �� �Լ� ù��° for���� �����ϴ� y != -1���� �ɸ��� �����.
            if (cur.size() >= 1)
            {
                sort(cur.begin(), cur.end());
                int cur_size = cur.size() - 1;
                for (int iter = cur_size; iter >= 1; --iter)
                {
                    sharks[cur[iter]].y = -1;
                    cur.pop_back();
                    // ���� �����ϴ� ����� ���� ���ҽ�Ų��.
                    --shark_num;
                }
                // ���ο� ������ ����.
                small[i][j] = make_pair(cur[0], K);
            }
        }
}

void MakeAnswer()
{
    int answer = 0;
    while (shark_num > 1)
    {
        ++answer;
        memset(check, false, sizeof(check));
        SharkAllMove();
        SmallDown();

        if (answer > 1000)
        {
            answer = -1;
            break;
        }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    board.resize(N, vector<deque<int>>(N, deque<int>()));
    sharks.resize(M + 1, shark{ 0, 0, 0 });
    shark_rot.resize(M, vector<vector<int>>(4, vector<int>(4, 0)));
    small.resize(N, vector<pair<int, int>>(N, make_pair(0, 0)));
    shark_num = M;
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> cur;
            if (cur != 0)
            {
                sharks[cur].y = i;
                sharks[cur].x = j;
                small[i][j] = make_pair(cur, K);
                board[i][j].push_back(cur);
            }
        }

    for (int i = 1; i <= M; ++i)
        cin >> sharks[i].dir;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < 4; ++j)
            for (int idx = 0; idx < 4; ++idx)
            {
                vector<int>& cur = shark_rot[i][j];
                cin >> cur[idx];
            }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}