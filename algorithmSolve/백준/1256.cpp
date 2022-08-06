#include <iostream>
#include <cstring>

using namespace std;

const int MAXNUM = 1000000001;
int N, M, K;
int board[201][201];

void MakingNums()
{
    memset(board, 0, sizeof(board));
    for (int i = 0; i <= 200; ++i)
    {
        board[i][0] = board[i][i] = 1;
        for (int j = 1; j < i; ++j)
            board[i][j] = min(MAXNUM, board[i - 1][j - 1] + board[i - 1][j]);
    }
}

string Calcul(int a, int z, int k)
{
    if (a == 0)
        return string(z, 'z');

    if (board[a + z - 1][a - 1] >= k)
        return "a" + Calcul(a - 1, z, k);
    return "z" + Calcul(a, z - 1, k - board[a + z - 1][a - 1]);
}

void MakeAnswer()
{
    MakingNums();
    if (K > board[N + M][N])
    {
        cout << -1 << '\n';
        return;
    }
    cout << Calcul(N, M, K) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}