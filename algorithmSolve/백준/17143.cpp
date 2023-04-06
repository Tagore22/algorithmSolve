#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� ��û �����ɷȰ�, �ϳ� �ָԱ��������� Ǭ ������.
// ���� ¥������. Ư���� �� ��迡 ���� ���������� �ݴ��������
// ���� �κ��� ������ ���� �����ΰ� ����. ������ ũ�� ������ �����µ�
// ���߿� �ٽ� ���߰ڴ�.

struct shark
{
    // ���� �� �ѹ� �̵��ϱ⿡ bool Ÿ�� ������ �ξ� �̵��� ���θ� �����Ѵ�.
    bool ismove;
    int s;
    int d;
    int z;
};

vector<deque<shark>> sharks;
int R, C, M, row = -1, answer = 0;

// ������ �����Ѵ� ������ ���� ����� �� ���� �Լ�. ����� �̵� ���� 
// ��� ĭ���� �ⲯ�ؾ� �Ѹ����� ���ۿ� �����Ҽ� �����Ƿ�
// [0]�� �ᵵ �ȴ�.
void CatchShark()
{
    for (int i = 0; i < R; ++i)
        if (!sharks[i * C + row].empty())
        {
            int idx = i * C + row;
            answer += sharks[idx][0].z;
            sharks[idx].pop_back();
            break;
        }
}

// ����� �̵��� �����ϴ� �Լ�. ���߿� �ٽú���.
void MoveShark(int y, int x)
{
    int idx = y * C + x;
    int speed = sharks[idx][0].s;
    int dir = sharks[idx][0].d;
    int ssize = sharks[idx][0].z;

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

    // ���ο� ������ �ݵ�� �������־�� �Ѵ�.
    sharks[dy * C + dx].push_back(shark{ true, speed, dir, ssize });
    // ������ ���� �ݵ�� �� �տ� �����Ͽ��⿡ pop_front()�� ó�� �����ϴ�.
    sharks[idx].pop_front();
}

// ����� ũ�⸦ ���ϴ� �Լ�.
bool SortShark(const shark& lhs, const shark& rhs)
{
    return lhs.z > rhs.z;
}

// ��� ����� �̵��� �����ϴ� �Լ�.
void MoveAllShark()
{
    // �� ĭ�� �� �̵����� ���� ���¶�� ��� �̵������ش�.
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            int idx = i * C + j;
            for (int iter = 0; iter < sharks[idx].size(); ++iter)
                if (!sharks[idx][iter].ismove)
                    MoveShark(i, j);
        }

    // �� ĭ�� �� ���� ū �Ѹ����� �����ϰ� �����Ѵ�.
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            int idx = i * C + j;
            if (sharks[idx].size() >= 1)
            {
                sort(sharks[idx].begin(), sharks[idx].end(), SortShark);
                int cur_size = sharks[idx].size() - 1;
                for (int iter = 0; iter < cur_size; ++iter)
                    sharks[idx].pop_back();
                // �̵� �������� �ٽ� �������־���Ѵ�.
                sharks[idx][0].ismove = false;
            }
        }
}

void MakeAnswer()
{
    // ù��° ������ ������ ������ ��ȸ�Ѵ�.
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
    sharks.resize(R * C, deque<shark>());
    int y, x, s, d, z;
    for (int i = 0; i < M; ++i)
    {
        cin >> y >> x >> s >> d >> z;
        int idx = (y - 1) * C + (x - 1);
        sharks[idx].push_back(shark{ false, s, d, z });
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}