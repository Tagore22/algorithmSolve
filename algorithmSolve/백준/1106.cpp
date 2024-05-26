#include <iostream>

using namespace std;

// 풀이.
// 조금 어이가 없다. 어제 어렵게 풀었던 골5문제는 45퍼였는데 오늘 꽤나 쉽게 푼 골4 문제는 36퍼짜리다.
// 가끔 이렇게 쉬운걸 어렵게 풀고 어려울걸 쉽게 풀때가 있는데 흠... 답은 늘 정진하는것 뿐이다.
// 이 문제는 딱히 그리디한 풀이 수단이 안보였다. 가장 적은 비용으로 가장 많은 홍보 방법을 많이 쓰는것 뿐이었는데
// 예를 들어 10명을 홍보해야할때 3, 5가 가장 가성비 좋은 홍보방법일때 이것을 4번 사용하는것보다 3번 사용하고
// 나머지 1명을 값싼 홍보방법을 사용하여 홍보하는것이 결과적으로 싼데 이러한 방법을 구하기가 애매했다.
// 따라서 dp와 배낭 문제 풀이를 사용하기로 했다. 처음 C명이 있을때 모든 방법을 한번씩 사용하여 인원을 줄여나가보는 것이다.
// 그중 최소값을 찾아내어 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

// P.S 그래도 이겨냈다. 뿌듯하다.

pair<int, int> board[20];
int dp[1001]; // dp[1001] = {-1, }로 초기화해보려 했으나 되지 않았다. 아마 0이나 false만 되는것 같다.
int C, N;

// dp와 배낭 문제 풀이를 이용하여 최소값을 구하는 함수.
int CalMin(int num)
{
    // 모든 인원을 이미 찾았다면 더이상 구할 필요가 없기에 0원을 반환한다.
    if (num <= 0)
        return 0;

    int& ans = dp[num];
    // 이미 num명의 최소값을 구했다면 반복하지 않고 dp값을 반환한다.
    if (ans != -1)
        return ans;
    ans = 987654321;

    // 모든 홍보방법들을 이용하여 인원수를 줄여나가본다. 그 비용들의 최소값을 반환한다.
    for (int i = 0; i < N; ++i)
        ans = min(ans, board[i].first + CalMin(num - board[i].second));

    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i <= C; ++i)
        dp[i] = -1;
    cout << CalMin(C) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> C >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}