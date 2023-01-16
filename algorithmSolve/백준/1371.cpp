#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

//Ǯ��
//�־����� ��� ���ڵ��� �Է¹޾� ���ĺ��̶�� �����Ǵ� �迭�� ���Ұ��� 1�ø���,
//�ִ밪�� ���� ���ҵ��� ���ĺ����� ġȯ�Ͽ� ����Ѵ�.

//P.S while(cin >> c) �Ӹ� �ƴ϶� while(getline(cin, str)�� �ȴ�.

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