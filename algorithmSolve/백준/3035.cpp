#include <iostream>

using namespace std;

// 풀이.
// for문의 구현이 중요한 문제였다. 각 문자를 주어진 확대만큼 더 출력하면 된다.

char board[50][50];
int R, C, ZR, ZC;

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        for (int a = 0; a < ZR; ++a)
        {
            for (int j = 0; j < C; ++j)
                for (int b = 0; b < ZC; ++b)
                    cout << board[i][j];
            cout << '\n';
        }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> ZR >> ZC;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}