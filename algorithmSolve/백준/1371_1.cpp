#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

//1371번의 다른 풀이 방법.
//문자로 한개씩 받지 않고 문자열로 한줄씩 입력받는다.
//while(getline(cin, str))이 가능함에 주목할것.

int board[26];

void MakeAnswer()
{
    string str;
    while (getline(cin, str))
        for (int i = 0; i < str.size(); ++i)
            ++board[str[i] - 'a'];

    int max_num = *(max_element(board, board + 26));
    for (int i = 0; i < 26; ++i)
        if (board[i] == max_num)
            cout << char(i + 'a');
    cout << '\n';
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, 0, sizeof(board));
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}