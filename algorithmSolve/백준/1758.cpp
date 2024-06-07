#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 팁을 얻는 방식이 존재할때 팁의 최대값을 출력하는 문제다. 팁을 오름차순으로 정렬하여 최대한 음수를 없애는 방식을
// 생각해볼수도 있으나, 적어도 이문제에서는 팁이 음수일때는 0으로 처리하기 때문에 반대로 생각해야 한다.
// 내림차순으로 정렬하여 최대한 많은 팁들을 얻고 음수들을 0을 처리해야한다. 즉, 정렬만 잘해주면 된다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int board[100000];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    sort(board, board + N, greater<int>());
    long long answer = 0;
    for (int i = 0; i < N; ++i)
        answer += board[i] - i > 0 ? board[i] - i : 0;
    cout << answer << '\n';
    return 0;
}