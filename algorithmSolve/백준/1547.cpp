#include <iostream>

using namespace std;

int M, ball, from, to;

//현재 공의 위치를 추적하며 바뀐 두 컵 중 공을 포함하고 있던 컵이 있다면 나머지 컵의 위치로 공의 위치를 변경해주면서 반복함.

void MoveCup(int a, int b)
{
    if (ball == a)
        ball = b;
    else if (ball == b)
        ball = a;
}

void MakeAnswer()
{
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        MoveCup(from, to);
    }
    cout << ball << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    ball = 1;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}