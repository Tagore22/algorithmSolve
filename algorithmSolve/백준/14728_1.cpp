#include <iostream>

using namespace std;

// 14728의 더 나은 풀이.
// 재귀를 사용하지 않고 단순 반복문만을 사용하는 풀이이다.
// 어떤 과목을 선택할수 있을때 가장 최대 점수는 선택했을때 혹은 선택하지 않았을 경우 2가지중 최대인점을 이용한다.

// 자세한 설명은 주석으로 남긴다.

int dp[10001];
int N, T, K, S;

void MakeAnswer()
{
    // 과목수 N개만큼 입력을 받고 그때마다 dp값을 갱신시킨다.
    for (int i = 0; i < N; ++i)
    {
        cin >> K >> S;
        // 상술하였듯 선택이 가능할때에 선택 혹은 선택하지 않았을 경우 2가지중 최대값을 매번 갱신한다.
        for (int iter = T; iter >= K; --iter)
            dp[iter] = max(dp[iter], dp[iter - K] + S);
    }

    cout << dp[T] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}