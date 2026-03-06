#include <iostream>

using namespace std;

int N;
int board[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    board[0] = -1;
    bool isup = true, isdown = false;
    int answer = 0, cur = 0;
    for (int i = 1; i <= N; ++i)
    {
        // board[i] == board[i - 1]은 어디인가?
        if (board[i] > board[i - 1])
        {
            if (isup)
            {
                ++cur;
            }
            else if (isdown)
            {
                answer = max(answer, cur);
                cur = 2;
                isup = true;
                isdown = false;
            }
        }
        else if (board[i] < board[i - 1])
        {
            if (isup)
            {
                ++cur;
                isup = false;
                isdown = true;
            }
            else if (isdown)
            {
                ++cur;
            }
        }
        else
        {
            answer = max(answer, cur);
            cur = 1;
            isup = true;
            isdown = false;
        }
    }
    answer = max(answer, cur);
    cout << answer << '\n';
    return 0;
}