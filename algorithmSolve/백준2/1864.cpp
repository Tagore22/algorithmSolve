#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    board['-'] = 0;
    board['\\'] = 1;
    board['('] = 2;
    board['@'] = 3;
    board['?'] = 4;
    board['>'] = 5;
    board['&'] = 6;
    board['%'] = 7;
    board['/'] = -1;

    string str;
    while (true)
    {
        cin >> str;
        if (str == "#")
            break;

        int mul = 1, sum = 0;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            sum += board[str[i]] * mul;
            mul *= 8;
        }

        cout << sum << '\n';
    }
    return 0;
}