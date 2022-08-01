#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> board;
int N, M, W;
const int MAXNUM = 987654321;

void BF()
{
    vector<int> len(N + 1, 0);
    len[1] = 0;
    for (int iter = 0; iter < N - 1; ++iter)
        for (int here = 1; here <= N; ++here)
            for (int i = 0; i < board[here].size(); ++i)
            {
                int there = board[here][i].first;
                int cost = board[here][i].second;
                if (len[here] != MAXNUM)
                    len[there] = min(len[there], len[here] + cost);
            }
    for (int here = 1; here <= N; ++here)
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int cost = board[here][i].second;
            if (len[here] != MAXNUM && len[there] > len[here] + cost)
            {
                cout << "YES" << '\n';
                return;
            }
        }
    cout << "NO" << '\n';
}

void MakeAnswer() //도로는 양방향, 웜홀은 방향
{
    BF();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    board.clear();
    cin >> N >> M >> W;
    board.resize(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i < W; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, -c));
    }
}

int main()
{
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; ++i)
    {
        Input();
        MakeAnswer();
    }
    return 0;
}