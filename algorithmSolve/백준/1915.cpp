#include <iostream>

using namespace std;

int board[1001][1001];
int N, M;

//문제에서 주어지는 N과 M의 범위가 1부터 1000인데 배열의 크기를 N과 M의 값으로 넣으면
//N과 M이 1일때에는 계산을 할수가 없기에 가로 세로의 크기를 강제로 1을 늘려야한다.
//이 부분을 깨닫지 못해 오래 걸렸다. ㅠㅠ...
//문제를 좀 잘 읽자.

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (board[i][j] != 0)
            {
                board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
                answer = max(answer, board[i][j]);
            }
    cout << answer * answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j + 1] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}