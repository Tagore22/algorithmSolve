#include <iostream>
#include <map>

using namespace std;

map<string, int> board;
string str1, str2, str3;

void MakeAnswer()
{
    long long answer = board[str1] * 10 + board[str2];
    for (int i = 0; i < board[str3]; ++i)
        answer *= 10;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    board.insert(make_pair("black", 0));
    board.insert(make_pair("brown", 1));
    board.insert(make_pair("red", 2));
    board.insert(make_pair("orange", 3));
    board.insert(make_pair("yellow", 4));
    board.insert(make_pair("green", 5));
    board.insert(make_pair("blue", 6));
    board.insert(make_pair("violet", 7));
    board.insert(make_pair("grey", 8));
    board.insert(make_pair("white", 9));

    cin >> str1 >> str2 >> str3;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}