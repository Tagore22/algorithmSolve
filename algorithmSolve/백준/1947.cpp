#include <iostream>

using namespace std;

// 별것 아닌 dp문제인데 한참 걸렸다.
// 결과적으로 처음에 유추했던 각 값들을 dp로 묶어푸는 것이었는데
// 푸는 과정이 조금 잘못됬었다. 점화식만 잘 세우면 쉬운 문제이다.

// 자세한 설명은 주석으로 남긴다.

long long board[3];
const int div_num = 1000000000;
int N;

void MakeAnswer()
{
    // 가지치기.
    if (N <= 2)
    {
        cout << N - 1 << '\n';
        return;
    }
    // 점화식에 필요한 초기값.
    for (int i = 1; i < 3; ++i)
        board[i] = i - 1;
    // 슬라이딩 윈도우를 이용하여 연산량을 더 줄일수도 있다.
    // 점화식은 board[N] = (board[N - 1] + board[N - 2]) * N - 1이다.
    for (int i = 3; i <= N; ++i)
        board[i % 3] = (board[(i - 1) % 3] + board[(i - 2) % 3]) * (i - 1) % div_num;
    cout << board[N % 3] << '\n';
}

void Input()
{
    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}