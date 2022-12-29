#include <iostream>

using namespace std;

//풀이
//음수 버전의 피보나치를 따로 구해야할것처럼 보이나, 실제로는 규칙이 있다. 주어지는 n이 음수면서 짝수라면 양수버전의 피보나치의 곱하기 -1을 하면
//되고 그 이외라면 따로 건드릴 필요없이 값이 일치하기 때문이다. 따라서 주어지는 n을 검사하여 -1, 0, 1 중 하나를 출력하고 n까지의 피보나치를
//계산한뒤 절대값을 출력하라고 했기에 그냥 피보나치값을 그대로 출력하면 된다.

int board[1000001];
int n;
const int DIV_NUM = 1000000000;

void MakeAnswer()
{
    if (n == 0)
        cout << 0 << '\n';
    else if (n < 0 && n % 2 == 0)
        cout << -1 << '\n';
    else
        cout << 1 << '\n';

    board[0] = 0;
    board[1] = 1;

    n = n >= 0 ? n : n * -1;

    for (int i = 2; i <= n; ++i)
        board[i] = (board[i - 2] + board[i - 1]) % DIV_NUM;

    cout << board[n] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}