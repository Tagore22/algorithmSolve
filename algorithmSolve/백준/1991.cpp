#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, char>> board;

void PreOrder(int num)
{
    cout << static_cast<char>(num + 'A');
    if (board[num].first != '.')
        PreOrder(board[num].first - 'A');
    if (board[num].second != '.')
        PreOrder(board[num].second - 'A');
}

void InOrder(int num)
{
    if (board[num].first != '.')
        InOrder(board[num].first - 'A');
    cout << static_cast<char>(num + 'A');
    if (board[num].second != '.')
        InOrder(board[num].second - 'A');
}

void PostOrder(int num)
{
    if (board[num].first != '.')
        PostOrder(board[num].first - 'A');
    if (board[num].second != '.')
        PostOrder(board[num].second - 'A');
    cout << static_cast<char>(num + 'A');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    board.assign(n, make_pair(0, 0));
    for (int i = 0; i < n; ++i)
    {
        char a, b, c;
        cin >> a >> b >> c;
        board[a - 'A'] = make_pair(b, c);
    }
    PreOrder(0);
    cout << '\n';
    InOrder(0);
    cout << '\n';
    PostOrder(0);
    cout << '\n';
    return 0;
}