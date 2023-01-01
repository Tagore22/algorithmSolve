#include <iostream>

using namespace std;

//많이 헷갈렸던 문제. 다만 각 칸은 ox, xo, xx로만 둘수 있기에 의외로 쉬운 문제였다.

//풀이
//위 상술하였듯 각 칸은 ox, xo, xx로 처리할수 있다. 다만 세로로 붙어 있으면 안되기에 그것을 잘 처리해서
//N행까지 순회하여 모든 경우의 수를 더해 출력하며 된다.

int board[100001][3];
int N;
const int DIV_NUM = 9901;

void MakeAnswer()
{
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;

    for (int i = 2; i <= N; ++i)
    {
        board[i][0] = (board[i - 1][1] + board[i - 1][2]) % DIV_NUM;
        board[i][1] = (board[i - 1][0] + board[i - 1][2]) % DIV_NUM;
        board[i][2] = (board[i - 1][0] + board[i - 1][1] + board[i - 1][2]) % DIV_NUM;
    }

    cout << (board[N][0] + board[N][1] + board[N][2]) % DIV_NUM << '\n';
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