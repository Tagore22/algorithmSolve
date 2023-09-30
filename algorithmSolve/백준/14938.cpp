#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 어려운 문제도 아닌데 잘못 생각해서 2번이나 헤맨 문제다.
// 처음에는 낙하지점에서 이동할것 없이 이동 가능한 지점의 아이템들을 더하려고 했으나,
// 다음 지점으로 이동하여 먹을수 있음에도 불구하고 문제를 잘못 읽어서 넘겨서 틀렸고
// 두번째는 DFS를 이용했기 때문에 한번 도착한 지점을 더 빠르게 도착할수 있을때를 무시해서 틀렸다.
// 결과적으로는 플로이드 와셜이나 다익스트라를 이용해서 어떤 지점을 최소한의 길이로 이동하였을때
// 도착할수 있다면 그 지점의 아이템을 획득할수 있는 것으로 여겨 이 아이템들의 개수를 모두 더하여 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> way;
int item[101];
int N, M, R, answer = 0;

// 플로이드 와셜 함수.
void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                // i에서 j로의 기존 길이를 k를 거쳐 이동하는 경우와 비교하여 갱신함.
                way[i][j] = min(way[i][j], way[i][k] + way[k][j]);
}

void MakeAnswer()
{
    Floyd();

    // 1 ~ N번 지점을 모두 순회하여 가장 많은 아이템수를 찾는다.
    for (int i = 1; i <= N; ++i)
    {
        int ans = 0;
        // 1 ~ N번까지 최소한의 길이로 이동하였을때 수색범위 내에 지점의 아이템수를 모두 더한다.
        for (int j = 1; j <= N; ++j)
            if (way[i][j] <= M)
                ans += item[j];

        answer = max(answer, ans);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    // 획득 범위가 최대 15이기 때문에 그 이상인 16으로 초기화하면 된다.
    for (int i = 1; i <= N; ++i)
        cin >> item[i];
    way.resize(N + 1, vector<int>(N + 1, 16));
    // i에서 i로 이동은 가능하나 이러한 경우가 주어지지 않기에 직접 초기화해야한다.
    for (int i = 1; i <= N; ++i)
        way[i][i] = 0;
    int from, to, len;
    for (int i = 0; i < R; ++i)
    {
        cin >> from >> to >> len;
        // 양방향으로 이동이 가능함을 문제에서 제시했음.
        way[from][to] = len;
        way[to][from] = len;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}