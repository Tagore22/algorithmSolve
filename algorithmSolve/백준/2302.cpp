#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// DP를 이용한 피보나치 수열 문제이다.
// 1번부터 N번까지의 좌석이 있을때 시작점은 1번에서 시작한다.
// 그 후, 순서대로 vip의 좌석번호를 받아
// 좌석번호 - 현재 번호를 한 만큼의 경우의 수를 곱해나간다.
// 예를 들어 현재 번호가 1번이고 vip가 4번이라면
// 4 - 1이 되어 1, 2, 3으로 3개의 좌석이 있을때의 경우의 수를 구하여 최종답에 곱한다.

// 경우의 수를 구하는 점화식은
// dp[n] = dp[n - 1] + dp[n - 2]로 상술한 피보나치의 수열과 같다.
// 단 dp[1]과 dp[2]는 주먹구구식으로 구해도 각각 1과 2임을 알수있다.

// 맨 마지막에 vip의 계산이 끝나면 N - 1 - 현재 번호값으로 
// 한번 더 경우의 수를 곱해주고 최종답을 출력하면 된다.

// vip는 무조건 좌석이 고정되어 있으므로 따로 계산하지 않아도 된다.
// 참고로 모든 좌석이 vip일때를 고려해야한다. 이부분을 생각하지 못해 한번 틀렸기 때문이다.
// 결과적으로 경우의 수를 구하는 함수에서 num이 0이여도 1을 반환(결과값이 없는것을 하나로 친다.)하면 된다.

int dp[41];
int N, M;

// num개의 좌석이 있을때 경우의 수를 구하는 함수.
int CalNum(int num)
{
    // num이 0일때(모든 좌석이 vip여서 혹은 1번부터 vip일때)를 고려해야한다.
    // 결과적으로 없음 그 자체를 1개의 수로 둔다.
    if (num <= 1)
        return 1;
    if (num == 2)
        return num;

    int& ans = dp[num];
    if (ans != -1)
        return ans;

    // 상술하였듯 점화식은 dp[n] = dp[n - 1] + dp[n - 2]이다.
    return ans = CalNum(num - 1) + CalNum(num - 2);
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int idx = 1, answer = 1;

    // 각 vip 번호 - 현재 번호를 하여 얻을수 있는 좌석수의
    // 경우의 수를 구하여 최종값에 곱해준다.
    for (int i = 0; i < M; ++i)
    {
        int vip;
        cin >> vip;
        answer *= CalNum(vip - idx);
        idx = vip + 1;
    }

    // 마지막으로 N - 1 - 현재 번호를 하여 한번더 경우의 수를
    // 최종값에 곱해준다.
    answer *= CalNum(N + 1 - idx);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}