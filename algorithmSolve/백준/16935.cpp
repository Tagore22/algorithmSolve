#include <iostream>

using namespace std;

// 풀이.
// 어려울것은 전혀 없으나, 구현해야할것이 많고, 오타에 주의해야하는 문제다.
// 다 풀었으나 중간에 오타가 있어서 로직에 문제가 있나 꽤나 헤맸다.
// 오타에 주의할것.

// 자세한 설명은 주석으로 남긴다.

int board[100][100], act[1000];
int N, M, R;

void ActFunc(int num)
{
    if (num == 1)
    {
        int mid = N / 2;
        for (int i = 0; i < mid; ++i)
            for (int j = 0; j < M; ++j)
                swap(board[i][j], board[N - 1 - i][j]);
    }
    else if (num == 2)
    {
        int mid = M / 2;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < mid; ++j)
                swap(board[i][j], board[i][M - 1 - j]);
    }
    else if (num == 3)
    {
        int temp[100][100];

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                temp[j][i] = board[N - 1 - i][j];

        swap(N, M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = temp[i][j];
    }
    else if (num == 4)
    {
        int temp[100][100];

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                temp[j][i] = board[i][M - 1 - j];

        swap(N, M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = temp[i][j];
    }
    else if (num == 5)
    {
        int temp[100][100];

        int N_mid = N / 2;
        int M_mid = M / 2;
        // 1번을 2번으로.
        for (int i = 0; i < N_mid; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i][j - M_mid];

        // 2번을 3번으로.
        for (int i = N_mid; i < N; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i - N_mid][j];

        // 3번을 4번으로.
        for (int i = N_mid; i < N; ++i)
            for (int j = 0; j < M_mid; ++j)
                temp[i][j] = board[i][j + M_mid];

        // 4번을 1번으로.
        for (int i = 0; i < N_mid; ++i)
            for (int j = 0; j < M_mid; ++j)
                temp[i][j] = board[i + N_mid][j];

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = temp[i][j];
    }
    else
    {
        int temp[100][100];

        int N_mid = N / 2;
        int M_mid = M / 2;
        // 1번을 4번으로.
        for (int i = N_mid; i < N; ++i)
            for (int j = 0; j < M_mid; ++j)
                temp[i][j] = board[i - N_mid][j];

        // 4번을 3번으로.
        for (int i = N_mid; i < N; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i][j - M_mid];

        // 3번을 2번으로.
        for (int i = 0; i < N_mid; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i + N_mid][j];

        // 2번을 1번으로.
        for (int i = 0; i < N_mid; ++i)
            for (int j = 0; j < M_mid; ++j)
                temp[i][j] = board[i][j + M_mid];

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = temp[i][j];
    }
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        // 여기서 실행.
        ActFunc(act[i]);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    for (int i = 0; i < R; ++i)
        cin >> act[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}