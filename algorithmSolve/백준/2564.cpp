#include <iostream>

using namespace std;

// 풀이.
// 어렵지 않는 반복성 짙은 문제다.
// 각 방향(동, 서, 남, 북)과 그에 따른 위치를 이용하여 거리를 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[100], pos;
int R, C, N;

// 거리를 구하는 함수.
// 첫번째로 위치한 방향, 두번째로 각 기준점으로부터의 거리를 얻을수 있다.
// 방향이 같다면 y 혹은 x 값의 차이만 구하면 되니 거리값의 절대값을 반환하면 되고,
// 나머지는 시계 방향, 반시계 방향의 거리를 구하여 출력하면 된다.
int CalLen(int idx)
{
    int goal = board[idx].first;
    int goal_x = board[idx].second;
    int now = pos.first;
    int now_x = pos.second;

    // 위치한 방향이 같다. 즉, 기준점으로부터의 거리만을 비교하여
    // 출력한다.
    if (now == goal)
        return abs(goal_x - now_x);

    if (now == 1 && goal == 2)
    {
        int clock = C - now_x + R + C - goal_x;
        int c_clock = now_x + R + goal_x;
        return min(clock, c_clock);
    }
    else if (now == 1 && goal == 3)
    {
        return now_x + goal_x;
    }
    else if (now == 1 && goal == 4)
    {
        return C - now_x + goal_x;
    }
    else if (now == 2 && goal == 1)
    {
        int clock = now_x + R + goal_x;
        int c_clock = C - now_x + R + C - goal_x;
        return min(clock, c_clock);
    }
    else if (now == 2 && goal == 3)
    {
        return now_x + R - goal_x;
    }
    else if (now == 2 && goal == 4)
    {
        return C - now_x + R - goal_x;
    }
    else if (now == 3 && goal == 1)
    {
        return now_x + goal_x;
    }
    else if (now == 3 && goal == 2)
    {
        return R - now_x + goal_x;
    }
    else if (now == 3 && goal == 4)
    {
        int clock = now_x + C + goal_x;
        int c_clock = R - now_x + C + R - goal_x;
    }
    else if (now == 4 && goal == 1)
    {
        return now_x + C - goal_x;
    }
    else if (now == 4 && goal == 2)
    {
        return R - now_x + C - goal_x;
    }
    else if (now == 4 && goal == 3)
    {
        int clock = R - now_x + C + R - goal_x;
        int c_clock = now_x + C + goal_x;
        return min(clock, c_clock);
    }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
        // 여기서 거리를 구한다.
        answer += CalLen(i);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> C >> R >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
    cin >> pos.first >> pos.second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}