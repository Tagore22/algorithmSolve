#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 15486번의 틀린 풀이지만 복습을 위해 남겨둔다.
// 문제 자체는 어렵지 않다. 완전 탐색을 이용하여 모든 경우에서 가장 큰 수입을 구하면 되는데
// 다음 풀이의 문제점은 너무 많은 연산으로 인해 시간초과가 난다는 것이다.
// 처음에는 dp이기에 배열값인 150만으로 연산이 끝나는줄 착각했으나 그렇지 않았다.
// CalMax()의 for문을 보면 현재 원소 순서 idx부터 N까지 순회를 하는데 여기가 문제다.
// 예를 들어 1 ~ 150만일동안 작업시간이 1일인 경우를 생각해보면 for문이
// 150만번부터 1씩 줄어들며 엄청난 연산을 필요로 한다. 바로 이것때문에 시간초과가 난것이다.
// 진짜 풀이는 오히려 냅색을 이용해야 한다.

pair<int, int> board[1500000];
int dp[1500000];
int N;

int CalMax(int idx)
{
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = idx; i < N; ++i)
        if (i + board[i].first <= N)
            ans = max(ans, CalMax(i + board[i].first) + board[i].second);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = CalMax(0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}