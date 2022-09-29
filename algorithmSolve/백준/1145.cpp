#include <iostream>

using namespace std;

//주어지는 수의 최대값이 100이므로 적어도 배수의 크기는 최대 100 * 100 * 100인 100만보다 아래이므로
//1부터 차례대로 적어도 3개의 수를 나눌수 있는 수가 될때까지 1씩 증가하며 찾아봐도 시간내에 찾을수 있다.

int board[5];

void MakeAnswer()
{
    int now = 1;
    while (true)
    {
        int div = 0;
        for (int i = 0; i < 5; ++i)
            div = now % board[i] == 0 ? div + 1 : div;
        if (div >= 3)
        {
            cout << now << '\n';
            return;
        }
        ++now;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}