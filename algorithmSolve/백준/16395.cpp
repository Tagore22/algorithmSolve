#include <iostream>

using namespace std;

int N, K;
int board[31][31];

void CalTra()
{
    for (int i = 0; i <= 30; ++i)
    {
        board[i][0] = 1;
        board[i][i] = 1;
    }
    for (int i = 2; i <= 30; ++i)
        for (int j = 1; j < i; ++j)
            board[i][j] = board[i - 1][j - 1] + board[i - 1][j];
}

int main()
{
    cin >> N >> K;

    CalTra();
    cout << board[N - 1][K - 1] << '\n';
    return 0;
}