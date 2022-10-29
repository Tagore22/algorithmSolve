#include <iostream>

using namespace std;

int board[26];
int N;

void MakeAnswer()
{
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        ++board[str[0] - 'a'];
    }

    string answer = "";
    for (int i = 0; i < 26; ++i)
        if (board[i] >= 5)
            answer += 'a' + i;

    cout << (answer != "" ? answer : "PREDAJA") << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}