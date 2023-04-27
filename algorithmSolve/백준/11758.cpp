#include <iostream>

using namespace std;

// 풀이.
// CCW라는 기하 알고리즘의 문제였다. (Counter Clock Wise)
// 처음 본 알고리즘이라 많이 헤맸다.

// 기본적인 로직은 그리 어렵지 않은데
// a, b, c의 점이 있을때 각 c - a와 b - a의 벡터를 외적삼아

// bx - ax , by - ay
// cx - ax , cy - ay
// 를 계산하면 된다. 계산값은

// (bx - ax) * (cy - ay) - (by - ay) * (cx - ax)가 되는데 이값이 
// 1. 음수라면 시계방향.
// 2. 0이라면 직선.
// 3. 양수라면 반시계방향이 된다.



pair<int, int> board[3];

void MakeAnswer()
{
    int answer = (board[1].first - board[0].first) * (board[2].second - board[0].second) -
        (board[1].second - board[0].second) * (board[2].first - board[0].first);

    if (answer > 0)
        cout << 1 << '\n';
    else if (answer == 0)
        cout << 0 << '\n';
    else
        cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}