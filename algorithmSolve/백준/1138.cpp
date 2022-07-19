#include <iostream>
#include <cstring>

using namespace std;

int board[10];
int N;

void MakeAnswer()
{
    int answer[10];
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < N; ++i)
    {
        int move = board[i];
        int idx = 0;
        for (int j = 0; j < N; ++j)
            if (answer[j] == -1)
            {
                idx = j;
                break;
            }
        for (int j = 0; j < move; ++j)
        {
            ++idx;
            while (answer[idx] != -1)
            {
                ++idx;
            }
        }
        answer[idx] = i + 1;
    }
    for (int i = 0; i < N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        board[i] = a;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}