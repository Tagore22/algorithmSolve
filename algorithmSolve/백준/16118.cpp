#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 무시무시한 문제였다. 골1에 정답율이 20퍼도 안되는 문제였는데 알고보니 서울대 경시대회 문제였다.
// 언뜻 보면 간단한 다익스트라 알고리즘 같으나, 늑대에서 복잡해진다. 속도가 2배로 증가할수도
// 감소할수도 있기 때문이다. 특히나 감소할때 기존의 가중치가 홀수라면 값이 이상해지기 때문에
// 모든 가중치를 2배로 곱하여 시작했다. 여우는 상술한대로 평범한 다익스트라로 풀면 되지만
// 늑대는 속도가 증감이 있기 때문에 2차원 배열을 사용해야한다. i번째 정점에 홀수번째로 도달했을때와
// 짝수번째로 도달했을 경우가 다르기 때문이다. 또한, 우선순위큐에서 -를 이용하여 맨위로 올리는걸 깜빡했는데
// 당연하게도 시간초과가 났다. 기존이라면 버려야할 값들을 모두 검사하기 때문이다. 주의하자.

// 자세한 설명은 주석으로 남긴다.

const int MAXNUM = 2100000000;
int N, M;
vector<pair<int, int>> board[4001];
// 각각 여우와 늑대의 각 정점으로의 최단거리.
vector<int> FoxDist, WolfDist;

// 여우의 각 정점까지 최단거리를 구하는 함수.
// 평범한 다익스트라와 다를게 없다.
void DKFox()
{
    for (int i = 0; i <= N; ++i)
        FoxDist.push_back(MAXNUM);
    FoxDist[1] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > FoxDist[here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int next = cost + p.second;
            if (next < FoxDist[there])
            {
                FoxDist[there] = next;
                que.push(make_pair(-next, there));
            }
        }
    }
}

// 늑대의 각 정점까지 최단거리를 구하는 함수.
void DKWolf()
{
    // 홀수번째로 도달할때와 짝수번째로 도달할때가 다르기 때문에
    // 2차원 배열을 사용한다.
    int odd[2][4001];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j <= N; ++j)
            odd[i][j] = MAXNUM;
    // 이부분이 매우 중요한데 처음에는 별생각 없이 odd[0][1] = odd[1][1] = 0을 했었다.
    // 하지만 그러면 안되는게 int 변수 isodd의 원래값을 출발하는 홀수 혹은 짝수이고
    // (isodd + 1) % 2는 도착했을때의 값을 나타내기 때문이다. 최초에 isodd가 1로 시작하기에 
    // 0으로 도착하는 경우는 0에서 0이므로 0이지만, 1에서 어딘가로의 가중치는 절대로 0이 될수 없기 때문이다.
    odd[0][1] = 0;
    priority_queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(0, 1), 1));

    while (!que.empty())
    {
        // 상술한대로 우선순위큐를 사용할때 값을 -로 반전하는것을 잊지말자.
        int cost = -que.top().first.first;
        int here = que.top().first.second;
        int isodd = que.top().second;
        que.pop();

        if (cost > odd[(isodd + 1) % 2][here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int dis = isodd == 1 ? p.second / 2 : p.second * 2;
            int next = cost + dis;
            if (next < odd[isodd][there])
            {
                odd[isodd][there] = next;
                que.push(make_pair(make_pair(-next, there), (isodd + 1) % 2));
            }
        }
    }
    WolfDist.push_back(0);
    // 홀수번째와 짝수번째값들을 비교하여 최소값을 벡터에 넣는다.
    for (int i = 1; i <= N; ++i)
    {
        int low = min(odd[0][i], odd[1][i]);
        WolfDist.push_back(low);
    }
}

void MakeAnswer()
{
    DKFox();
    DKWolf();
    int answer = 0;
    // 늑대와 여우의 값들 비교하여 여우가 더 짧을때 최종값 answer는 1 증가한다.
    for (int i = 1; i <= N; ++i)
        if (FoxDist[i] < WolfDist[i])
            ++answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost * 2));
        board[to].push_back(make_pair(from, cost * 2));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}