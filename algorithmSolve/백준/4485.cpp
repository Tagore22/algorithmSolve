#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �ִ� �Ÿ��淡 BFS���� �˰� Ǯ���ٰ� ���� �ظ̴�.
// �ִ� �Ÿ��� �ƴ϶� �ּ� ����ġ�� ���� ���Ͽ��� �ϱ⿡ ���ͽ�Ʈ��� Ǯ����ߴ�.
// ������ �˸� ������ ����� ������ ������ ������ ����.

// 1. 0, 0���� �����ϸ� ������ ����ġ���� board[0][0]���̴�.
// 2. ���ʰ��� �켱���� ť�� �־� ��ȸ�� �ϸ� �� �� �� �� 4�������� ���ư��� ����ġ�� �յ��� �����Ѵ�.
// 3. answer[N - 1][N - 1]�� ����Ѵ�.

// �ڼ��� ������ �ּ����� ÷����.

// ���� �� �迭�� ����ġ���� �ּ� ����ġ�� �տ� ���� �迭
int board[125][125], answer[125][125];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int N;

// 0, 0 ~ N - 1, N - 1������ ����ġ ���� �ּҰ��� ����ϴ� �Լ�.
int DK()
{
    // ��� ��ǥ������ ����ġ�� ���� 987654321�� ���ʰ����� �Ѵ�.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer[i][j] = 987654321;

    answer[0][0] = board[0][0];
    priority_queue<pair<int, pair<int, int>>> que;
    que.push(make_pair(-board[0][0], make_pair(0, 0)));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int y = que.top().second.first;
        int x = que.top().second.second;
        que.pop();

        if (answer[y][x] < cost)
            continue;

        // 4�������� ���ư��� ����ġ�� ���� �ּҰ��� �����Ѵ�.
        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= N)
                continue;

            int new_cost = cost + board[dy][dx];

            if (new_cost < answer[dy][dx])
            {
                answer[dy][dx] = new_cost;
                que.push(make_pair(-new_cost, make_pair(dy, dx)));
            }
        }
    }

    return answer[N - 1][N - 1];
}

void MakeAnswer()
{
    int idx = 0;

    while (true)
    {
        cin >> N;

        if (N == 0)
            break;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];

        ++idx;
        cout << "Problem " << idx << ": " << DK() << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}