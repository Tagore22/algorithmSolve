#include <iostream>
#include <algorithm>

using namespace std;

// 11497번의 다른 풀이.
// 2가지가 달라졌는데 다음과 같다.

// 1. deque를 쓰지 않고 그냥 배열로 해결.
// 2. 각 끄트머리(0, 1과 N - 1, N - 2)를 처리하지 않음.

// 1번은 하술할 코드를 보면 알듯이 기존의 deque을 이용한 풀이와 비교하면
// 현재 원소 + 2의 값과 같다. 그렇기에 굳이 deque를 쓰지 않고 현재 원소 board[i]와 board[i + 2]로 계산하면 된다.

// 2번은 진작에 눈치채지 못한 것인데, 예를 들어 문제에 제시된 2 4 5 7 9 를 보면
// 이 값들을 정렬한 상태 2 4 5 7 9에서 상술한 대로 board[i]와 board[i + 2]로 계산하는데 정렬된 상태이기에
// 끄트머리값 board[0]과 board[1]의 계산값 2는 board[0]과 board[2]의 계산값 3보다 무조건 작을수밖에 없다.

// 그렇기에 굳이 끄트머리값을 계산하지 않아도 최종값을 얻어낼수 있다.

int board[10000];
int T, N;

void MakeAnswer()
{
    for (int test = 0; test < T; ++test)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];

        sort(board, board + N);

        int answer = 0;
        // 배열을 순회해가며 i번째 원소와 i + 2번째 원소로 계산하고, 나중에 끄트머리값을 따로 계산해주었는데
        // 정렬된 상태이기에 끄트머리값은 무조건 i번째 원소와 i + 2번째 원소의 계산값보다 작을수밖에 없다.
        for (int i = 0; i < N - 2; ++i)
            answer = max(answer, abs(board[i] - board[i + 2]));

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}