#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    bool board[26] = { false, };
    for (int i = 0; i < str.size(); ++i)
        board[str[i] - 'A'] = true;
    if (board[1] && board[8] && board[12] && board[14] && board[18])
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}