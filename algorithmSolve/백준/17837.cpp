#include <iostream>
#include <vector>
#include <algorithm>

// Ǯ��.
// �Ｚ ������� ������ �͵� ���� ���ǵ� ���� ��������.

// ū Ʋ�� ������ ����.
// 1. �Ź� ������ ��ȣ�������, ������ �ִ� ���⿡ ���� �����δ�.
// 2. ���� ��� ��ǥ���� ���� 4�� �̻� ���̴� ���� �� ���� ����Ѵ�.

// �׷� �� �ܼ��ϰ� ������ �����̴� ������ ����.
// 1. �⺻������ ���ϰ� �ִ� ������ 1ĭ�� �����δ�.
// 2. ���� ���� ������ �ٸ����� ������ �ִٸ� �� ���鵵 �Բ� �����δ�.
// 3. ���ο� ��ǥ�� �Ͼ��(0)�̶�� �׳� �����δ�.
// 4. ���ο� ��ǥ�� ������(1)�̶�� ���� ������ ������ ������ ��������.
// 5-1. ���ο� ��ǥ�� �Ķ����̰ų�, �迭���� ����� ������ �����Ǿ� ���ο� ������ 1ĭ�� �����δ�.
// 5-2. ���ο� ������ ������ ������ �Ķ����̰ų� �迭���� ����ٸ� �������� �ʴ´�.

// �̰��� �������ָ� �Ǵµ� �����ؾ� ������ �Ѱ��� �ִ�.
// 1. ���� ��ǥ�� ������(1)�̰� ������ ���������� �Ķ����̸�, ������ ������ �������� �Ķ����� ���
// �ᱹ�� �������� �ʱ⿡ ������ ������ �������� �ȵȴ�.

// �̰��� �����ϸ� �������� �����ϸ� �ȴ�.

using namespace std;

// ��⸻���� �����ϴ� ����ü.
struct chess
{
    int y;
    int x;
    int dir;
};

// �� ��ǥ�� ��⸻���� �ε��������� ������ �ִ´�.
vector<vector<vector<int>>> cur_board;
int board[13][13];
chess c[10];
int rot[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int N, K;
bool isfind = false;

// �־��� ������ ���ο� ��ǥ���� ��ȯ�ϴ� �Լ�.
chess MoveChess(int y, int x, int dir)
{
    int dy = y + rot[dir - 1][0];
    int dx = x + rot[dir - 1][1];

    // ���ο� ��ǥ�� �Ķ����̰ų� �迭���� ����� ���.
    if (dy <= 0 || dy > N || dx <= 0 || dx > N || board[dy][dx] == 2)
    {
        // ������ ������Ű�� �ι�° ���ο� ��ǥ���� ã�´�.
        dir = dir % 2 == 0 ? dir - 1 : dir + 1;
        dy = y + rot[dir - 1][0];
        dx = x + rot[dir - 1][1];
        
        // �ι�° ���ο� ��ǥ�� ���� �迭���� ����ų� �Ķ����̶�� �������� �ʴ´�. �ٸ� ������ ������ �״���̴�.
        if (dy <= 0 || dy > N || dx <= 0 || dx > N || board[dy][dx] == 2)
        {
            dy = y;
            dx = x;
        }
    }

    return chess{ dy, dx, dir };
}

void MoveAllChess(int idx)
{
    int y = c[idx].y;
    int x = c[idx].x;
    int dir = c[idx].dir;

    // ���⼭ ���ο� ��ġ�� ������ ã�´�.
    chess new_pos = MoveChess(y, x, dir);

    int new_y = new_pos.y;
    int new_x = new_pos.x;
    int new_dir = new_pos.dir;

    // �� ���ĺ��� ���Ⱚ�� �ǵ帮�� �ʴ´�. ������ ���Ⱚ�� �����Ǿ� �������� �ֱ⿡ ���⼭ ���� �����Ѵ�.
    c[idx].dir = new_dir;

    // ���⼭���� ���� idx��° ������ �������� ���ο� ��ġ�� �ű��.

    // 1. ����϶� -> �׳� �ű�.
    // 2. �������϶� -> ��ġ�� �ű⳪ ���� ������ ����.
    // 3. �Ķ����϶� -> 
    vector<int>& cur = cur_board[y][x];
    vector<int> temp;
    int Csize = cur.size() - 1;
    for (int i = Csize; i >= 0; --i)
    {
        temp.push_back(cur[i]); // ������ �Ųٷ� ���°��� ��������.
        cur.pop_back();

        if (temp.back() == idx)
            break;
    }

    // ���⼭ �ι�° ���ǹ��� �߿��ϴ�. ����Ͽ��� ���簪�� ������(1)�ε� �ᱹ�� �������� ������ ���� ��⸻���� ������ ������ ������Ѵ�.
    if (board[new_y][new_x] != 1 || (y == new_y && x == new_x))
        reverse(temp.begin(), temp.end());

    // ��⸻���� �ε������� �ű�� ��ǥ ���� �������ش�.
    vector<int>& next = cur_board[new_y][new_x];
    for (int i = 0; i < temp.size(); ++i)
    {
        next.push_back(temp[i]);
        c[temp[i]].y = new_y;
        c[temp[i]].x = new_x;
    }

    if (next.size() >= 4)
        isfind = true;
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
    {
        int y = c[i].y;
        int x = c[i].x;

        cur_board[y][x].push_back(i);
    }

    int answer = 0;
    while (true)
    {
        ++answer;
        for (int i = 0; i < K; ++i)
            MoveAllChess(i);

        if (isfind)
        {
            cout << answer << '\n';
            return;
        }

        if (answer > 1000)
        {
            cout << -1 << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cur_board.resize(N + 1, vector<vector<int>>(N + 1, vector<int>()));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];

    for (int i = 0; i < K; ++i)
        cin >> c[i].y >> c[i].x >> c[i].dir;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}