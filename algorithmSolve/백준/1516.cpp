#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<int> times, links;
int N;

void BFS()
{
    queue<int> que;
    vector<int> answer(N, 0);
    for (int i = 0; i < N; ++i)
        if (links[i] == 0)
        {
            answer[i] = times[i];
            que.push(i);
        }
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i];
            --links[there];
            answer[there] = max(answer[there], answer[here] + times[there]);
            if (links[there] == 0)
                que.push(there);
        }
    }
    for (auto& i : answer)
        cout << i << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    links.resize(N, 0);
    board.resize(N, vector<int>());
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        times.push_back(t);
        while (true)
        {
            int l;
            cin >> l;
            if (l == -1)
                break;
            board[l - 1].push_back(i);
            ++links[i];
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}