#include <iostream>

using namespace std;

// 풀이.
// 더워서 머리가 안돌아가는지 전혀 어려운 문제가 아닌데 헤맨 문제다.
// 우선 dp를 사용할때 scv의 체력이 0보다 작아져 파괴되었을때를 상정하지 못했는데 매우 간단했다.
// 그냥 0보다 작으면 0으로 치면 되었다. 그 이외에도 scv의 수에 따라 공격받는 대미지라던가 이런거를 따로
// 계산했는데 지금 생각해보면 그럴 필요가 없다. 예를 들어 아래 att를 보면 scv가 2개일때 9, 3이 아니라
// 9, 1으로 공격받을수도 있는데 이럴 경우는 없다. 하지만 상관없다. 왜냐하면 9, 3도 존재하기 때문이다.
// 당연히 9, 1보다 9, 3이 더 많은 공격을 하기에 더 빨리 파괴할수 있다. 또한 scv의 수가 무조건 3이 아니기에
// dp를 구현하기 애매하다 생각했는데 이것도 예를 들어 N이 2라서 3번째 scv가 없다면 그냥 체력을 0으로 하여
// 늘 성공해 있는 상태로 두면 된다. 내 몇안되는 안좋은 단점인 너무 어렵게 생각했던것 같다. 좀더 침착해보자.
// 아니 근데 너무 덥잖아. 할맘이 안생긴다고;

// 자세한 설명은 주석으로 남긴다.
// P.S 문제에 힌트에는 BFS가 나와 있으나 아래 풀이도 그러하듯 굳이 그러지 않아도 된다. 결과적으로 그리디하게 풀수 없기에
// 모든 결과를 순회하며 dp를 사용하여 중복되는 결과들을 지우기만 해주면 된다.

int scv[3];
int att[6][3] = { {1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1} };
int dp[61][61][61];
int N;

// 모든 경우를 다 계산해보는 함수.
int BackTrack(int a, int b, int c)
{
    // 모든 scv가 파괴되었다면 0을 반환한다. 
    if (a <= 0 && b <= 0 && c <= 0)
        return 0;

    int& ans = dp[a][b][c];
    if (ans != -1)
        return ans;

    ans = 987654321;
    // 모든 공격 방법 6가지를 총동원한다.
    for (int i = 0; i < 6; ++i)
    {
        int na = a - att[i][0] < 0 ? 0 : a - att[i][0];
        int nb = b - att[i][1] < 0 ? 0 : b - att[i][1];
        int nc = c - att[i][2] < 0 ? 0 : c - att[i][2];
        ans = min(ans, BackTrack(na, nb, nc) + 1);
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < 61; ++i)
        for (int j = 0; j < 61; ++j)
            for (int k = 0; k < 61; ++k)
                dp[i][j][k] = -1;
    cout << BackTrack(scv[0], scv[1], scv[2]) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> scv[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}