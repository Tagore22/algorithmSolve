#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이.
// 오랜만에 엄청 오래걸렸고, 꽤나 주먹구구식으로 푼 문제다.
// 정말 짜증난다. 특히나 상어가 경계에 끝에 도달했을때 반대방향으로
// 도는 부분의 구현이 완전 엉망인것 같다. 나머진 크게 어려울것 없었는데
// 나중에 다시 봐야겠다.

struct shark
{
    // 상어는 단 한번 이동하기에 bool 타입 변수를 두어 이동의 여부를 갱신한다.
    bool ismove;
    int s;
    int d;
    int z;
};

vector<deque<shark>> sharks;
int R, C, M, row = -1, answer = 0;

// 상어왕이 존재한느 열에서 가장 가까운 상어를 낚는 함수. 상어의 이동 이후 
// 모든 칸에는 기껏해야 한마리의 상어밖에 존재할수 없으므로
// [0]을 써도 된다.
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

// 상어의 이동을 구현하는 함수. 나중에 다시보자.
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

    // 새로운 방향을 반드시 갱신해주어야 한다.
    sharks[dy * C + dx].push_back(shark{ true, speed, dir, ssize });
    // 기존의 상어는 반드시 맨 앞에 존재하였기에 pop_front()로 처리 가능하다.
    sharks[idx].pop_front();
}

// 상어의 크기를 비교하는 함수.
bool SortShark(const shark& lhs, const shark& rhs)
{
    return lhs.z > rhs.z;
}

// 모든 상어의 이동을 구현하는 함수.
void MoveAllShark()
{
    // 각 칸의 상어가 이동하지 않은 상태라면 모두 이동시켜준다.
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            int idx = i * C + j;
            for (int iter = 0; iter < sharks[idx].size(); ++iter)
                if (!sharks[idx][iter].ismove)
                    MoveShark(i, j);
        }

    // 각 칸의 상어를 가장 큰 한마리를 제외하고 삭제한다.
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
                // 이동 가능함을 다시 갱신해주어야한다.
                sharks[idx][0].ismove = false;
            }
        }
}

void MakeAnswer()
{
    // 첫번째 열부터 마지막 열까지 순회한다.
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