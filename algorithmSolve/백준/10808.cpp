#include <iostream>
#include <cstring>

using namespace std;

int board[26];
string str;

void MakeAnswer()
{
    for (int i = 0; i < str.size(); ++i)
        ++board[str[i] - 'a'];

    for (int i = 0; i < 26; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, 0, sizeof(board));

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}