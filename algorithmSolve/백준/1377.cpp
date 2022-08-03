#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUM = 500000;
pair<int, int> board[MAXNUM];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N - 1; ++i)
        answer = max(answer, board[i].second - i);
    cout << answer + 1 << '\n';
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
        board[i] = make_pair(a, i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}