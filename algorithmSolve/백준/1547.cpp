#include <iostream>

using namespace std;

int M, ball, from, to;

//���� ���� ��ġ�� �����ϸ� �ٲ� �� �� �� ���� �����ϰ� �ִ� ���� �ִٸ� ������ ���� ��ġ�� ���� ��ġ�� �������ָ鼭 �ݺ���.

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