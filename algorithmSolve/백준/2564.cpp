#include <iostream>

using namespace std;

// Ǯ��.
// ����� �ʴ� �ݺ��� £�� ������.
// �� ����(��, ��, ��, ��)�� �׿� ���� ��ġ�� �̿��Ͽ� �Ÿ��� ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

pair<int, int> board[100], pos;
int R, C, N;

// �Ÿ��� ���ϴ� �Լ�.
// ù��°�� ��ġ�� ����, �ι�°�� �� ���������κ����� �Ÿ��� ������ �ִ�.
// ������ ���ٸ� y Ȥ�� x ���� ���̸� ���ϸ� �Ǵ� �Ÿ����� ���밪�� ��ȯ�ϸ� �ǰ�,
// �������� �ð� ����, �ݽð� ������ �Ÿ��� ���Ͽ� ����ϸ� �ȴ�.
int CalLen(int idx)
{
    int goal = board[idx].first;
    int goal_x = board[idx].second;
    int now = pos.first;
    int now_x = pos.second;

    // ��ġ�� ������ ����. ��, ���������κ����� �Ÿ����� ���Ͽ�
    // ����Ѵ�.
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
        // ���⼭ �Ÿ��� ���Ѵ�.
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