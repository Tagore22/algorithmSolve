#include <iostream>

using namespace std;

//풀이
//2193번 문제를 피보나치 해결법으로 푼 방식.
//N번째 자리수가 0이라면 앞자리에 무슨 수가 와도 되니 N-1값이 올수 있으며,
//1이라면 바로 앞자리에 0을 두고 그 이전 N-2값이 올수 있으므로 둘을 더해
//N = N-1 + N-2의 점화식에 해당한다.

long long board[90];
int N;

void MakeAnswer()
{
    board[0] = 1;
    board[1] = 1;

    for (int i = 2; i < N; ++i)
        board[i] = board[i - 1] + board[i - 2];

    cout << board[N - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}