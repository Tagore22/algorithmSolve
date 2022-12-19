#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//처음에는 너무 안일하게 y축, x축과 평행하는 정사각형만 생각했다.

//풀이
//각 4개의 점을 입력받은후 정렬을 하여 각 점의 위치를 얻는다. (0번째가 왼쪽 아래, 1번째가 오른쪽 아래 등등)
//각 변의 길이를 구한후, 대각선의 길이 또한 구하여 변의 길이가 동일한지 또한, 대각선의 길이가 각 변의 길이의 제곱을 더한 값인지
//확인하여 0 또는 1을 출력한다.
//마지막으로 주어지는 입력값의 절대값은 10만이지만 길이를 구하는데 있어 제곱값을 사용하기에 단순 int가 아닌 long long을 사용하여
//오버플로우에 유의한다.

pair<long long, long long> board[4];
int T;

long long CalLen(pair<long long, long long> x, pair<long long, long long> y)
{
    return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
}

bool IsAnswer()
{
    long long zero_one = CalLen(board[0], board[1]);
    long long zero_two = CalLen(board[0], board[2]);
    long long two_three = CalLen(board[2], board[3]);
    long long one_three = CalLen(board[1], board[3]);

    long long zero_three = CalLen(board[0], board[3]);
    long long one_two = CalLen(board[1], board[2]);

    if (zero_one == zero_two && zero_one == two_three && zero_one == one_three &&
        zero_three == zero_one + one_three && one_two == zero_one + zero_two)
        return true;
    else
        return false;
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        for (int idx = 0; idx < 4; ++idx)
            cin >> board[idx].first >> board[idx].second;

        sort(board, board + 4);

        if (IsAnswer())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
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