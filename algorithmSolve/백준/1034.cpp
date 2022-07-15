#include <iostream>
#include <vector>

using namespace std;

vector<string> board;
int N, M, K;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int zero = 0;
        for (int j = 0; j < M; ++j)
            if (board[i][j] == '0')
                ++zero;
        if (zero <= K && zero % 2 == K % 2)
        {
            int count = 0;
            for (int k = 0; k < N; ++k)
                if (board[i] == board[k])
                    ++count;
            answer = max(answer, count);
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.assign(N, string());
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}