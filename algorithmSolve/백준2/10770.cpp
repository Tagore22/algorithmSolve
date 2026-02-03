#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str, answer = "";
vector<char> board = { 'a', 'e', 'i', 'o', 'u' };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        answer += str[i];
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            continue;
        int idx = lower_bound(board.begin(), board.end(), str[i]) - board.begin();
        if (idx == 5)
        {
            answer += board[4];
        }
        else
        {
            int left = str[i] - board[idx - 1], right = board[idx] - str[i];
            answer = left <= right ? answer + board[idx - 1] : answer + board[idx];
        }
        char cur = ' ';
        for (char j = str[i] + 1; j <= 'z'; ++j)
        {
            if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
                continue;
            cur = j;
            break;
        }
        answer = cur == ' ' ? answer + str[i] : answer + cur;
    }
    cout << answer << '\n';
    return 0;
}