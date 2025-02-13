#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �������� �����ֵ� �߻��� ���ø��� ���� ��������. ó������ �𷡼��� ť�� �־� ������ �𷡼��� ã���� ������
// �̷��� �ĵ��� ��Ƽ�� �𷡼��� ��� ť�� �����ϰ� �Ǿ� ������ BFS�� ������ ���� ���� �ȴ�.
// BFS�� �⺻. ��, ���簡 �ƴ� �� ������ ť�� �ְ� ��� ���ư��� ���̾���. ��������� �𷡼��� �ƴ�
// �𷡸� ť�� �־���ߴµ� ���� 8������ �𷡼��� ���� �𷡼��� �����ϰų� ������� �����̴�. ���� ��ġ����
// 8������ ��ȸ�Ͽ� �𷡼��� ���� �����Ѵٸ� �� ưư���� 1 ���̴� ������ ������ �����Ҽ� �ִ�.
// �̹��Ͽ� ưư���� 0�� �ȴٸ� �𷡰� �Ǵ� ������ �����ϸ� �ȴ�.

// ���߻��� ���� ����. �ݴ�ε� �����غ���.
// �ڼ��� ������ �ּ����� �����.

char board[1000][1000];
int sand[1000][1000];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int H, W;
queue<pair<int, int>> que;

void BFS()
{
    // �𷡿��� �����Ѵ�.
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (sand[i][j] == 0)
                que.push(make_pair(i, j));

    int answer = -1;
    while (!que.empty())
    {
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for (int i = 0; i < 8; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // �������� ����ų� �̹� �𷡶�� �����Ѵ�.
                if (ny < 0 || ny >= H || nx < 0 || nx >= W || sand[ny][nx] == 0)
                    continue;
                // ưư���� 1���̰� �𷡰� �ȴٸ� ť�� �ִ´�.
                --sand[ny][nx];
                if (sand[ny][nx] == 0)
                    que.push(make_pair(ny, nx));
            }
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {

            cin >> board[i][j];
            if (board[i][j] == '.')
                sand[i][j] = 0;
            else
                sand[i][j] = board[i][j] - '0';
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}