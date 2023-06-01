#include <iostream>

using namespace std;

// 풀이.
// 피보나치 수열의 반대 문제이다.
// 마지막 D번째 수열이 주어졌을때 첫번째, 두번째 수열을 구하는 문제이다.
// 각 수열의 값은 최소 1이므로 주어진 D번째 수열에 1 ~ K - 1까지의 수를 하나씩 빼서
// D - 1번째 수열을 만든 후 첫번째 수열까지 역으로 내려가본다.
// 다만 이 과정에서 

// 1. 음수 혹은 0은 나올수 없다.
// 2. dp[N]이 dp[N + 1]보다 클수없다.

// 이 2가지 조건을 지켜야만 한다.
// 이 조건을 만족시키는 첫번째, 두번째 수열의 값을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int dp[30];
int D, K;

void MakeAnswer()
{
    // 1. dp[D - 2]값을 K ~ 0개까지 순회한다.
    // 2. dp[D - 3]부터 dp[0]까지 만들수 있다면 그것이 답인데
    // 음수가 나오거나 dp[D - N]보다 dp[D - N + 1]이 더 작다면 현재 반복문을 탈출한다.
    bool isfind;
    for (int iter = 1; iter < K; ++iter)
    {
        isfind = true;
        dp[D - 2] = dp[D - 1] - iter;
        for (int i = D - 3; i >= 0; --i)
        {
            dp[i] = dp[i + 2] - dp[i + 1];
            if (dp[i] <= 0 || dp[i] >= dp[i + 1])
            {
                isfind = false;
                break;
            }
        }
        if (isfind)
        {
            cout << dp[0] << '\n';
            cout << dp[1] << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> D >> K;
    dp[D - 1] = K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}