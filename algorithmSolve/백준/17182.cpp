#include <iostream>

using namespace std;

// 풀이.
// 어떠한 정점을 중복해서 방문할수가 있다. 라는 한문장이 헤매게 만든 문제였다. 프림이나 플로이드 알고리즘을
// 이용하는 문제인거 같았는데 프림은 중복으로 방문을 하지 않기에 플로이드 같았다. 그러나 그 뒤가 잠깐 떠오르질 않았다.
// 정답은 어차피 중복 방문은 플로이드 알고리즘에 의해 이미 해결된 상태이기 때문에 그 뒤로는 백트래킹을 이용하여 모든
// 경로를 확인하여 최소값을 출력만 하면 되는 것이었다.

// 자세한 설명은 주석으로 남긴다.

int board[10][10];
bool check[10] = { false, };
int N, K, answer = 987654321;

// 플로이드 알고리즘. i에서 j로의 최소 거리를 구한다.
void Floyd()
{
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

// 모든 이동 경로를 확인해보는 함수.
int BackTrack(int idx, int num)
{
    // N개의 정점을 모두 방문했다면 0을 반환한다.
    // 기저사례.
    if (num == N)
        return 0;

    int ans = 987654321;
    // 모든 정점들을 순회한다.
    for (int i = 0; i < N; ++i)
    {
        // 이미 방문했거나 idx -> idx로의 이동은 무시한다.
        if (check[i] || i == idx)
            continue;
        check[i] = true;
        ans = min(ans, BackTrack(i, num + 1) + board[idx][i]);
        check[i] = false;
    }
    // 여기를 까먹어서 한 2분 헤맸다.
    return ans;
}

void MakeAnswer()
{
    Floyd();
    check[K] = true;
    cout << BackTrack(K, 1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}