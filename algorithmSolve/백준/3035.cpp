#include <iostream>

using namespace std;

// Ǯ��.
// for���� ������ �߿��� ��������. �� ���ڸ� �־��� Ȯ�븸ŭ �� ����ϸ� �ȴ�.

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