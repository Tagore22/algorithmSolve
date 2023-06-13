#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ����� BFS �������ٰ� ���̵��� �ǹ�1�ε� �������� 38%�ΰ� ���� 
// �޸� ���� �����ΰͰ���. �������� i, j��° ������ �湮 ���θ� üũ�ϴ�
// boolŸ�� �迭 visit�� ������ �߾��µ� �Ÿ��� �迭 answer�� -1�� �ʱ�ȭ���Ѽ�
// ���� ������ ��ǥ���� answer���� -1�� �ƴ϶�� �̹� �湮�� ���̱� ������
// �̷��� ������ ��������ϴ� �Ÿ��� answer�� �̿��ؼ� ��� ���ΰ� visit�� ��ü�Ҽ� �־���
// �޸𸮸� �Ƴ��� �־���.

char board[1000][1000];
int answer[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ��, ��, ��, ��.
int N, M;
pair<int, int> from;

void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    answer[from.first][from.second] = 0;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // ����Ͽ��� answer�� �湮 ���ΰ��� ��ü�Ҽ� �ִ�. -1�� �ƴ϶�� ���� �Ұ����� ���̰ų�
            // �̹� ������ �湮�Ͽ� ���� ����� �����̱� ����.
            if (dy < 0 || dy >= N || dx < 0 || dx >= M || answer[dy][dx] != -1)
                continue;

            answer[dy][dx] = answer[y][x] + 1;
            que.push(make_pair(dy, dx));
        }
    }
}

void MakeAnswer()
{
    BFS();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // answer���� -1�� �ʱ�ȭ�ؾ� �Ѵ�. �ٸ� �Ʒ��κп��� answer���� ����ɼ��� �ֱ⿡
    // �� �������� -1�� �ʱ�ȭ�ؾ��Ѵ�.
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == '2')
                from = make_pair(i, j);
            // board���� '0'�� ���� �ƿ� ������ �Ұ����ϱ⿡ ���⼭ answer�� ���� �����Ѵ�.
            else if (board[i][j] == '0')
                answer[i][j] = 0;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}