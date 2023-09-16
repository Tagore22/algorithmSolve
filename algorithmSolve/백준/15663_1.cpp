#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 15663번의 제대로 된 풀이.
// 따로 조건문을 만들 필요없이 변수하나만 추가하면 되는 문제였다.
// 기존의 선택한 값 prev_num 변수를 추가하여 이번에 고르려는 값과 같다면
// 무시한다.

// 자세한 설명은 주석으로 남긴다.

int board[8], answer[8];
bool visit[8];
int N, M;

void BackTrack(int num)
{
    // M개의 원소를 골랐을시 출력하고 탈출한다.
    if (num == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // 이전에 선택한 값을 저장하는 prev_num.
    int prev_num = 0;
    for (int i = 0; i < N; ++i)
    {
        // 이미 사용한 원소거나 이전에 지금과 같은 값을 골랐다면 무시한다.
        if (!visit[i] && prev_num != board[i])
        {
            visit[i] = true;
            answer[num] = board[i];
            prev_num = board[i];
            BackTrack(num + 1);
            visit[i] = false;
        }
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    memset(visit, false, sizeof(visit));
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