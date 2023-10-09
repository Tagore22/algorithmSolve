#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// N개의 수들중 M개를 고르는 시리즈 11번째다.
// 이번에는 모든 수를 고르되, 뒷자리가 더 적어도 상관없고 다만
// 똑같은 수가 반복해서 나오면 안된다. 이 풀이는 이전의 고른값 int prev를 이용하여
// 그 중복을 막았다.

// 자세한 설명은 주석으로 남긴다.

int board[7], answer[7];
int N, M;

void BackTrack(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // 이전에 골랐던 값을 저장하여 이번에 고른 값과 같다면
    // 무시한다.
    int prev = -1;
    for (int i = 0; i < N; ++i)
    {
        if (board[i] == prev)
            continue;

        answer[idx] = board[i];
        BackTrack(idx + 1);
        prev = board[i];
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}