#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 단순히 수들을 입력받아 정렬한후 K번째로 큰 수를 출력하면 되는 문제다.
// 처음에는 sort()를 이용했는데 직접 구현해보니 nth_element()가 훨씬 더 빨랐다.
// 앞으로 자주 써먹어야겠다.
// 다만, nth_element()에서 주의해야할점이 있는데 보통은 정렬하는 범위에서 끝부분 즉,
// end부분은 범위내에 포함이 되지 않지만 nth_element의 기준이되는데 두번째 변수 nth는
// 포함이 된다는 것이다. 구현 방식이 nth를 기준으로 잡아 왼쪽 오른쪽을 정렬하기 때문이다.

// 자세한 설명은 주석으로 남긴다.

int board[5000000];
int N, K;

void MakeAnswer()
{
    --K;
    // 입력받은 수들을 정렬. 정확히는 K - 1번째 까지 정렬한다.
    nth_element(board, board + K, board + N);
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