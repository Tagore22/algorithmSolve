#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 모든 값들을 입력받아 오름차순으로 정렬후 중복되는 값들을 삭제한다.

int board[100000];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    int to = unique(board, board + N) - board;
    for (int i = 0; i < to; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}