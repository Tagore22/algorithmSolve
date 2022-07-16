#include <iostream>

using namespace std;

int N, M;
int board1[100][100];
int board2[100][100];

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board1[i][j] + board2[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board1[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board2[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}