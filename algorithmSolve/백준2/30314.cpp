#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char board[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                     'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    int N;
    string str1, str2;
    cin >> N >> str1 >> str2;
    int answer = 0;
    for (int i = 0; i < str1.size(); ++i)
    {
        int upper = 0;
        int idx = str1[i] - 'A';
        while (true)
        {
            if (board[idx] == str2[i])
                break;
            ++upper;
            idx = (idx + 1) % 26;
        }
        int lower = 0;
        idx = str1[i] - 'A';
        while (true)
        {
            if (board[idx] == str2[i])
                break;
            ++lower;
            idx = (idx + 25) % 26;
        }
        answer += min(upper, lower);
    }
    cout << answer << '\n';
    return 0;
}