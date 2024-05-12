#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 예전에 많이 풀었던 이중 정렬과 비슷한 문제다.
// 최대한 많이 풀기 위해서는 어려운 버전까지 풀수 있는 문제가 많아야하며, 그 수가 K보다 적을때에는
// 쉬운 버전이라도 최대한 풀어야 한다. 그러기 위해서는 일단 어려운 버전을 기준으로 오름차순 정렬을 하여
// 최대한 많이 풀수 있는 140점짜리 문제들을 알아야한다. 그 이후 나머지는 쉬운 100점 문제로 채우면 된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<int, int> board[100];
    int N, L, K, answer = 0, solve = 0;
    cin >> N >> L >> K;
    // 만약 K가 0이라면 아무런 문제도 풀수 없으니 0을 출력하고 프로그램을 종료한다.
    // 이 부분을 간과해서 완전 정답인 140점이 아니라 100점이었다;;
    if (K == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    // 각 문제별 난이도를 입력받는다. 다만 어려운 버전이 먼저 기준이 되기에 순서를 바꾸어야 한다.
    for (int i = 0; i < N; ++i)
        cin >> board[i].second >> board[i].first;
    // 각 난이도를 정렬한다. 상술한대로 어려운 버전을 먼저 기준으로 정렬한다.
    sort(board, board + N);
    for (int i = 0; i < N; ++i)
    {
        // 두 구간에 걸쳐 각 버전별 점수를 추가한다. 만약 두번째 점수 즉, 어려운 버전을 풀수 없다면
        // 오름차순 정렬에 의해 더이상 그 어떤 어려운 버전도 풀수 없다.
        if (L >= board[i].second)
        {
            ++solve;
            answer += 100;
        }
        // 만약 어려운 문제까지 풀수 있다면 점수를 추가한다.
        answer = L >= board[i].first ? answer + 40 : answer;
        // K개 이상의 문제를 풀었다면 for문을 탈출한다.
        if (solve >= K)
            break;
    }
    cout << answer << '\n';
    return 0;
}