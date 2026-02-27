#include <iostream>

using namespace std;

int N, X;
int board[100000];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> X;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    int answer = 2001;
    for (int i = 1; i < N; ++i)
        answer = min(answer, board[i] + board[i - 1]);
    cout << answer * X << '\n';
    return 0;
}