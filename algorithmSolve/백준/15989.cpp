#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// dp문제임은 확실했으나, 규칙을 찾지 못해서 결국은 구글링을 하고 말았다. T^T
// 나는 갯수에 사칙연산을 이용한 규칙인줄 알았는데 그게 아니라
// 덧셈의 마지막 수를 이용한 dp였다. 더하는 순서가 다를뿐 이루는 숫자가 같은 중복은 무시하기에
// 더하는 순서는 오름차순으로만 가능하다고 하자. 
// 2차원 배열을 만들어 [n][i]가 숫자 n의 합을 이룰때 i로 끝나는 배열로 만든다.
// 그러면 각각 1 ~ 3까지 끝날수 있는데

// 1. [n][1]은 [n - 1][1]에서 맨 뒤에 1을 더하면 된다.
// 2. [n][2]은 [n - 2][1], [n - 2][2]에서 뒤에 2를 더해주면 된다.
// 3. [n][3]은 [n - 3][1], [n - 3][2], [n - 3][3]에서 뒤에 3을 더해주면 된다.

// 다만, 상술하였듯 [n - 3]까지 계산해야하므로 4부터([0]은 아예 신경쓰지 않음) 시작해야한다.

// 자세한 설명은 주석으로 남긴다.

int dp[10001][4];
int T, N;

void Init()
{
    // 상술하였듯 4부터 순회하기 때문에 그 이전값들은 미리 하드코딩한다.
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    // 최대값 10000까지 순회한다.
    for (int iter = 4; iter <= 10000; ++iter)
        // 상술하였듯 1 ~ 3까지 빼서 1 ~ 3으로 끝나는 수들을 더한다.
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= i; ++j)
                dp[iter][i] += dp[iter - i][j];
}

void MakeAnswer()
{
    memset(dp, 0, sizeof(dp));
    Init();
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        int answer = 0;
        for (int i = 1; i <= 3; ++i)
            answer += dp[N][i];
        cout << answer << '\n';
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