#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 정답율이 보여주듯 어려운 문제였다. 처음에는 2개를 더해서 2개의 배열을 만든후
// 투포인터를 이용해서 풀려고 했는데 같은 조합의 중복을 막는것이 불가능했다.
// 결과적으로 2개의 값을 구해놓은 상태에서 두번째 이후의 원소들을 이진 탐색으로 순회하여 마지막
// 3번째 원소를 찾아야했다.

// 자세한 설명은 주석으로 남긴다.

int board[10000];
int N;

void MakeAnswer()
{
    // 이진 탐색을 위한 정렬.
    sort(board, board + N);
    long long answer = 0;
    // 2번째 원소까지 10000 * 10000 가량을 순회하며 찾는다.
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            // 2번째 원소 이후의 원소들을 이진 탐색으로 순회하며 마지막 3번째 원소를 찾는다.
            // 이때 더해서 0이 되는 값을 찾아야 하기에 두 원소의 합 sum의 마이너스값을 이용해야함을 주의해야한다.
            int sum = board[i] + board[j];
            int from = lower_bound(board + j + 1, board + N, -sum) - board;
            int to = upper_bound(board + j + 1, board + N, -sum) - board;
            answer += to - from;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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