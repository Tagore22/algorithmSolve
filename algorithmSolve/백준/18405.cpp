#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ����� ���� BFS��������. �ٸ�, ��� ��ġ���� �ľ��ϴ°��� �߿��Ѱ� ����.
// �� ĭ���� �ʱⰪ���� �Է¹����� 1�̻��̶�� ���̷����� �������̶�� ���̹Ƿ� vector�� �迭�� �̿��Ͽ�
// ĭ���� �ش��ϴ� �迭�ӿ� ��� �������� ���߿� queue�� ������� ����־��ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[201][201], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
vector<pair<int, int>> vir[1000];
int N, K, S, X, Y; // X�� ���������� ��������.

void BFS()
{
    queue<pair<int, int>> que;
    // ����Ѵ�� vector�� ������� ���̷����� ���� ��ġ�� queue�� �ִ´�. ���� ���� �������� �ִ´�.
    for (int i = 1; i <= K; ++i)
        for (auto& p : vir[i])
            que.push(p);
    int time = 0;

    // time�� S���� �Ǿ����� �ݺ��� �����.
    while (time < S)
    {
        int qsize = que.size();
        ++time;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + rot[i][0];
                int ny = y + rot[i][1];

                // �迭���� ����ų� �̹� ���̷����� �����ϴ� ĭ�̶�� �����Ѵ�.
                if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] != 0)
                    continue;
                que.push(make_pair(nx, ny));
                board[nx][ny] = board[x][y];
            }
        }
    }
}

void MakeAnswer()
{
    BFS();
    cout << board[X][Y] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] >= 1)
                vir[board[i][j]].push_back(make_pair(i, j));
        }
    cin >> S >> X >> Y;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}