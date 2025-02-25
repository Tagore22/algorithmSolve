#include <iostream>

using namespace std;

// 풀이.
// 처음에는 약간 그리디한 방식으로 풀려고 했었다. 하지만 그리디는 늘 예상을 벗어났고
// 다른 방법을 찾다가 MST를 보았다. 적응하는 방식이 꽤나 까다롭다고 생각했었으나 조금씩
// 깊이 생각해보면 오히려 어려울게 없었다. 
// 
// 자세한 설명은 주석으로 남긴다.

// 처음에는 board라는 이름으로 우물을 파는 가격들을 저장해두려고 했으나 사실상 프림 알고리즘에서 사용하는
// 최소값들과 동일했다. 따라서 최소값으로 아예 바꾸어버렸다.
int dist[300], cost[300][300];
int N, answer = 0;

// MST의 최소값을 구하는 프림 알고리즘.
void Prim()
{
    // 여기에 원래라면 모든 정점의 최소길이 dist가 초기화되어야 한다.
    // 하지만 애시당초 물을 끌어오느냐 우물을 파느냐에서 더 적은 가격을 골라야 한다.
    // 따라서 초기화 가격을 이미 입력으로 주어진 우물을 파는 가격으로 대체해도 상관없다.
    bool visit[300] = { false, };

    // N개의 정점들을 고른다.
    for (int iter = 0; iter < N; ++iter)
    {
        int u = -1;
        // 매번 N개의 정점들중 고르지 않았으며 가장 최소길이가 짧은 정점을 고른다.
        for (int i = 0; i < N; ++i)
            if (!visit[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        // 최종값 answer에 길이를 더해주고 방문 여부를 갱신한다.
        answer += dist[u];
        visit[u] = true;

        // 현재 정점 u에서 도달할수 있는 정점(이 문제에서는 모든 정점이 연결되어 있다.)을
        // 순회하며 아직 방문하지 않은 정점들의 최소 길이를 갱신한다.
        for (int i = 0; i < N; ++i)
            if (!visit[i] && dist[i] > cost[u][i])
                dist[i] = cost[u][i];
    }
}

void MakeAnswer()
{
    Prim();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int cur;
    for (int i = 0; i < N; ++i)
        cin >> dist[i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> cost[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}