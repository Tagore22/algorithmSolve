#include <iostream>

using namespace std;

// 풀이.
// 문제가 정말 그지같았다. 문제로는 설명이 애매해서 직접 여러방면으로 예제를 풀어보고 알았다.
// 결과적으로는 각 시간별로 주차되어 있는 트럭의 수를 저장해가며 이후 각 시간별로 주차되어 있는 트럭의 수 *
// 주차비를 모두 더하여 출력하면 된다. 다만 아래 풀이에서는 0 ~ 100을 모두 순회하지 않고 가지치기를 사용하기 위해
// 주차된 가장 빠른 시간과 가장 느린 시간을 구하여 가장 빠른 시간 ~ 가장 느린 시간 - 1까지만 순회하였다.

int main()
{
    int cost[4] = { 0, };
    for (int i = 1; i <= 3; ++i)
        cin >> cost[i];
    int from = 101, to = -1, left, right;
    int board[101] = { 0, };
    for (int i = 0; i < 3; ++i)
    {
        cin >> left >> right;
        from = min(from, left);
        to = max(to, right);
        for (int j = left; j < right; ++j)
            ++board[j];
    }
    int answer = 0;
    for (int i = from; i < to; ++i)
        answer += cost[board[i]] * board[i];
    cout << answer << '\n';
    return 0;
}