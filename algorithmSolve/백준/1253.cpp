#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUM = 2000;
int board[MAXNUM];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int l = 0;
        int r = N - 1;
        while (l < r)
        {
            if (board[l] + board[r] == board[i])
            {
                if (l != i && r != i)
                {
                    ++answer;
                    break;
                }
                else if (l == i)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
            else if (board[l] + board[r] > board[i])
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
    }
    cout << answer << '\n';
}
void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}