#include <iostream>
#include <queue>

using namespace std;

// 1113���� �� ������ ������ Ǯ��.
// ������ ����� ���ؼ��� �����ڸ��� ���ؼ��� �ȵȴ�. �̰��� ������ Ǯ���̴�.
// ������ ��ǥ���� �ƿ츣�� ������ �� �����. �׸��� 1 ~ �־����� �ִ밪���� ��ȸ�ϸ�
// �����ڸ����� 1�� ������Ų��. �̶� BFS��ȸ�� �̿��ϴµ� ����Ѵ�� �����ڸ����� ���ų� ���� ����
// ����� ������ ����� ���� ������ BFS��ȸ���� �����Ҽ� �ִ� ������ �̸� �������� �Ŀ� �߰��Ǵ� �κп��� ���ش�.

// �ڼ��� ������ �ּ����� �����.

int board[52][52];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M, maxnum = 0, answer = 0;

// �Ź� �����ڸ����� �����Ҽ� �ִ� ��� ������ ���� ������.
void BFS(int h)
{
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    board[0][0] = h;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ��ǥ���� ����ų� �����ڸ����� �����Ҽ� �ִٸ� ���� �����Ͽ� ���߿� �߰����� �ʰ���.
                if (ny < 0 || ny > N + 1 || nx < 0 || nx > M + 1 || board[ny][nx] >= h)
                    continue;

                board[ny][nx] = h;
                que.push(make_pair(ny, nx));
            }
        }
    }
}

void MakeAnswer()
{
    for (int iter = 1; iter <= maxnum; ++iter)
    {
        BFS(iter);

        // BFS ��ȸ�� ���� �����ڸ����� �����Ҽ� �ִ� �κ��� ��� iter�� ����Ǿ��⿡
        // ���Ŀ� �߰��� ��꿡�� ���ܵȴ�.
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (board[i][j] < iter)
                {
                    ++answer;
                    ++board[i][j];
                }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 1; i <= N; ++i)
    {
        cin >> str;
        // ���� �̺κп��� �Ǽ��� �־���. str�� ���� �����ؾ��ϱ⿡ j�� 0���� �����ؾ��ϸ�
        // ���� ��ǥ�� ��ġ���� + 1�� �ؾ��Ѵ�.
        for (int j = 0; j < M; ++j)
        {
            board[i][j + 1] = str[j] - 48;
            maxnum = max(maxnum, board[i][j + 1]);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}