#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 백트래킹을 이용한 재귀와 dp문제이다.
// 한알짜리 약과 반알짜리 약의 개수를 가지고 모든 순회를 미리 끝마친후, 주어지는 알약의 개수의 경우를 출력하면 된다.
// 처음 로직을 잘때 한가지 중요한 실수를 했는데, 예시를 보면 9천억이 넘어가는 큰수가 있기에 그걸 보고 재귀의 가능성을
// 지워버렸다. 재귀로 한다면 이 풀이처럼 1씩 반환한다는 것이고 그렇다면 9천억이 넘어가는 연산량이 있을 것이라는 이유였다.
// 하지만 이건 말도 안되는 이야기인데 아래 풀이를 보면 최대 연산량은 dp의 두 매개변수의 최대값인 30 * 30개 즉, 900밖에 안된다.
// 실제로 많은 연산량이 존재하여도 그것은 중복되는 연산들이며 dp를 사용하여 그 중복되는 연산들을 지워버리기 때문에 실제 연산량은
// 확줄어들게 된다. 별로 어렵지는 않은 문제지만 이런 어이없는 실수로 시간이 걸렸다는게 화가 난다.
// 좀더 넓은 시야을 가지자.

// 자세한 설명은 주석으로 남긴다.

int N;
// 예시에 주어졌듯이 값이 int값을 벗어나는 경우가 존재하기에 long long타입을 써야한다.
long long dp[31][31];

// 모든 순회를 구현하는 함수.
long long BackTrack(int one, int half)
{
    // 마지막까지 도달하였다면 1개 확정.
    if (one == 0)
        return 1;

    long long& ans = dp[one][half];
    if (ans != -1)
        return ans;

    ans = 0;

    // 현재 1개짜리 알약을 집었을 경우.
    if (one > 0)
        ans += BackTrack(one - 1, half + 1);

    // 현재 반개짜리 알약을 집었을 경우.
    if (half > 0)
        ans += BackTrack(one, half - 1);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    BackTrack(30, 0);
    // 여기서 미리 구해본다.
    while (true)
    {
        cin >> N;
        if (N == 0)
            return;

        // 여기서 dp[]를 꺼내온다.
        cout << dp[N][0] << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}