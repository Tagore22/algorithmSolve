#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ������ ���� ���� ��������. ��2�� �������� 25���� ����� �������µ� �̷� �������� �������� 2������ �ִ�.
// ù°�� �ļ��� �����س��� ��ٷο��� �κ��� �ϳ� �����Ѵ�. ��°�� ������ �������� ��������. ���� ���
// � ĭ���� �̵��ߴµ� �� ĭ�� g�̸�, ������ �����Ⱑ �����Ѵ�. �̷� ��Ȳ���� ���� �ΰ��� ��Ȳ�� ���
// ���ԵǱ⿡ �Ѵ� 1�� �����ϴ��� �˾Ҵµ� �װ� �ƴ϶� ������ĭ�� ���� Ƚ���� 1�����ϴ� ���̾���.
// �� ������ ��� �ϳ� ��̴�. �׷��� �ᱹ�� ������ ����� �ʰ� Ǯ��´�. �����̴�.
// Ǯ�̸� ������ڸ� BFS�� ��ȸ�ϴ� ���̴�. ������ �̵��� �ּҰ��� ���ϴ� ������ BFS�ʹ� �ٸ��� ������� ����
// Ƚ���� �ּҰ����� ���ؾ��ϱ⿡ �ߺ��� �����ϴ� ���� �������. �ֳ��ϸ� �Ȱ��� ĭ�� �ߺ��湮�ص� ���� pair����
// ���� ������ �ߺ��� �ƴҼ��� �ֱ� �����̾���. ���� �ϴ���� bool Ÿ������ �ϴ� �¾� �������� �ʾҴ�.
// ��ġ�ְ� ���ø� ����� pair Ÿ������ �ߺ��湮�� ���°��̾���. �� ĭ�� pair���� �ΰ� �� ������ ũ�ٸ� �����ϰ�
// �۴ٸ� ť�� ���Խ�Ű�� ���̴�. �̰��� ����� ����� ���� ù��°����. ��ġ�ִ� �߻��� �ʿ�� �ߴ�. 

// �ڼ��� ������ �ּ����� �����.

// P.S ���� �з��� ���� ���ͽ�Ʈ�� �����ִ�. �׷� ����� ������ �ְڴ�. �ֽô��� BFS�� ���ͽ�Ʈ�� ���
// �ּҰ��� ���ϱ� ���� ����̴� ��������� ����ϱ� �����̴�.

// ť�� �ֱ� ���� ����� ���� Ÿ��.
// ���� ��ǥ�� pair��.
struct pos
{
    int y;
    int x;
    pair<int, int> cur;
};

char board[50][50];
int N, M;
pair<int, int> from, to;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

// �����Ϸ��� ĭ�� ������ �����Ⱑ �����ϴ��� Ȯ���ϴ� �Լ�.
bool CheckSide(int y, int x)
{
    // �ٽ� ���� 4ĭ�� ��ȸ�Ѵ�.
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + rot[i][0];
        int nx = x + rot[i][1];

        // ���ó� �������� ����ٸ� �����Ѵ�.
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        // �������� �������� �ٷ� true�� ��ȯ�ϰ� Ż���Ѵ�.
        if (board[ny][nx] == 'g')
            return true;
    }
    // Ż������ ���ߴٴ� ���� �����⸦ �߰����� ���ߴٴ� ���̱⿡
    // false�� ��ȯ�ϰ� Ż���Ѵ�.
    return false;
}

// ��� ��츦 Ž���ϴ� BFS �Լ�.
void BFS()
{
    queue<pos> que;
    que.push(pos{ from.first, from.second, make_pair(0, 0) });
    // ����� �ߺ��湮�� ���� pair �迭. ��ĭ�� pair���� �ξ� �׺��� ũ�ٸ� �����Ѵ�.
    pair<int, int> visit[50][50];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            // �ſ� ū������ �ʱ�ȭ�صд�. �뷫 2500������ �Ѿ ��������� ������ Ȥ�� ���� �� ū������ �ص�.
            visit[i][j] = make_pair(50000, 50000);
    visit[from.first][from.second] = make_pair(0, 0);

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        pair<int, int> cur = que.front().cur;
        que.pop();

        // �������� �����ߴٸ� ���̻� ��ȸ�� �ʿ䰡 ������ �����Ѵ�.
        if (y == to.first && x == to.second)
            continue;

        // 4������ ��� ��ȸ�Ѵ�.
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // �������� ����ٸ� �����Ѵ�.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            pair<int, int> next = cur;
            // ���� �����ϴ� ���� �������� first���� �����Ѵ�. �̰��� �������� ����� ���������� �ʾҴ�.
            if (board[ny][nx] == 'g')
                next.first = cur.first + 1;
            // �����Ⱑ �ƴ϶�� ������ �����Ⱑ �ִ��� Ȯ���Ѵ�.
            else
                next.second = board[ny][nx] != 'F' && CheckSide(ny, nx) ? cur.second + 1 : cur.second;

            // ���� ����� �� next�� ���������� ũ�ٸ� �����Ѵ�.
            if (next >= visit[ny][nx])
                continue;

            // �׷��� �ʴٸ� next�� ť�� �ְ� visit���� �����Ѵ�.
            que.push(pos{ ny, nx, next });
            visit[ny][nx] = next;
        }
    }
    // ������ ���.
    cout << visit[to.first][to.second].first << ' ' << visit[to.first][to.second].second << '\n';
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
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'S')
                from = make_pair(i, j);
            else if (board[i][j] == 'F')
                to = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}