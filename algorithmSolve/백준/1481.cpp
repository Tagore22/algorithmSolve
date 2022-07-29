#include <iostream>
#include <cstring>

using namespace std;

int board[10][10];
int first;
int N, D;

void FirstMakeBoard()
{
    memset(board, -1, sizeof(board));
    for (int i = 0; i < N - (D - 1); ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = j + D - N > 0 ? j + D - N : 0;
    for (int i = 0; i < N - (D - 1); ++i)
        for (int j = 0; j < N; ++j)
            board[j][i] = j + D - N > 0 ? j + D - N : 0;
}

bool MakeOtherBoard(int y, int x)
{
    if (y == N)
        return true;
    bool check[10]; //bool의 초기값은 false로 알고 있으나, 그때그때마다 변하는것 같으므로 그냥 값을 명시적으로 초기화할것.
    memset(check, 1, sizeof(check));
    for (int i = 0; i < y; ++i)
        check[board[i][x]] = false;
    for (int i = 0; i < x; ++i)
        check[board[y][i]] = false;
    bool isAnswer;
    for (int i = 0; i < D; ++i)
        if (check[i])
        {
            board[y][x] = i;
            if (x + 1 != N)
                isAnswer = MakeOtherBoard(y, x + 1);
            else
                isAnswer = MakeOtherBoard(y + 1, first);
            if (isAnswer)
                return true;
        }
    return false;
}

void ShowBoard()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void MakeAnswer()
{
    FirstMakeBoard();
    first = N - D + 1;
    MakeOtherBoard(first, first);
    ShowBoard();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> D;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}