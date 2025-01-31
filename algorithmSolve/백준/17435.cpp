#include <iostream>

using namespace std;

// 풀이.
// 희한하게 정답율이 높아서 보니 희소 배열 문제였다. 난이도가 꽤나 높은 문제들중 이러한 종류가 상당히
// 존재하는데 어려운 개념을 알기만 하면 적용하기 어렵지 않은 문제들이 그러하다.
// 희소 배열은 모든 정점들이 각각 도달하는 정점이 한개인 경우에 사용할수 있다. 
// https://velog.io/@dlwogns/Sparse-Table%ED%9D%AC%EC%86%8C-%EB%B0%B0%EC%97%B4 을 참조하였는데
// K + 8번 이동한 정점은 K + 4에서 4번 이동한 정점과 같고, K + 4번 이동한 정점은 K + 2에서 2번 이동한
// 정점과 같다. 이것을 이용하여 실제 이동수가 아닌 실제 이동한 수의 로그값을 dp에 적용할수 있다.
// 즉, dp값은 다음과 같은 점화식을 띈다.
// board[i][N] = board[i - 1][board[i - 1][N]];
// 또한, 희소 배열은 비트마스크와 세트인데 상술한대로 이동할수 있는 정점이 한군데이기 때문이다.
// 예를 들어 11번 이동한다고 치면 이진수로 치환하여 1011, 즉 8번, 2번, 1번 이동하는 경우가 되며
// 상술한대로 이것을 2의 배수로 치환하여 3, 1, 0번 이동시킨 결과값을 출력하면 된다.
// 생소한 개념이나 어렵지 않으니 잘 기억해두자.

// 1. 방향이 하나이기에 어디서 시작하든 결과값은 같아진다.
// 2. 로그값을 dp에 적용하여 연산량을 줄인다.
// 4. 비트마스킹을 이용하여 결과값을 적용한다.

// 자세한 설명은 주석으로 남긴다.

int board[19][200001];
int M, Q, N, X;

void MakeAnswer()
{
    // 미리 모든 이동값들을 구해놓는다.
    for (int i = 1; i < 19; ++i)
        for (int j = 1; j <= M; ++j)
            board[i][j] = board[i - 1][board[i - 1][j]]; // 상술한 점화식.

    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> N >> X;
        for (int i = 19; i >= 0; --i) // 이진수와 비트마스킹을 이용하여 이동한 거리들을 구한다.
        {
            if ((1 << i) & N)
                X = board[i][X];
        }
        cout << X << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    for (int i = 1; i <= M; ++i)
        cin >> board[0][i];
    cin >> Q;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}