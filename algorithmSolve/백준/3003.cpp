#include <iostream>

using namespace std;

int answer[6] = { 1,1,2,2,2,8 };
int board[6];

void MakeAnswer()
{
    for (int i = 0; i < 6; ++i)
        cout << answer[i] - board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 6; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}