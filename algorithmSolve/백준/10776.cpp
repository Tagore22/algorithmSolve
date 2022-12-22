#include <iostream>
#include <vector>
#include <queue>

using namespace std; //양방향 그래프다.

//오랜만에 다익스트라를 비롯한 그래프 문제이다. 기본 다익스트라에서 크게 벗어나진 않았으나, 뗏목의 체력이라는 변수가 생각보다 골치아팠다.
//지금 다시 생각해보면 다익스트라를 좀더 깊기 이해하게 되는 좋은 문제인것 같다.

//풀이
//기본틀은 다익스트라 풀이와 크게 차이는 없으나, 상술하였듯이 뗏목의 체력이 중요한 변수가 되었다.
//기본적으로 최소 시간값을 구해야 하기에 dist에 최소값을 갱신해가며 큐를 순회하지만 잘 생각해보면 뗏목의 체력때문에 갈수 있고 없는
//경우의 수가 생긴다. 그렇기에 dist는 단순히 정점만을 인덱스로 가지지 않고, 뗏목의 체력 역시 가지게 되는 2차배열이 되어야 한다.
//정리하자면 똑같은 시간이 걸려 똑같은 정점에 도달하였으나, 그 상황의 체력 역시 구분해야한다는 것이다.
//대미지가 현 뗏목의 체력보다 적고, dist[there][health - damage]인 경우 즉, 똑같은 정점을 똑같은 체력으로 
//도달한 경우보다 시간이 덜 걸릴때 우선순위 큐에 포함하는 식으로 큐를 순회하여 dist[to - 1]의 모든 원소(0부터 K까지의)를 다시 순회하여
//최소값으 출력하되, 아예 도착점까지 도달하지 못하여 모든 값이 MAX_NUM일때에는 -1을 출력한다.


vector<vector<pair<int, pair<int, int>>>> board; //도착점, 시간, 체력
int K, N, M, from, to;
const int MAX_NUM = 987654321;

void DK()
{
    vector<vector<int>> dist(N, vector<int>(K + 1, MAX_NUM));
    dist[from - 1][K] = 0;
    priority_queue<pair<int, pair<int, int>>> que; //시간, 정점, 체력
    que.push(make_pair(0, make_pair(from - 1, K)));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second.first;
        int health = que.top().second.second;
        que.pop();

        if (dist[here][health] < cost)
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int time = board[here][i].second.first;
            int damage = board[here][i].second.second;

            if (health > damage && cost + time < dist[there][health - damage])
            {
                dist[there][health - damage] = cost + time;
                que.push(make_pair(-dist[there][health - damage], make_pair(there, health - damage)));
            }
        }
    }

    int answer = MAX_NUM;
    for (int i = 0; i <= K; ++i)
        answer = min(answer, dist[to - 1][i]);

    if (answer != MAX_NUM)
        cout << answer << '\n';
    else
        cout << -1 << '\n';
}

void MakeAnswer()
{
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> N >> M;
    board.resize(N, vector<pair<int, pair<int, int>>>());
    int a, b, time, damage;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> time >> damage;
        board[a - 1].push_back(make_pair(b - 1, make_pair(time, damage)));
        board[b - 1].push_back(make_pair(a - 1, make_pair(time, damage)));
    }
    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}