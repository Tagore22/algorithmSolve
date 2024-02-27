#include <iostream>

using namespace std;

// 풀이.
// 오른쪽에서 보인다는 것은 맨 오른쪽 막대보다 크다는 것을 의미한다. 그 이후 점점 더 커져야 보이기 때문에
// 오른쪽, 즉 맨 뒤부터 순회하며 현재 값보다 큰 막대의 수를 찾으면 된다.

int board[100000];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    int answer = 1, h = board[N - 1];
    for (int i = N - 2; i >= 0; --i)
        if (board[i] > h)
        {
            ++answer;
            h = board[i];
        }
    cout << answer << '\n';
    return 0;
}