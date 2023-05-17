#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 풀이.
// 복잡하게 꼬아놓은 문제다. 이 문제의 큰틀을 보자면 이러하다.

// 1. 수는 반시계방향으로 1씩 커진다. 이를 모두 하나씩 증가시키며 구할수도 있고, 그리디로 구할수도 있는듯하다.
// 2. 범위 내의 값을 출력하되, 모두 같은 칸을 차지하게 출력한다. 예를 들어 100과 1이 있다면 1의 앞에 두칸을 띄고 출력한다.

// 1번 부분은 그리디로는 엄두도 못내서 직접하나씩 증가시키기로 했다. 최대값인 5000바퀴를 돈다고해도 모든 경우의 수는
// (5000 * 2 + 1)의 제곱으로 1억이 조금 넘게 때문에 시간초과에는 걸리지 않는다.
// 2번은 의외로 간단한데 가장 큰 수를 찾아서 그 수가 몇자리인지를 계산하여 모든 수를 출력할때 자리수를 비교하여
// 그만큼 공백을 먼저 출력하면 된다. 다만 이부분에서 실수가 있어서 좀 해맸다.

// 자세한 설명은 주석으로 남긴다.

int r1, c1, r2, c2, iter, y = 5000, x = 5000, cur = 1, max_num = -1;
int from_y, from_x, to_y, to_x;
vector<vector<int>> board;

// 현재 좌표가 출력범위내인지 확인하는 함수.
bool Check(int y, int x)
{
    if ((from_y <= y && y <= to_y) && (from_x <= x && x <= to_x))
        return true;
    return false;
}

// 반시계 방향으로 돌아가며 좌표 및 현재값을 갱신하는 함수.
void RotateFunc()
{
    // 시작값 역시 범위내에 들어가는지 확인해야한다.
    if (Check(y, x))
    {
        board[y - from_y][x - from_x] = cur;
        max_num = max(max_num, cur);
    }

    int rot;
    for (int i = 1; i <= iter; ++i)
    {
        // 첫번째 오른쪽
        ++x;
        ++cur;
        if (Check(y, x))
        {
            board[y - from_y][x - from_x] = cur;
            max_num = max(max_num, cur);
        }

        // 위쪽
        rot = i * 2 - 1;
        for (int idx = 0; idx < rot; ++idx)
        {
            --y;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }

        // 왼쪽
        ++rot;
        for (int idx = 0; idx < rot; ++idx)
        {
            --x;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }

        // 아래쪽
        for (int idx = 0; idx < rot; ++idx)
        {
            ++y;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }

        // 두번째 오른쪽
        for (int idx = 0; idx < rot; ++idx)
        {
            ++x;
            ++cur;
            if (Check(y, x))
            {
                board[y - from_y][x - from_x] = cur;
                max_num = max(max_num, cur);
            }
        }
    }
}

// int값 num의 자리수를 확인하는 함수. 여기서 상술한 작은 실수가 있었는데
// while문의 조건문을 num > 10이라고 했었다. 그래서 10, 100등 10의 배수들이
// 자리수가 1씩 작아져서 계산되었었다. ;;
int CalLen(int num)
{
    int ans = 1;
    while (num >= 10)
    {
        num /= 10;
        ++ans;
    }

    return ans;
}

void MakeAnswer()
{
    // 최대 몇바퀴를 돌아야하나 계산한다.
    iter = max({ abs(r1), abs(c1), abs(r2), abs(c2) });
    board.resize(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));
    from_y = 5000 + r1;
    from_x = 5000 + c1;
    to_y = 5000 + r2;
    to_x = 5000 + c2;
    // 여기서 iter만큼 회전한다.
    RotateFunc();
    max_num = CalLen(max_num);
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            // 현재값과 최대값의 자리수를 비교하여 모자라다면 공백으로 메꾸어준다.
            int now = board[i][j];
            int len = CalLen(now);
            for (int iter = 0; iter < max_num - len; ++iter)
                cout << ' ';
            cout << now << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}