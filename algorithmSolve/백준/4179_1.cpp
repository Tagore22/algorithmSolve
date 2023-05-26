#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 4179���� �� ���� Ǯ��.
// �޸𸮵� �� ���� �����ϰ� �� ������.
// �������� ����� �ߺ� �湮�� ���� ���� �湮 ���θ� üũ�ϴ� bool�� �迭�� �־�����,
// �����غ��� ���� �ʿ䰡 ������.

// ����� �湮�ߴ� ���� 'J'�� �ȴٸ� ����̵� ���̵� �湮�� ���� ������ 'F' Ȥ�� 'J'�� �ȴ�.
// ����, ����� �����̴� �̵� ������ �ϳ��� �����̷��� ĭ�� ���� 'J' Ȥ�� 'F'�� �ƴϿ��� �ϹǷ�
// bool �迭�� �Ϻ��ϰ� ��ü�Ҽ� ������, ������ ��� �ð� �� �����ϴ� �޸𸮸� �ƿ� ���ټ� �ִ�.

char board[1000][1000];
int R, C;
pair<int, int> start;
vector<pair<int, int>> f;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.

int BFS()
{
    int answer = 0;
    queue<pair<int, int>> man, fire;
    man.push(start);
    for (int i = 0; i < f.size(); ++i)
        fire.push(f[i]);

    while (!man.empty())
    {
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

        int msize = man.size();
        for (int i = 0; i < msize; ++i)
        {
            int y = man.front().first;
            int x = man.front().second;
            man.pop();

            if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
                return answer;

            for (int j = 0; j < 4; ++j)
            {
                int dy = y + rot[j][0];
                int dx = x + rot[j][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] != '.')
                    continue;

                board[dy][dx] = 'J';
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