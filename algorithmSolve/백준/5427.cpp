#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// ó���� DFS�� Ǯ�� �; �ð��� ���� ���� ������.
// �ִܰŸ��̱⿡ ��������� BFS�� Ǫ�°� �´µ� ���� ������ �ηȴ�.

// �� ������ �ùķ��̼� ������ ����ѵ� ūƲ�� ���ڸ� ������ ����.

// 1. ���� ���� 4������ �������� �����ϼ� �ִ� ������ �����δ�.
// 2. ����� ���������� 4������ �������� �����ϼ� �ִ� ������ �����δ�.
// 3. ����� ��ġ�� �迭���� ����� ��� �� ���� ����ϰ� �ƿ� ����� ���Ѵٸ� ���ڿ��� ����Ѵ�.

// ���� ���� �������� �ϴ� ������ ������ ����.

// 1. ���� ����� �ִ� ���� �����ϼ� �ִ�. ��, ���� ��ǥ�� ���̰ų� ���� �ƴ϶�� �ƹ����̳� ������ �� �ִ�.
// 2. ����� ���� �������� ������ ��ǥ�δ� ���� ����. �׷��⿡ ���� ���� �����̰� ����� �����δٸ� �� ������ �˸´�.

// �� ������ ���� �����Ͽ� �������� ����ϸ� �ȴ�.
// �ڼ��� ������ �ּ����� �����.

// P.S �ּ����� ������ �κ��� ������ ���� �̵��� �����ߴ� �Լ���.
// �� �Լ��� ����Ͽ� ���� �̵���Ű�� �ð� �ʰ��� ���. ���� �̵��� �ִ� 100���� �Ͼ�⿡
// �Ź� �ִ� 100����(�迭�� �ִ� ũ��)�� �̵��� �ٽ� �ִ� 100����(�ִ� ���� �̵�Ƚ��)�ϱ� �����̴�.
// ���� ���� �̵� ���� BFS�� ���Խ�Ų�ٸ� �Ź� �ִ� 100����(�迭�� �ִ� ũ��)�� ��ȸ�� �ʿ����
// �ִ� 100����(�ִ� ���� �̵�Ƚ��)�� ���� �̵���Ű�� �ȴ�.

char board[1000][1000];
bool visit[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int T, W, H;
pair<int, int> cur_pos;

/*void MoveFire()
{
    vector<pair<int, int>> next_fire;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (board[i][j] == '*')
                next_fire.push_back(make_pair(i, j));

    for (int i = 0; i < next_fire.size(); ++i)
    {
        int y = next_fire[i].first;
        int x = next_fire[i].second;

        for (int iter = 0; iter < 4; ++iter)
        {
            int dy = y + rot[iter][0];
            int dx = x + rot[iter][1];

            if (dy < 0 || dy >= H || dx < 0 || dx >= W || board[dy][dx] == '#' || board[dy][dx] == '*')
                continue;

            board[dy][dx] = '*';
        }
    }
}*/

int BFS(const vector<pair<int, int>>& fires)
{
    queue<pair<int, int>> que, fire;
    que.push(cur_pos);
    for (int i = 0; i < fires.size(); ++i)
        fire.push(make_pair(fires[i].first, fires[i].second));
    memset(visit, false, sizeof(visit));
    visit[cur_pos.first][cur_pos.second] = true;
    int answer = -1;

    while (!que.empty())
    {
        // ����Ͽ��� ���� ���� �̵��Ѵ�. ���� �ִ� 100���� �̵��ϱ⿡
        // �Ʒ� for���� �ִ� 100���� ����ȴ�.
        int fsize = fire.size();
        for (int iter = 0; iter < fsize; ++iter)
        {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();

            for (int i = 0; i < 4; ++i)
            {
                int dy = y + rot[i][0];
                int dx = x + rot[i][1];

                if (dy < 0 || dy >= H || dx < 0 || dx >= W || board[dy][dx] == '#' || board[dy][dx] == '*')
                    continue;

                board[dy][dx] = '*';
                fire.push(make_pair(dy, dx));
            }
        }

        // �� ���� ����� �̵��̴�. ����� �̵��� �ߺ��� ���⿡
        // �ִ� 100���� �Ͼ��. ���� BFS�� �ִ� 200������ ���귮�� �����Ѵ�.
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            if (y < 0 || y >= H || x < 0 || x >= W)
                return answer;

            for (int i = 0; i < 4; ++i)
            {
                int dy = y + rot[i][0];
                int dx = x + rot[i][1];

                if ((dy >= 0 && dy < H && dx >= 0 && dx < W) && (board[dy][dx] == '#' || board[dy][dx] == '*' ||
                    visit[dy][dx]))
                    continue;

                que.push(make_pair(dy, dx));
                visit[dy][dx] = true;
            }
        }
    }
    return 987654321;
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> W >> H;
        vector<pair<int, int>> fires;
        string str;
        for (int i = 0; i < H; ++i)
        {
            cin >> str;
            for (int j = 0; j < W; ++j)
            {
                board[i][j] = str[j];
                if (board[i][j] == '@')
                    cur_pos = make_pair(i, j);
                else if (board[i][j] == '*')
                    fires.push_back(make_pair(i, j));
            }
        }

        int answer = BFS(fires);

        if (answer != 987654321)
            cout << answer << '\n';
        else
            cout << "IMPOSSIBLE" << '\n';
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