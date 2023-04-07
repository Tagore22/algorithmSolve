#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 17143���� ���� ������ �޸𸮸� ���� �����ϴ� Ǯ��.
// �������� shark Ÿ���� 3���� �迭�� ������ �־ �뷮�� �ſ� ������,
// �̹����� shark Ÿ���� 1���� �迭�� �ִ� 10000���� ������ �� ��ǥ�� ���ϴ�
// 3���� �迭�� �ܼ� intŸ������ �ٲپ���. �׷��� ���� �뷮�� ū��
// ��� �ǵ���������� �� �𸣰ڴ�. ���߿� �� �ٽú���.

struct shark
{
    bool ismove;
    int y;
    int x;
    int s;
    int d;
    int z;
};

vector<vector<deque<int>>> board;
shark sharks[10000];
int R, C, M, row = -1, answer = 0;

void CatchShark()
{
    int idx;
    for (int i = 0; i < R; ++i)
        if (!board[i][row].empty())
        {
            idx = board[i][row][0];
            answer += sharks[idx].z;
            board[i][row].pop_front();
            break;
        }
}

void MoveShark(int idx)
{
    sharks[idx].ismove = true;

    int y = sharks[idx].y;
    int x = sharks[idx].x;
    int speed = sharks[idx].s;
    int dir = sharks[idx].d;
    int ssize = sharks[idx].z;

    int dy, dx;
    if (dir == 1)
    {
        dx = x;
        speed = speed % ((R - 1) * 2);
        dy = y - speed;
        if (dy < 0)
        {
            dir = 2;
            dy *= -1;
        }
        if (dy / (R - 1) > 0)
        {
            dir = 1;
            dy = R - 1 - (dy % (R - 1));
        }
    }
    else if (dir == 2)
    {
        dx = x;
        speed = speed % ((R - 1) * 2);
        dy = y + speed;
        if (dy >= R)
        {
            dir = 1;
            dy = R - 1 - (dy - (R - 1));
        }
        if (dy < 0)
        {
            dir = 2;
            dy *= -1;
        }
    }
    else if (dir == 3)
    {
        dy = y;
        speed = speed % ((C - 1) * 2);
        dx = x + speed;
        if (dx >= C)
        {
            dir = 4;
            dx = C - 1 - (dx - (C - 1));
        }
        if (dx < 0)
        {
            dir = 3;
            dx *= -1;
        }
    }
    else
    {
        dy = y;
        speed = speed % ((C - 1) * 2);
        dx = x - speed;
        if (dx < 0)
        {
            dir = 3;
            dx *= -1;
        }
        if (dx / (C - 1) > 0)
        {
            dir = 4;
            dx = C - 1 - (dx % (C - 1));
        }
    }
    sharks[idx].y = dy;
    sharks[idx].x = dx;
    sharks[idx].d = dir;

    board[dy][dx].push_back(idx);
    board[y][x].pop_front();
}

bool SortShark(int lhs, int rhs)
{
    return sharks[lhs].z > sharks[rhs].z;
}

void MoveAllShark()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            deque<int>& cur = board[i][j];
            if (cur.size() != 0 && !sharks[cur[0]].ismove)
                MoveShark(cur[0]);
        }

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            deque<int>& cur = board[i][j];
            if (cur.size() >= 1)
            {
                sort(cur.begin(), cur.end(), SortShark);
                int cur_size = cur.size() - 1;
                for (int iter = 0; iter < cur_size; ++iter)
                    cur.pop_back();
                sharks[cur[0]].ismove = false;
            }
        }
}

void MakeAnswer()
{
    if (M == 0)
    {
        cout << 0 << '\n';
        return;
    }

    while (row < C - 1)
    {
        ++row;
        CatchShark();
        MoveAllShark();
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> M;
    board.resize(R, vector<deque<int>>(C, deque<int>()));
    int y, x, s, d, z;
    for (int i = 0; i < M; ++i)
    {
        cin >> y >> x >> s >> d >> z;
        sharks[i] = shark{ false, y - 1, x - 1, s, d, z };
        board[y - 1][x - 1].push_back(i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}