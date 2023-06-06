#include <iostream>

using namespace std;

// Ǯ��.
// �������� ���� ������, �����ؾ��Ұ��� ����, ��Ÿ�� �����ؾ��ϴ� ������.
// �� Ǯ������ �߰��� ��Ÿ�� �־ ������ ������ �ֳ� �ϳ� ��̴�.
// ��Ÿ�� �����Ұ�.

// �ڼ��� ������ �ּ����� �����.

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
        // 1���� 2������.
        for (int i = 0; i < N_mid; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i][j - M_mid];

        // 2���� 3������.
        for (int i = N_mid; i < N; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i - N_mid][j];

        // 3���� 4������.
        for (int i = N_mid; i < N; ++i)
            for (int j = 0; j < M_mid; ++j)
                temp[i][j] = board[i][j + M_mid];

        // 4���� 1������.
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
        // 1���� 4������.
        for (int i = N_mid; i < N; ++i)
            for (int j = 0; j < M_mid; ++j)
                temp[i][j] = board[i - N_mid][j];

        // 4���� 3������.
        for (int i = N_mid; i < N; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i][j - M_mid];

        // 3���� 2������.
        for (int i = 0; i < N_mid; ++i)
            for (int j = M_mid; j < M; ++j)
                temp[i][j] = board[i + N_mid][j];

        // 2���� 1������.
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
        // ���⼭ ����.
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