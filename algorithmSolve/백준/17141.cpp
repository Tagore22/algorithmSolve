#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ����� ������ �������� ������ �������� �����־� ����� �Ǽ����� ���Ǹ� ���ϴ� ������.
// �ϳ��ϳ� �������ڸ� ���ʿ��ϰ� ������� ���� �ּ��� �̿��ؾ߰ڴ�.
// �ʰ� �Ͼ�� �׳� �ǹ��� -��-�� Ǯ� ������ �׷��� �̰ܳ´�.

// �ڼ��� ������ �ּ����� �����.

int board[50][50], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
// ���̷����� Ǯ�� �ִ� ��ġ��.
pair<int, int> pos[10];
// ���� ����� ��ġ��.
deque<int> cur;
bool check[50][50];
int N, M, answer = 987654321, idx = 0;

// ��� ĭ�� ���̷����� ��Ҵ��� Ȯ���ϴ� �Լ�.
bool CheckVirus()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!check[i][j])
                return false;
    return true;
}

// ���̷������� ��ġ�� ���������� ��� ĭ�� �����ϴ� �ð��� ���ϴ� �Լ�.
void BFS()
{
    queue<pair<int, int>> que;
    // ������ �Ǿ��ִ� ĭ�� �湮�Ҽ��� ���⿡ ��ȸ�� �̸� �湮�ߴٰ� ó���ؾ��Ѵ�.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            check[i][j] = board[i][j] == 1 ? true : false;
    // �̸� ������ ���̷����� ��ġ���� ť�� �ְ� �湮���θ� üũ�Ѵ�.
    for (int i = 0; i < M; ++i)
    {
        que.push(make_pair(pos[cur[i]].first, pos[cur[i]].second));
        check[pos[cur[i]].first][pos[cur[i]].second] = true;
    }
    int ans = -1;

    while (!que.empty())
    {
        ++ans;
        // ���̷����� �� �ð����� ���ÿ� �����δ�. ���� �̰����� Ȯ���ص� �������
        // �Ʒ� for�� �Ʒ����� Ȯ���ص� ����� ������, ���⿡�� Ȯ���ϴ°��� �� �󵵼���
        // �ٿ��� �ӵ��� �����ų�� �ִ�.
        if (CheckVirus())
        {
            answer = min(answer, ans);
            return;
        }
        // ����Ͽ��� ���̷����� �� �ð����� ���ÿ� �����̱⿡ ���� que�� ����ִ� ���ҵ鸸
        // �̵����Ѿ� �Ѵ�.
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 4�������� ��� �̵���Ų��.
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // �迭���� ����ų� �̹� �湮�� ��ġ��� �����Ѵ�.
                // �ٸ� ������� �̵��� ��ġ�� ���ΰ��� ���� ���ǵ� �־���߰�����
                // ����Ͽ��� ���� �ƿ� ���̷����� �����Ҽ� ���� �̸� �湮üũ�� �س��Ҵ�.
                // �׷��� ������ �湮���θ� Ȯ���ص� ������ �Բ� �ɷ����� �ִ�.
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || check[ny][nx])
                    continue;

                que.push(make_pair(ny, nx));
                check[ny][nx] = true;
            }
        }
    }
}

// ��� ���̷������� ��ġ�� ��󺸴� �Լ�.
void BackTrack(int prev, int num)
{
    // M���� ��� ����ٸ� BFS ��ȸ�� �����Ͽ� �ð��� ����غ���.
    if (num == M)
    {
        BFS();
        return;
    }

    // �ߺ��� �ɷ����� ���� ������ + 1�� ��ġ���� �����Ѵ�.
    for (int i = prev + 1; i < idx; ++i)
    {
        // �̰����� deque�� �� ���̷����� �ε������� �ѱ��.
        cur.push_back(i);
        BackTrack(i, num + 1);
        cur.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1, 0);
    // ���� answer�� ���� ������ �ʾҴٸ� ��� ��츦 �����ص� ���̷����� ä��� �����⿡
    // -1�� ���� �����Ѵ�.
    answer = answer == 987654321 ? -1 : answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                // ���� ��ġ���� 2��� ���̷����� ������ �ִ� ��ġ�̹Ƿ� pos�� �߰��Ѵ�.
                pos[idx++] = make_pair(i, j);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}