#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 미니맥스 알고리즘을 안다면 어렵지 않은 문제다.
// 하지만 나는 까먹은건지 처음본건지 확실치 않지만 헤맸다;
// 미니맥스 알고리즘을 간단히 설명하자면 내턴일때에는 최대값을,
// 상대턴일때에는 최소값을 구하면 된다.
// 또한 MakeMax()의 3번째 매개변수를 dp에 엮는 풀이도 있는데 이건
// 투머치에 가깝다. 왜냐하면 처음에 4개의 수가 있을때 첫번째 플레이어일때에는
// 무조건 짝수개가 존재하고, 두번째 플레이어일때에는 무조건 홀수개가 존재하기 때문에
// 애시당초 범위가 같을수가 없기 때문이다.

// 자세한 설명은 주석으로 남긴다.

int board[1000];
int dp[1000][1000];
int T;

// 모든 경우의 수를 미니맥스 알고리즘을 이용하여 순회하는 함수.
int MakeMax(int left, int right, bool ismine)
{
    if (left > right)
        return 0;

    int& ans = dp[left][right];
    if (ans != -1)
        return ans;

    // 상술하였듯 내턴일때에는 최대로 상대의 턴일때에는 최소를 구한다.
    if (ismine)
        ans = max(MakeMax(left + 1, right, !ismine) + board[left],
            MakeMax(left, right - 1, !ismine) + board[right]);

    else
        ans = min(MakeMax(left + 1, right, !ismine),
            MakeMax(left, right - 1, !ismine));

    return ans;
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i)
            cin >> board[i];

        memset(dp, -1, sizeof(dp));
        // 여기서 최대값을 구한다.
        int answer = MakeMax(0, num - 1, true);

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