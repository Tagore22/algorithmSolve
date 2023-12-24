#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 주어진 수들을 정렬하여 K번째로 큰 수를 출력하는 문제다.
// sort()를 사용하여 전체를 정렬후 K번째 수를 출력해도 되나 nth_element()를 이용하여 K번째 수까지만
// 정렬하여 출력하는 것이 더 빠르기 때문에 nth_element()를 사용하였다.

// 자세한 설명은 주석으로 남긴다.

int board[1000];
int N, K;

void MakeAnswer()
{
    --K;
    // K번째 수까지만 정렬.
    nth_element(board, board + K, board + N, greater<>());
    cout << board[K] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}