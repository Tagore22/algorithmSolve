#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 각 소의 위치가 변하는 수를 출력해주면 된다.
// 다만, 소들의 위치를 초기화시킬때는 0도 1도 아닌 다른수로 해주어야 한다.
// 이 풀이에서는 -1로 초기화를 하였다. 그 이후 소들의 위치값을 입력받으면서 다음과 같은 조건문을 거친다.

// 1. idx번째 소의 기존 위치 board[idx]와 현재 소의 위치 dir이 같을 경우.
// 1-1 소의 위치는 변동이 없으므로 무시해도 된다.
// 2. 기존값과 현재 dir이 다를 경우.
// 2-1. idx번째 소의 기존위치 board[idx]가 -1이라면 소의 위치가 처음 들어오는 경우이므로 board[idx] = dir을 해주면 된다.
// 2-2. idx번째 소의 기존위치 board[idx]가 -1이 아니라면 소의 위치가 변동되었다는 것이므로 최종값 answer을 1 증가시킨후
// board[idx] = dir로 변경해주면 된다.

// 이것만 구현해주면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[11];
int N;

void MakeAnswer()
{
    // 위 상술하였듯 소의 초창기 위치를 0도 1도 아닌 다른수로 초기화해주어야 한다.
    memset(board, -1, sizeof(board));
    int idx, dir, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> idx >> dir;
        // idx번째 소의 기존 위치가 -1이 아니고 현재 위치값 dir와 다르다면 소의 위치가 변동된것이므로 최종값 answer을
        // 1 증가시켜준다.
        if (board[idx] != -1 && board[idx] != dir)
            ++answer;
        // 소의 위치를 변동시킨다.(기존 위치와 dir이 같을 경우 값 자체는 변동없음)
        board[idx] = dir;
    }

    cout << answer << '\n';
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