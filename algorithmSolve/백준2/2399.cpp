#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 처음엔 n * n의 로직을 사용해서 브루트포스로 풀었다.
// 뭔가 수학적인 접근이 필요했는데 기여도에 따른 계산이었다.
// 예를 들어 예시에서 주어진 값들을 오름차순으로 정렬하면
// 1, 2, 3, 4, 5가 되는데 각 좌표들의 거리는 앞값 - 뒷값 혹은
// 뒷값 - 앞값이 되어 자신의 수를 더하거나 빼는 경우가 된다.
// 이 때 더하느냐 빼느냐를 자신보다 큰 수 혹은 작은 수의 개수로
// 알 수가 있으며 이걸 이용하여 총합을 계산할 수 있다.

// 자세한 설명은 주석으로 남긴다.

int n;
int board[10000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    // 상술하였듯 기여도 즉, 더하느냐 빼느냐의 경우를 알려면 반드시
    // 정렬이 되어있어야만 한다.
    sort(board, board + n);
    long long answer = 0;
    // 현재 구현은 뒷값(큰값) - 앞값(작은값)의 형태를 가정한다.
    // 따라서 나보다 큰값들이 있을 경우에는 빼는 경우가 되고 작은값들이
    // 있을 경우에는 더하는 형식이 되기에 자신보다 큰수 - 자신보다 작은수 *
    // 자신의 값으로 최종값을 알아낼 수 있다.
    for (int i = 0; i < n; ++i)
        answer += static_cast<long long>(board[i]) * (i - n + 1 + i);
    cout << answer * 2 << '\n';
    return 0;
}