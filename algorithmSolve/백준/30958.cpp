#include <iostream>
#include <string>

using namespace std;

int N;
string str;
int board[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin.ignore();
    getline(cin, str);
    for (int i = 0; i < N; ++i)
        if ('a' <= str[i] && str[i] <= 'z')
            ++board[str[i] - 'a'];
    int answer = 0;
    for (int i = 0; i < 26; ++i)
        answer = max(answer, board[i]);
    cout << answer << '\n';
    return 0;
}