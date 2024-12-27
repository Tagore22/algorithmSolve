#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ��û ����� ��������. ���� �������� ������ ����� �����̾��µ� �Ѱ��� �ٸ����� Ű�� �ʹ� ���Ƽ� ��Ʈ����ũ�� ó���Ҽ�
// ������. �׷��� string�� �̿��Ͽ� �ߺ� Ž���� �������� ��������� �ð��ʰ��� �����ߴ�. ����� �� Ǯ�̴� BFS�� BFS����.
// �ѹ��� BFS���� ���� Ű�� �����Ҽ� �ִ� ��� ���� ��ȸ�Ͽ� ���踦 ������ ���� �ʾ� ���ư��� ���� ������ �����صΰ�,
// ���� ���� Ű�� �����س��´�. �� ���� Ű�� ��ȸ�Ͽ� ���Ӱ� �����Ҽ� �ִ� ������ �ٽ� BFS�� ȣ���Ѵ�. �̷��� �ϸ�
// ������ �����Ҽ� ������ ������ ���Ӱ� ��ȸ�� �ϰ� �Ǿ� �ᱹ �ѹ��� BFS�� ���� ���� ���길�� �ϰ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int T, H, W;
char board[102][102];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool visit[102][102] = { false, };
string key;
// �� ��ȸ���� �����Ҽ� ���� ���� ��ġ�� �����ϴ� queue. �����Ҽ� �ְ� �Ǹ� �������־�� �ϱ� ������
// queue�� �����Ͽ���.
queue<pair<int, int>> door;
int answer = 0;

// ���� ���� Ű��� �ش� ���� �湮�Ҽ� �ִ��� Ȯ���ϴ� �Լ�.
bool CheckKey(string key, char c)
{
    for (int i = 0; i < key.size(); ++i)
        if (key[i] == c + 32)
            return true;
    return false;
}

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // �������� ����ų�, ���̰ų�, �ߺ��湮�̶�� �����Ѵ�.
            if (ny < 0 || ny >= H + 2 || nx < 0 || nx >= W + 2 || board[ny][nx] == '*' ||
                visit[ny][nx])
                continue;

            // ���ο� ������ �����϶�.
            if ('a' <= board[ny][nx] && board[ny][nx] <= 'z')
            {
                // �̹� ���� �������� Ȯ���Ͽ� ������ ���� ���� ��쿡�� �߰��Ѵ�.
                bool isfind = false;
                for (int f = 0; f < key.size(); ++f)
                    if (key[f] == board[ny][nx])
                    {
                        isfind = true;
                        break;
                    }
                key = isfind ? key : key + board[ny][nx];
            }
            // ���϶�.
            else if ('A' <= board[ny][nx] && board[ny][nx] <= 'Z')
            {
                // Ű�� ���� �湮���� ���Ѵٸ� door�� �߰��ϰ� �����Ѵ�.
                if (!CheckKey(key, board[ny][nx]))
                {
                    door.push(make_pair(ny, nx));
                    continue;
                }
            }
            // $�̶�� ���� 1�÷��ش�.
            answer = board[ny][nx] == '$' ? answer + 1 : answer;
            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // ������ �ʱ�ȭ. �׽�Ʈ ���̽��� �����ϱ⿡ �ʼ��̴�.
        answer = 0;
        while (!door.empty())
            door.pop();
        for (int i = 0; i < 102; ++i)
            for (int j = 0; j < 102; ++j)
                visit[i][j] = false;
        cin >> H >> W;
        // �ǹ������� ������ �ٸ� �Ա��� �����ϴ� ����� �����ϱ� ������
        // �迭���� �¿���� 1�� �÷� �������� �ִ� ��θ� �������Ѵ�.
        for (int i = 0; i < H + 2; ++i)
        {
            board[i][0] = '.';
            board[i][W + 1] = '.';
        }
        for (int i = 0; i < W + 2; ++i)
        {
            board[0][i] = '.';
            board[H + 1][i] = '.';
        }
        string str;
        for (int i = 1; i <= H; ++i)
        {
            cin >> str;
            for (int j = 0; j < W; ++j)
                board[i][j + 1] = str[j];
        }
        cin >> key;
        key = key == "0" ? "" : key;

        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));

        while (!que.empty())
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();
            BFS(y, x);

            // �������� ���ߴ� ������ ���Ӱ� ���� Ű�� ���� �ִٸ� que�� �߰��ϰ�
            // door���� ���ܽ�Ų��.
            int dsize = door.size();
            for (int d = 0; d < dsize; ++d)
            {
                pair<int, int> here = door.front();
                door.pop();
                char pos = board[here.first][here.second];

                bool isfind = false;
                for (int u = 0; u < key.size(); ++u)
                {
                    if (key[u] == pos + 32)
                    {
                        isfind = true;
                        break;
                    }
                }
                if (isfind)
                    que.push(here);
                else
                    door.push(here);
            }
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}