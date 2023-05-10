#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 5052번의 정렬식 풀이.
// 트라이의 풀이보다 메모리도 더 적게 먹고 속도도 더 빨랐다.


vector<string> board;
int T, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        bool isfind = false;
        cin >> N;
        board.resize(N, "");
        for (int i = 0; i < N; ++i)
            cin >> board[i];

        sort(board.begin(), board.end());

        for (int i = 0; i < N - 1; ++i)
        {
            int c_size = board[i].size();
            int n_size = board[i + 1].size();

            if (c_size >= n_size)
                continue;

            if (board[i + 1].substr(0, c_size) == board[i])
            {
                isfind = true;
                break;
            }
        }

        if (isfind)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}