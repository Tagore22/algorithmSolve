#include <iostream>

using namespace std;

//풀이
//점화식만 찾아내면 간단한 문제다. 이번 자리에 1이 오는건 이전 자리가 0일때만 가능하기에 이전 자리가 0인 경우이고,
//이번 자리가 0일때에는 이전 자리가 1이든 0이든 상관없기에 둘을 더해준다.
//마지막으로 board[N-1][0]과 board[N-1][1]을 더해서 출력하면 된다. 다만, N이 커질수록 int의 범위값을 벗어나기에
//long long 형식으로 board를 구현해야한다.

long long board[90][2];
int N;

void MakeAnswer()
{
    board[0][0] = 0;
    board[0][1] = 1;

    for (int i = 1; i < N; ++i)
    {
        board[i][0] = board[i - 1][0] + board[i - 1][1];
        board[i][1] = board[i - 1][0];
    }

    cout << board[N - 1][0] + board[N - 1][1] << '\n';
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