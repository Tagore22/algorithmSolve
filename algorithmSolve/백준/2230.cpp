#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 예전에는 풀이가 생각이 안나서 못풀었던 문제인데, 오늘은 엄청 쉽게 풀었다. 투포인터가 바로 생각났기 때문이다.
// 둘다 0에서 시작해서 두 차이가 M보다 작다면 to의 값을 1씩 올려가며 가장 작은 차이를 구한다. 그 이후 다시
// from을 1올려 또다시 가장 작은 차이를 구한다. 다만 to는 최대 N - 1까지만 증가하는걸 잊어서는 안된다.
// 이러면 최대 10만번의 순회안에 답을 풀수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[100000];
int N, M;

void MakeAnswer()
{
    // 투포인터를 사용하기 위한 정렬.
    sort(board, board + N);
    int from = 0, to = 0, answer = 2100000000; // M이 최대 20억이기 때문에 그보다 커야한다.
    // from이 to보다 더 커지거나 to가 N보다 작을때까지만 허용된다.
    while (from <= to && to < N)
    {
        // 두 수의 차이가 M보다 작다면 to를 1증가시켜 차이를 키운다.
        if (board[to] - board[from] < M)
        {
            ++to;
        }
        // 두 수의 차이가 M보다 처음으로 커졌을때 그 값을 최종값 answer와 비교하고
        // from을 1증가시켜 다시 M보다 큰 가장 작은 차이값을 구한다.
        else
        {
            answer = min(answer, board[to] - board[from]);
            ++from;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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