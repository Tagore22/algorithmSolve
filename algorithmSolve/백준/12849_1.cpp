#include <iostream>
// #include <cstring> memset()의 헤더파일.

using namespace std;

// 12849번의 더 빠른 두번째 풀이.
// 그래프가 변하지 않고 고정되어 있기 때문에 직접 순회를 하지 않고 이론적으로 풀수 있는 문제였다.
// 각 지점에 도달할수 있는 경우의 수는 현재 정점으로 도달할수 있는 정점들의 경우의 수이기에
// 이 방법을 이용하여 훨씬 더 빠르게 풀수 있었다. 또한 배열들을 0으로 초기화하는 memset()을 사용하지 않았을때
// 더 빨라졌다. 예전에 0으로 직접 초기화하지 않아서 틀렸던 문제가 있기에 습관이 들었는데 이번에 바꾸어봐야겠다.

// 자세한 설명은 주석으로 남긴다.

long long dp[8], cur[8];
const int DIV_NUM = 1000000007;
int D;

void MakeAnswer()
{
    // memset(dp, 0, sizeof(dp)); 이 부분을 제외하면 더 빨라진다. 어차피 0으로 초기화 되기에 굳이 하지 않아도 된다.
    
    // 초창기에 0에서 시작하므로 움직이지 않았을 0분 상황에는 오직 0번 정점에만 존재할수 있다.
    dp[0] = 1;


    // 상술하였듯 각 지점에 도달할수 있는 경우의 수는 현재 정점으로 도달할수 있는 정점의 경우의 수다.
    // 처음 접해보는 부분인데 잘 기억해두어야겠다.
    for (int i = 1; i <= D; ++i)
    {
        cur[0] = dp[1] + dp[2];
        cur[1] = dp[0] + dp[2] + dp[3];
        cur[2] = dp[0] + dp[1] + dp[3] + dp[4];
        cur[3] = dp[1] + dp[2] + dp[4] + dp[5];
        cur[4] = dp[2] + dp[3] + dp[5] + dp[6];
        cur[5] = dp[3] + dp[4] + dp[7];
        cur[6] = dp[4] + dp[7];
        cur[7] = dp[5] + dp[6];

        for (int i = 0; i < 8; ++i)
            // 위 수들의 합에서 int값을 벗어날 가능성이 존재하기에 long long 타입으로 해야한다.
            dp[i] = cur[i] %= DIV_NUM;
    }

    cout << dp[0] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> D;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}