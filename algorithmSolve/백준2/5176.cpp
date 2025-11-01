#include <iostream>
#include <cstring>

using namespace std;

int K, P, M;
int board[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    for (int iter = 0; iter < K; ++iter)
    {
        cin >> P >> M;
        memset(board, 0, sizeof(board));
        int num;
        for (int i = 0; i < P; ++i)
        {
            cin >> num;
            ++board[num];
        }
        int answer = 0;
        for (int i = 1; i <= M; ++i)
            if (board[i] >= 2)
                answer += board[i] - 1;
        cout << answer << '\n';
    }
    return 0;
}