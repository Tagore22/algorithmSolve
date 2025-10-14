#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// DP를 이용하여 푼 코드다. 각 상황에 맞게 여러가지 경우를 대입하면 된다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
int dp[101][200], cost[3] = { 10000, 25000, 37000 };
bool notgo[101];

int DPFunc(int day, int coupon)
{
    // 처음에는 DPFunc을 호출할 때 day의 초기값을 0으로 구현하여 if(day >= N)이었으나
    // 그러면 여러가지가 안맞기 때문에 day 값을 1로 바꾸면서 if문도 함께 수정하였다.
    if (day > N)
        return 0;

    int& ans = dp[day][coupon];
    if (ans != -1)
        return ans;

    ans = 987654321;
    // 리조트에 갈 수 없는 날.
    if (notgo[day])
        return ans = min(ans, DPFunc(day + 1, coupon));
    // 각각 하루, 3일, 5일 이용권을 구매할 경우.
    ans = min(ans, DPFunc(day + 1, coupon) + cost[0]);
    ans = min(ans, DPFunc(day + 3, coupon + 1) + cost[1]);
    ans = min(ans, DPFunc(day + 5, coupon + 2) + cost[2]);
    // 쿠폰을 사용할 경우.
    if (coupon >= 3)
        ans = min(ans, DPFunc(day + 1, coupon - 3));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(notgo, false, sizeof(notgo));

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int day;
        cin >> day;
        notgo[day] = true;
    }

    cout << DPFunc(1, 0) << '\n';
    return 0;
}