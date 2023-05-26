#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ������ Ǯ��ô� ������ ��ȭ���̴�. �ٸ� �� �������� �Ұ� ����� �̵��� ���� ������ �־��µ�
// �̹��� �׷��� ��� ��Ȼ��ߴ�. ����ó�� ���� ���� ���������ϴµ�
// ���� ��� ���� ���� �̵��� ���� ����� �����Ҽ� ������ ����� ���� ������ ����
// ���� �����ϴ°� �����ѵ� �̰� ���� �ɼ� ���� �����̴�.

// ���� �����ؾ� ������ ���� �̵� ���ǿ� �� Ȥ�� ���� ���� ���� ���⿡ ���� ���� �Ǵٽ� ���� ������,
// ����� ���� �湮 ���θ� üũ�ؾ� �������� �Ǵٽ� ���� �ʴ´�.

// �ڼ��� ������ �ּ����� �����.

char board[1000][1000];
int R, C;
pair<int, int> start;
vector<pair<int, int>> f;
vector<vector<bool>> visit;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.

// �Ұ� ����� �̵��ϸ� Ż�⿩�� Ȥ�� Ż��ð��� ��ȯ�ϴ� �Լ�.
int BFS()
{
    visit.resize(R, vector<bool>(C, false));
    int answer = 0;
    queue<pair<int, int>> man, fire;
    man.push(start);
    visit[start.first][start.second] = true;
    for (int i = 0; i < f.size(); ++i)
        fire.push(f[i]);

    while (!man.empty())
    {
        // ����Ͽ��� ���� ���� ���������Ѵ�.
        ++answer;
        int fsize = fire.size();
        for (int i = 0; i < fsize; ++i)
        {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();

            for (int j = 0; j < 4; ++j)
            {
                int dy = y + rot[j][0];
                int dx = x + rot[j][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#' ||
                    board[dy][dx] == 'F')
                    continue;

                board[dy][dx] = 'F';
                fire.push(make_pair(dy, dx));
            }
        }

        // ����� �̵�.
        int msize = man.size();
        for (int i = 0; i < msize; ++i)
        {
            int y = man.front().first;
            int x = man.front().second;
            man.pop();
            
            // �����ڸ��� �����Ͽ��ٸ� Ż��.
            if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
                return answer;

            for (int j = 0; j < 4; ++j)
            {
                int dy = y + rot[j][0];
                int dx = x + rot[j][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#' ||
                    board[dy][dx] == 'F' || visit[dy][dx])
                    continue;

                visit[dy][dx] = true;
                man.push(make_pair(dy, dx));
            }
        }
    }
    return 987654321;
}

void MakeAnswer()
{
    int answer = BFS();

    if (answer == 987654321)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'J')
                start = make_pair(i, j);
            else if (board[i][j] == 'F')
                f.push_back(make_pair(i, j));
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}