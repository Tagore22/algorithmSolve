#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 몇가지 실수를 해서 푸는데 한참 걸렸다. 복기를 제대로 하자.
// 아래 풀이를 요약하자면 다음과 같다.

// 1. 벨만-포드 알고리즘을 사용해서 1번 정점에서 각 정점까지의 가중치를 N번 완화해나간다.
// 2. 벨만-포드 알고리즘에 의거하여 마지막 N번까지도 완화가 일어났다면 음수 사이클이 존재하는 것이고
// 이때 N번 정점에서도 완화가 일어났다면 목적지에 음수 사이클이 존재하기에 제대로 된 값을 구할수 없어
// -1을 출력해야한다.
// 3. 함수 호출 이후의 경우는 다음과 같다.
// 3-1. 목적지까지 도달할수가 없는 경우. -1을 출력.
// 3-2. 목적지까지 도달은 가능하나 음수 사이클이 있는 경우. -1을 출력
// 3-3. 목적지까지 도달이 가능하면서 음수 사이클이 없는 경우. 

// 각 경우에 따라 값을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[101];
int p[101], dist[101];
int N, M;
const int MAXNUM = 987654321;

// 벨만-포드 알고리즘을 구현하는 함수.
void BF()
{
    for (int i = 1; i <= N; ++i)
        dist[i] = MAXNUM;
    dist[1] = 0;

    // N번의 완화과정을 거친다. 만약 마지막 N번째에도 완화가 일어난다면
    // 음수 사이클이 존재함을 의미한다.
    for (int iter = 0; iter < N; ++iter)
    {
        // 1번부터 N번 정점까지 모두 순회한다.
        for (int here = 1; here <= N; ++here)
        {
            // 각 정점에서 도달할수 있는 모든 정점을 순회한다.
            for (int next = 0; next < board[here].size(); ++next)
            {
                int there = board[here][next].first;
                int cost = board[here][next].second;

                // 완화가 가능하다면 거리값을 갱신하고 배열 p에 부모값을 저장한다.
                if (dist[there] > dist[here] + cost)
                {
                    dist[there] = dist[here] + cost;
                    p[there] = here;
                    // 마지막 N번째에서 목적지의 음수 사이클이 발견되면 체크해놓는다.
                    if (iter == N - 1)
                        dist[there] = -MAXNUM;
                }
            }
        }
    }
}

void MakeAnswer()
{
    BF();

    // 목적지까지 도달할수 없거나, 목적지에 음수 사이클이 존재한다면 -1을 출력한다.
    if (dist[N] == MAXNUM || dist[N] == -MAXNUM)
    {
        cout << -1 << '\n';
        return;
    }
    // 부모값 p를 역순회하며 경로를 찾아 출력한다.
    int cur = N;
    vector<int> answer;
    while (cur != 0)
    {
        answer.push_back(cur);
        cur = p[cur];
    }
    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, -cost));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}