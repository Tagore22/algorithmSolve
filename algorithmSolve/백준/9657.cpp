#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 게임이론의 종만북식 풀이. 비트 연산등 귀찮은것이 많아서
// 다른 풀이가 더 가독성이 좋은것 같다. 다만 이방식도 반드시 알아야하기에
// 잘 푼것같다.

// 자세한 설명은 주석으로 남긴다.

int dp[1001];
int N;

int DFS(int num)
{
    // 더이상 집을 돌이 없다면 반드시 패배한다.
    if (num == 0)
        return 0;

    int& ans = dp[num];
    if (ans != -1)
        return ans;

    // 초기화는 패배로.
    ans = 0;
    // 0이 아니라면 반드시 1개 이상이므로 if문이 필요없다.
    // 1개를 가져갔을때의 결과를 반전하여 ans와 비교한다.
    ans |= DFS(num - 1) ^ 1;
    // 현재 돌이 3개 이상일때 비교.
    if (num >= 3)
        ans |= DFS(num - 3) ^ 1;
    // 현재 돌이 4개 이상일때 비교.
    if (num >= 4)
        ans |= DFS(num - 4) ^ 1;

    return ans;
}

int main()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));
    int answer = DFS(N);
    if (answer == 1)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
    return 0;
}