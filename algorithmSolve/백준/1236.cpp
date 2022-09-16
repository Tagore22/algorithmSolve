#include <iostream>

using namespace std;

char board[50][50];
int N, M;
int row[50];
int col[50];

//가로로 경비원을 필요한 수와 세로로 경비원을 필요한 수중 큰수(적은 쪽을 포함하게 끔)를 반환하면 된다.

void MakeAnswer()
{
    int row_num = 0;
    for (int i = 0; i < N; ++i)
        if (row[i] == 0)
            ++row_num;
    int col_num = 0;
    for (int i = 0; i < M; ++i)
        if (col[i] == 0)
            ++col_num;
    cout << max(row_num, col_num) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'X')
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}