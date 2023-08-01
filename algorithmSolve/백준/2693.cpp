#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 매 테스트케이스마다 10개의 수를 받아 정렬후 3번째 큰수를 출력하면 된다.

int board[10];
int T;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        for (int i = 0; i < 10; ++i)
            cin >> board[i];
        sort(board, board + 10);
        cout << board[7] << '\n';
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