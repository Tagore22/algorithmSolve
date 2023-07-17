#include <iostream>

using namespace std;

// 풀이.
// 바로 어제 풀었던 문제와 거의 똑같은 문제가 나와서 당황했다.
// 키가 큰 순서의 그래프와 키가 작은 순서의 그래프로 나누어
// 각각 플로이드 와셜 순회를 한 후에
// 모든 원소들을 다시 순회하며 키가 큰 그래프 혹은 키가 작은 그래프에서
// 다른 모든 원소에 접근할수 있다면 비교가 가능하다.

// 키가 큰 그래프와 작은 그래프로 나누는 이유는 자세히 보면 당연한 일이다.
// 키가 작을때의 이동과 클때의 이동이 서로 영향을 주어 크고 작음에 영향을 준다면
// 제대로 비교를 할수 없기 때문이다.

// DFS풀이가 있는것 같은데 그게 더 빠른것 같다.
// 플로이드 와셜 순회부분에서 500의 3제곱 즉 1억이 넘는 순회를 해야하기 때문이다.
// DFS에서는 그 순회가 없기에 훨씬 더 빠른것 같다.

// 자세한 설명은 주석으로 남긴다.

bool T[501][501], S[501][501];
int N, M;

void Floyd()
{
    // 나에서 나에 대한 방문은 언제나 가능하다.
    for (int i = 1; i <= N; ++i)
    {
        S[i][i] = true;
        T[i][i] = true;
    }

    // 플로이드 와셜 알고리즘. 기존에 접근 가능하였거나 다른 길을 통하여 접근이 가능하다면
    // 결국 접근 가능하다.
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                T[i][j] |= T[i][k] & T[k][j];
                S[i][j] |= S[i][k] & S[k][j];
            }
}

void MakeAnswer()
{
    Floyd();
    int answer = 0;
    bool isfind;

    // 위 상술하였던 대로 모든 원소들을 순회한다.
    for (int i = 1; i <= N; ++i)
    {
        isfind = true;
        // 다른 모든 원소들을 순회하되 키가 클때의 그래프와 작을때의 그래프가
        // 모두 접근이 불가능한 원소가 있다면 모든 원소들과의 비교가 불가능하므로
        // 현재 원소는 최종답에 포함되지 않는다.
        for (int j = 1; j <= N; ++j)
        {
            if (!S[i][j] && !T[i][j])
            {
                isfind = false;
                break;
            }
        }

        answer = isfind ? answer + 1 : answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        S[from][to] = true;
        T[to][from] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}