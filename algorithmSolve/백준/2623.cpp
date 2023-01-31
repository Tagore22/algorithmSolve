#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//원소들간의 순서가 중요한 위상정렬 문제이다.
//각 원소별로 현재 원소가 묶여있는(앞서 있는 수들의 개수)수를 저장하는 link를 계산한다.
//또한, 동시에 자기 자신 뒤에오는 수들의 목록을 2차원 배열 seq에 저장한다.
//그 후, BFS를 순회하며 link[K]가 0인 수들을 answer에 담아내면 되는데, 담아내기전 현재 원소 K뒤에 있는 모든 수들의 묶여있는 수들이 1씩 
//줄어듬을 잊으면 안된다. 

//처음에 풀때에는 답을 구할수 없는 경우가 2,3 3,2 같은 경우밖에 없는줄 알고 seq[board[i][j]]가 board[i][iter]를 가지고 있을 경우만
//0을 출력했으나, 그렇지 않고 1,2 2,3 3,1 같은 경우도 데드락이 되어 답을 구할수 없었다.
//이 모든 상태를 모두 알수 있는 최종적인 방법은 BFS에서 link[K]가 0인 값들을 최종답 answer에 담아두되, que의 순회가 끝났을때
//answer의 개수를 확인하는 것이다. N이 아니라면 결국 답을 구할수 없었으므로 0을 출력하면 된다.

vector<vector<int>> board, seq;
vector<int> link;
int N, M;

void MakeSeq()
{
    seq.resize(N + 1, vector<int>());
    link.resize(N + 1, 0);

    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i].size() >= 2)
            for (int j = 1; j < board[i].size(); ++j)
                for (int iter = 0; iter < j; ++iter)
                {
                    seq[board[i][iter]].push_back(board[i][j]);
                    ++link[board[i][j]];
                }
    }
}

void BFS()
{
    queue<int> que;
    vector<int> answer;

    for (int i = 1; i <= N; ++i)
        if (link[i] == 0)
            que.push(i);

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = 0; i < seq[here].size(); ++i)
        {
            int there = seq[here][i];
            --link[there];
            if (link[there] == 0)
                que.push(there);
        }
        answer.push_back(here);
    }
    if (answer.size() != N)
        cout << 0 << '\n';
    else
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << '\n';
}

void MakeAnswer()
{
    MakeSeq();
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(M, vector<int>());

    int t, num;
    for (int i = 0; i < M; ++i)
    {
        cin >> t;
        for (int j = 0; j < t; ++j)
        {
            cin >> num;
            board[i].push_back(num);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}