#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ���̵��� ��1�θ�ŭ ���� ���� ��������. �������� ��츦 ��� �����ؾ��߱� �����̴�.
// ���� ��ü�� �׸� ����� �ʴ�. �־��� ĭ���� ���� 2�� ĭ���߿��� ������ �������� �����
// �� ���������� BFS��ȸ�� �����Ͽ� ����� �ִ� ���� ū ���� ���� ����ϸ� �ȴ�.
// ���� ��ü�� ����� �ʾ����� 1000������ 1���� ��츦 ã�� ���ؼ� �����ð� ��̴�.
// �װ��� �ļ��ϰڴ�.

// �ڼ��� ������ �ּ����� �����.

int board[50][50], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
vector<pair<int, int>> land;
deque<pair<int, int>> g_que, r_que;
int N, M, G, R, answer = 0;

// 1. ���� �������� �Ѹ��� �ִ� ������ �ʷϻ��� �������� �־��� ����ŭ ���Ƿ� �����Ѵ�.
// 2. BFS ��ȸ�� �Ͽ� ���� ������ ���Ѵ�.
// 3. BFS ��ȸ�� ���� �������� �ʷϻ��� ��� ���� �ð��� ���ư��µ� 
// �̹� �������� ���� �ʷϻ��� �����Ҽ� ���� �ʷϻ��� ���� �������� �����Ҽ� ����.
// �ٸ�, ���� �ð��뿡 ������ ��쿡�� ���� �ȴ�. ���� �Ȱ��� que�� ������� �ʰ� ���ڸ���
// �ӹ���.

// ������ ���������� �־������� ����� �ִ� ���� ���� ����ϴ� BFS ��ȸ�Լ�.
void BFS()
{
    int temp[50][50];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            temp[i][j] = board[i][j];
    int time[50][50];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            time[i][j] = -1;
    queue<pair<int, int>> que;
    // 3�� ���� �ʷϻ����� ���ϰ� 4�� ������, 5�� ���� �� ĭ���� ���Ѵ�.
    for (auto& a : g_que)
    {
        que.push(a);
        temp[a.first][a.second] = 3;
    }
    for (auto& a : r_que)
    {
        que.push(a);
        temp[a.first][a.second] = 4;
    }
    int now = 0, ans = 0;

    while (!que.empty())
    {
        ++now;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // �� �κп��� ���� ��̴�. �� ���� ����� 1000������ 1���� ��Ÿ�����µ�
            // ���� � ĭ�� ���������� ����� �Ŀ� �ʷϻ��� �ٽ� �����Ѵٸ� �� ���� ���� �ǰ� ������ �Ѵ�.
            // ������ ���� ���������� �׷��� �ʾҴ�. �������� ������ ���� �� ĭ�� ���������� ���ϸ� ť��
            // ��ǥ���� �̹� ���ԵǱ� �����̴�. �� �Ŀ� �ʷϻ��� �����Ͽ� ���� ���Ŀ��� ť�� �� ��ǥ����
            // ������� �ʰ� �״�� ��ȸ�� ���Եȴ�. �׷��� ���̷��� �ϰԵ� ���� ��ȸ�ϰ� �Ǹ� ���� ���� 
            // �̻��ϸ���ġ �þ�� �Ǿ��� ���̴�. ���� ���� ��ǥ�� ������ �ٲ���ٸ� �������־�� �Ѵ�.
            if (temp[y][x] == 5)
                continue;

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // �迭���� ����ų� ���� �Ǿ��ų�, ���� ���� ��(���� ��)�̶�� �����Ѵ�.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || temp[ny][nx] == 0 ||
                    temp[ny][nx] == temp[y][x] || temp[ny][nx] == 5)
                    continue;

                // �� ���Ĵ� �迭���� 1, 2, ���� �ٸ� 3 Ȥ�� 4�� �ɼ��ۿ� ������
                // ���� 1, 2�� ��쿡�� ���ο� ������ ����� �������� ���� �ȴ�.

                // �迭���� 1�̳� 2�� ���. ���ο� ������ �����.
                if (temp[ny][nx] == 1 || temp[ny][nx] == 2)
                {
                    // ���� ���� ������ �ٲ�� �ð����� �ٲٰ� ť�� ����ִ´�.
                    temp[ny][nx] = temp[y][x];
                    time[ny][nx] = now;
                    que.push(make_pair(ny, nx));
                }
                // 1, 2�� �ƴϸ� ���� �ٸ����� �����ϴ� ���. �� ���� �ȴ�.
                // �ٸ� ���� �ð��뿡 �����߸� �Ѵ�.
                else if (time[ny][nx] == now)
                {
                    // ���� �ϳ� �����ϸ� ���� �����Ѵ�.
                    ++ans;
                    temp[ny][nx] = 5;
                }
            }
        }
    }
    answer = max(answer, ans);
}

// ������ �Ѹ��� �ִ� ������ G, R���� ���� �Լ�.
void ChooseLand(int idx, int green, int red)
{
    // ���� G�� R���� ���ߴٸ� BFS��ȸ�� �����Ѵ�.
    if (green == G && red == R)
    {
        BFS();
        return;
    }

    // ���������� G�� R���� ���� ���ߴٸ� Ż���Ѵ�.
    if (idx == land.size())
        return;

    int y = land[idx].first;
    int x = land[idx].second;
    // �ʷϻ�.
    g_que.push_back(make_pair(y, x));
    ChooseLand(idx + 1, green + 1, red);
    g_que.pop_back();
    // ������
    r_que.push_back(make_pair(y, x));
    ChooseLand(idx + 1, green, red + 1);
    r_que.pop_back();
    // �����ϰ� �Ѿ.
    ChooseLand(idx + 1, green, red);
}

void MakeAnswer()
{
    ChooseLand(0, 0, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> G >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                land.push_back(make_pair(i, j));
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}