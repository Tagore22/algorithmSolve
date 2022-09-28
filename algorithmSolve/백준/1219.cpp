#include <iostream>
#include <vector>


//기존에 알고스팟에서 풀었던 TimeTrip과 매우 유사한 문제이다. 최단거리를 구하되, 목적지에 음수사이클이 존재하거나, 혹은
//목적지까지 아예 도달하지도 못하는가를 구분해야한다. 51%에서 틀려서 뭐가 틀렸나 한참을 봤는데 각 정점들의 최단거리의 
//타입이 잘못되었었다(BF함수의 board). BF함수에서 시간복잡도는 V의 절대값 * E의 절대값이기에 모든 정점마다 연결된 경우에는 한 정점에서의 
// 최단거리를 갱신할때마다 모든 정점의 최단거리가 갱신된다. 즉, 매번 100만씩 줄어들며 50 * 50 * 1,000,000이 되어 -25억이 되어 int값을 
// 뛰어넘기에 long long으로 해야한다.

using namespace std; //양방향이 아니다

vector<vector<pair<int, int>>> path;
vector<vector<bool>> Cango;
vector<int> money;
int N, from, to, M;
const long long MAXNUM = 1LL << 62;

void CalCango()
{
    for (int i = 0; i < N; ++i)
        Cango[i][i] = true;
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                Cango[i][j] = Cango[i][j] || (Cango[i][k] && Cango[k][j]);
}

void BF()
{
    vector<long long> board(N, MAXNUM);
    board[from] = -money[from];
    for (int iter = 0; iter < N - 1; ++iter) // == 2 * (1+2) == 2 * 1 + 2 * 2 >>> 뒤에 1,2는 각 정점의 간선들. 총 간선은 3개. 정점은 2개
        for (int here = 0; here < N; ++here)
            for (int i = 0; i < path[here].size(); ++i) //모든 정점이 연결되어있는 경우엔 매순간 board[i]값이 최대 100만만큼 감소함.
            {
                int there = path[here][i].first;
                int cost = path[here][i].second - money[there];

                board[there] = min(board[there], board[here] + cost);
            }
    for (int here = 0; here < N; ++here)
        for (int i = 0; i < path[here].size(); ++i)
        {
            int there = path[here][i].first;
            int cost = path[here][i].second - money[there];

            if (board[there] > board[here] + cost && (Cango[from][here] && Cango[here][to])) //음수 사이클이 존재할경우.
            {
                cout << "Gee" << '\n';
                return;
            }
        }
    cout << -board[to] << '\n';
}

void MakeAnswer()
{
    CalCango();
    if (!Cango[from][to])
    {
        cout << "gg" << '\n';
        return;
    }
    BF();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> from >> to >> M;
    path.resize(N, vector<pair<int, int>>());
    Cango.resize(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        path[a].push_back(make_pair(b, c));
        Cango[a][b] = true;
    }
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        money.push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}