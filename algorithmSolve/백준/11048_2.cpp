#include <iostream>

using namespace std;

// 11048번의 가장 빠르면서 감탄했던 풀이다.
// 윈도우 슬라이딩 방식을 비슷하게 한것인데 큰 틀은 다음과 같다.

// 1. 맨 위줄부터 오른쪽으로 최대값을 계산해 나간다.
// 2. 그 다음줄부터 중요한데, 현재 좌표의 dp값은 윗줄의 값과 윗줄의 바로 앞값중 더 큰값이다.
// 따라서 현재 좌표의 앞값만 비교를 해도 3가지 값을 비교하는것과 다름이 없다. 이것을 이용하여
// 불필요한 연산을 줄이게 되고 메모리, 속도도 더 상햔된다.

// 자세한 설명은 주석으로 남긴다.

// 매번 값을 입력받으며 계산하기에 board[1001]이 필요가 없다.
int dp[1001];
int N, M;

void MakeAnswer()
{
    int cur;
    // 매번 현재값을 입력받고 바로 앞값의 dp값과 현재의 dp값을 비교한다. 현재 dp값은 윗줄의 dp값과 윗줄의 바로 앞 dp값중
    // 더 큰값이기 때문에 이렇게 하면 2가지를 비교하면서 3가지를 비교할수 있게 된다.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            cin >> cur;
            dp[j] = max(dp[j - 1], dp[j]) + cur;
        }
    cout << dp[M] << '\n';
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