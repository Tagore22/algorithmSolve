#include <iostream>

using namespace std;

// 풀이.
// 최소 스패닝 트리이다. 다만 크루스칼은 익숙하지 않아서 프림으로 풀었다. 하나 굉장히 화가 났다.
// 다풀었는데 정말 사소한곳에서 하나 삐끗난것이다. 한 몇시간 헤맨것 같다. 그래도 큰틀은 틀리지 않았다는건
// 다소 위안이 되지만, 흘러 버린 시간은 승질만 나게 할 뿐이었다.

// 어쨌든 풀이를 달자면 기본적인 프림과는 달랐다. 기본적인 프림은 최소 스패닝 트리 자체가 어디서 시작하든
// 결과값이 같기 때문에 0번째 정점에서 시작하면 되지만 이 경우에는 시작점이 따로 존재했다. 그것에 유의해야한다.

// 자세한 설명은 주석으로 남긴다.

int N, M, K, sum = 0, answer = 0;
bool connect[1001] = { false, };
int path[1001][1001], len[1001];

void MakeAnswer()
{
    // 시작점이 따로 존재하기에 구해야 한다. 최초에 발전기로부터 연결되어 있는 정점들을 찾으면서
    // 간선의 길이를 수정해나간다.
    
    // 모든 최소 길이는 최대값으로 초기화한다.
    for (int i = 1; i <= N; ++i)
        len[i] = 10001;
    // 모든 정점들을 순회하면서 발전소와 연결된 정점이 존재할때 그와 연결된 정점들의 최소 길이를
    // 수정해나간다.
    for (int i = 1; i <= N; ++i)
    {
        if (connect[i])
        {
            for (int j = 1; j <= N; ++j)
                len[j] = min(len[j], path[i][j]);
        }
    }
    while (sum < N)
    {
        int dis = 10001, next;
        for (int i = 1; i <= N; ++i)
        {
            // 아직 고르지 않은 정점들중 최소길이가 가장 짧은 정점을 선택한다. 여기서 상술한 실수가 발생했다.
            if (!connect[i] && len[i] < dis)
            {
                next = i;
                dis = len[i]; // 바로 이부분인데 dis가 수정되지 않아서 가장 짧은 정점이 선택되는 것이 아니라
                              // dis보다 최소길이가 짧은 정점들중 가장 맨 뒤 정점이 골라졌다. T^T
            }
        }
        // 정점이 골라졌음을 수정하고 answer과 sum값을 추가한다.
        connect[next] = true;
        answer += len[next];
        ++sum;
        // 현재 골라진 정점 next를 순회하며 연결된 정점들의 최소길이를 다시 수정한다.
        for (int i = 1; i <= N; ++i)
        {
            if (!connect[i] && len[i] > path[next][i])
                len[i] = path[next][i];
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            path[i][j] = 10001;
    int pos;
    for (int i = 0; i < K; ++i)
    {
        cin >> pos;
        connect[pos] = true;
    }
    sum = K;
    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        path[from][to] = cost;
        path[to][from] = cost;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}