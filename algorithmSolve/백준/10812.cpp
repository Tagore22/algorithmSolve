#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 뒤집기 비슷하길래 Reverse()를 사용하는줄 알았는데 전혀 아니었다. 따라서 총 4번에 걸쳐 배열값들을 변경시켜야 한다.
// 1. 맨 처음부터 i전까지.
// 2. k부터 j까지.
// 3. i부터 k전까지.
// 4. j + 1부터 마지막까지.

// 그런데 열심히 풀고나니 포인터에 이상이 있다는 에러가 떴다. 포인터 자체를 쓰지 않았는데 뭔소리인가 하고 배열로 풀어봐도
// 에러가 떴다. 생각해보니 N, M의 범위가 최대 100까지였다. 왜 나는 10까진줄 알았나. 문제를 잘 읽자. 아직 정신이 완전치 않은것 같다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, i, j, k, idx;
    cin >> N >> M;

    vector<int> answer, board;
    for (int iter = 0; iter <= N; ++iter)
        answer.push_back(iter);

    for (int iter = 0; iter < M; ++iter)
    {
        board = answer;
        idx = 0;
        cin >> i >> j >> k;
        for (int cur = 0; cur < i; ++cur)
            answer[idx++] = board[cur];
        for (int cur = k; cur <= j; ++cur)
            answer[idx++] = board[cur];
        for (int cur = i; cur < k; ++cur)
            answer[idx++] = board[cur];
        for (int cur = j + 1; cur <= N; ++cur)
            answer[idx++] = board[cur];
    }
    for (int idx = 1; idx <= N; ++idx)
        cout << answer[idx] << ' ';
    cout << '\n';
    return 0;
}