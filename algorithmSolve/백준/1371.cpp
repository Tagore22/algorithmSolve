#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

//풀이
//주어지는 모든 문자들을 입력받아 알파벳이라면 대응되는 배열의 원소값을 1올리고,
//최대값과 같은 원소들을 알파벳으로 치환하여 출력한다.

//P.S while(cin >> c) 뿐만 아니라 while(getline(cin, str)도 된다.

int board[26];

void MakeAnswer()
{
    char c;
    while (cin >> c)
        if ('a' <= c && c <= 'z')
            ++board[c - 'a'];

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