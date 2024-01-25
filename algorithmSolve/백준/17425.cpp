#include <iostream>

using namespace std;

// 풀이.
// 에라토스테네스의 체를 이용하는 문제다. N이 주어질때 1 ~ N까지 각 수들의 약수들의 합의 합을 구해야 한다.
// 따라서 미리 에라토스테네스의 체를 이용하여 값들을 모두 구해놓으면 매번 N을 입력받을때마다 추가적인 연산없이
// 바로 출력할수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[1000001];
long long dp[1000001];
int N, T;

// 미리 모든 값들 구해놓는 에라토스테네스의 체 함수.
void Era()
{
    // 각 수들에 약수값들을 모두 더한다.
    for (int i = 1; i <= 1000000; ++i)
        for (int j = i; j <= 1000000; j += i)
            board[j] += i;
    // i까지의 약수들의 합을 모두 더한다.
    long long sum = 0;
    for (int i = 1; i <= 1000000; ++i)
    {
        sum += board[i];
        dp[i] = sum;
    }
}

void MakeAnswer()
{
    // 에라토스테네스의 체를 이용하여 미리 모든 값을 구해놓는다.
    Era();
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        // N을 입력받아 추가적인 연산없이 바로 출력.
        cout << dp[N] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}