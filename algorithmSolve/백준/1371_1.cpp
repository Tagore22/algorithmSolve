#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

//1371���� �ٸ� Ǯ�� ���.
//���ڷ� �Ѱ��� ���� �ʰ� ���ڿ��� ���پ� �Է¹޴´�.
//while(getline(cin, str))�� �����Կ� �ָ��Ұ�.

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